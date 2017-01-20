#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main (int argc, char* argv[])
{
    //check for proper usage
    if (argc != 3)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    
    //remeber file names
    char* infile = argv[1];
    char* outfile = argv[2];
    
    //open input file
    FILE* inpt = fopen(infile, "r");
    if (inpt == NULL)
    {
        printf("could not open %s \n", infile);
        return 2;
    }
    
    //open output file
    FILE* outpt = fopen(outfile, "w");
    if (outpt == NULL)
    {
        fclose(inpt);
        fprintf(stderr, "could not create %s \n", outfile);
        return 3;
    }
    
    //read infile BITMAPFILEHEADER 
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inpt);
    
    //read infile BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inpt);
    
    if(bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outpt);
        fclose(inpt);
        fprintf(stderr, "File format is not supported \n");
        return 4;
    }
    
    //write outfile BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outpt);
    
    //write outfile BITMAPINFOHEADER
    fwrite(&bf, sizeof(BITMAPINFOHEADER), 1, outpt);
    
    //determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) %4) %4;
    
    //iterate over infile scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //iterate over pixels in scanlines
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE triple;
            
            //read rgb triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inpt);
            
            //create a white construct
            RGBTRIPLE white;
            white.rgbtRed = 0xff;
            white.rgbtGreen = 0xff;
            white.rgbtBlue = 0xff;
            
            //replace red pixels with white
            if (triple.rgbtRed == 0xff && triple.rgbtGreen == 0x00 && triple.rgbtBlue == 0x00)
            {
                triple = white;
            }
            //write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outpt);
        }
        //if any padding, skip over it
        fseek(inpt, padding, SEEK_CUR);
        
        //if any padding, add it back
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outpt);
        }
    }
    //close infile
    fclose(inpt);
    
    //close outfile
    fclose(outpt);
    
    return 0;
}
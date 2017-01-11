/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int array[], int n)
{
    int beginning = 0;
    int ending = n - 1;
    int mid = (beginning + ending) / 2;
    
    while (beginning <= ending)
    {
        if (array[mid] == value)
            return true;
        else if (value < array[mid])
        {
            ending = mid - 1;
            mid = (beginning + ending) / 2;
        }
        else if (value > array[mid])
        {
            beginning = mid + 1;
            mid = (beginning + ending) / 2;
        }
        else
            break;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int middle, end;
    for (end = 0; end < n - 1; end++)
    {
        int check = 0;
        for (middle = end; middle < n; middle++)
        {
            if (values[middle] < values[end])
            {
                int temp = values[middle];
                values[middle] = values[end];
                values[end] = temp;
                check = 1;
            }
        }
        if (check == 0)
            break;
    }
    for (int i = 0; i < n; i++)
        printf ("%d\n", values[i]);
        return;
}
/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Contains function definitons for
 * for statistics analysis
 *
 * This source file includes function definitions
 * that calculate the following statistics:
 *	- Minimum
 *	- Maximum
 *	- Mean
 *	- Median
 *
 * @author Ahmed Hessein
 * @date December 15, 2018
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  sort_array(test, SIZE);
  print_array(test, SIZE);
  print_statistics(test, SIZE);

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char * ptr, unsigned char size)
{
  printf("\nStatistics of the data set");
  printf("\n--------------------------------\n");
  printf("Maximum element in the data set = %d\n", find_maximum(ptr, size));
  printf("Minimum element in the data set = %d\n", find_minimum(ptr, size));
  printf("Mean element in the data set = %d\n", find_mean(ptr, size));
  printf("Median element in the data set = %d\n", find_median(ptr, size));
  printf("--------------------------------\n");
}

void print_array(unsigned char * ptr, unsigned char size)
{
  unsigned char i = 0;
  printf("\n--------------------------------\n");
  printf("Elements of the array are:-\n");
  for(i = 0; i < size; i++)
  {
    printf("Element of index %d = %d\n", i, ptr[i]);
  }
  printf("--------------------------------\n");
}

unsigned char find_median(unsigned char * ptr, unsigned char size)
{
  unsigned char index = 0;
  unsigned char median = 0;
  //array needs to be sorted before finding the median
  sort_array(ptr, size);

  if((size % 2) == 0)
  {
    // number of elements is even, median = mean of 2 middle elements
    index = (size/2) - 1;
    median = (ptr[index] + ptr[index+1]) / 2;
  }
  else
  {
    // number of elements is odd, median = the the middle element
    index = (size/2);
    median = ptr[index];
  }
}

unsigned char find_mean(unsigned char * ptr, unsigned char size)
{
  /*
  declaring a 16-bit integer variable that holds the sum of
  elements in the array of 8-bit integer elements to avoid
  overflow in some cases
  */
  unsigned short int sum = 0;
  unsigned char mean = 0;
  unsigned char i = 0;

  for(i = 0; i < size; i++)
  {
    sum += ptr[i];
  }

  mean = sum/size;

  return mean;

}

unsigned char find_maximum(unsigned char * ptr, unsigned char size)
{
  unsigned char maximum = 0;    // initialized with minimum value of unsigned char number
  unsigned char i = 0;

  for(i = 0; i < size; i++)
  {
    if(ptr[i] > maximum)
    {
      maximum = ptr[i];
    }
    else
    {;}   //do nothing
  }

  return maximum;
}

unsigned char find_minimum(unsigned char * ptr, unsigned char size)
{
  unsigned char minimum = 0xFF;    // initialized with maximum value of unsigned char number
  unsigned char i = 0;

  for(i = 0; i < size; i++)
  {
    if(ptr[i] < minimum)
    {
      minimum = ptr[i];
    }
    else
    {;}   //do nothing
  }

  return minimum;
}

void sort_array(unsigned char * ptr, unsigned char size)
{
  unsigned char i = 0, j = 0;
  unsigned char temp = 0;         // temporary variable used for swapping elements
  unsigned char swap_flag = 0;    // a flag that is set when a swap is occured to reduce overhead

  for(i = 0; i < size-1; i++)
  {
    for(j = 0; j < size-i-1; j++)
    {
      if(ptr[j] < ptr[j+1])
      {
        //swap elements to bubble up the lesser value
        temp = ptr[j];
        ptr[j] = ptr[j+1];
        ptr[j+1] = temp;
        swap_flag = 1;
      }
      else
      {;}   //do nothing
    }
    if(0 == swap_flag)
    {
      break;    // no swapping occured thus the array is sorted
    }
    else
    {
      swap_flag = 0;
    }
  }

}

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
 * @file stats.h 
 * @brief Contains function declarations for 
 * for statistics analysis
 *
 * This header file includes function declarations
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
#ifndef __STATS_H__
#define __STATS_H__



/**
 * @brief Prints the statistics of an array
 *
 * This function takes as input an address of an array
 * of 32-bit integer numbers and it's size in 32-bit
 * integer. This will print the statistics of the array
 * which are minimum, mixmum, mean and median
 *
 * @param The 32-bit address of the array for its statistics to be printed
 * @param The 32-bit size of the array for its statistics to be printed
 *
 * @return void
 */
void print_statistics(int * ptr, int size);


/**
 * @brief Prints the elements of an array
 *
 * This function takes as input an address of an array
 * of 32-bit integer numbers and it's size in 32-bit
 * integer. This will print the elements of the array
 *
 * @param The 32-bit address of the array to be printed
 * @param The 32-bit size of the array to be printed
 *
 * @return void
 */
void print_array(int * ptr, int size);


/**
 * @brief find the median of the elements of an array
 *
 * This function takes as input an address of an array
 * of 32-bit integer numbers and it's size in 32-bit
 * integer. This will find the median of the elements
 * in the array
 *
 * @param The 32-bit address of the array to find the median value
 * @param The 32-bit size of the array to find the median value
 *
 * @return The 32-bit value of the median calculated
 */
int find_median(int * ptr, int size);


/**
 * @brief find the mean of the elements of an array
 *
 * This function takes as input an address of an array
 * of 32-bit integer numbers and it's size in 32-bit
 * integer. This will find the mean of the elements
 * in the array
 *
 * @param The 32-bit address of the array to find the mean value
 * @param The 32-bit size of the array to find the mean value
 *
 * @return The 32-bit value of the mean calculated
 */
int find_mean(int * ptr, int size);


/**
 * @brief find the maximum of the elements of an array
 *
 * This function takes as input an address of an array
 * of 32-bit integer numbers and it's size in 32-bit
 * integer. This will find the maximum of the elements
 * in the array
 *
 * @param The 32-bit address of the array to find the maximum value
 * @param The 32-bit size of the array to find the maximum value
 *
 * @return The 32-bit value of the maximum calculated
 */
int find_maximum(int * ptr, int size);


/**
 * @brief find the minimum of the elements of an array
 *
 * This function takes as input an address of an array
 * of 32-bit integer numbers and it's size in 32-bit
 * integer. This will find the minimum of the elements
 * in the array
 *
 * @param The 32-bit address of the array to find the minimum value
 * @param The 32-bit size of the array to find the minimum value
 *
 * @return The 32-bit value of the minimum calculated
 */
int find_minimum(int * ptr, int size);


#endif /* __STATS_H__ */

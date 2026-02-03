/**
 * @file single_operations.h
 * @brief Single set operations for SmallSet library
 */

#ifndef SINGLE_OPERATIONS_H
#define SINGLE_OPERATIONS_H

#include <stdio.h>
#include <stdbool.h>
#include "./SmallSet.h"

/**
 * @brief Helper macro to create a new standard UINT value
 * @param x Value to wrap
 * @return UINT value (based on GenericSize)
 */
#define newValue(x) (uint8_t){x}

/**
 * @brief Create a new empty set
 * 
 * Allocates and initializes a new set based on GenericSize
 * 
 * @return A pointer to the newly allocated structure or NULL on allocation failure
 * 
 * @note User must manually free memory by calling freeSet() when done
 */
SmallSet createEmptySet(void);

/**
 * @brief Generate a new set with elements not in the original set
 * 
 * Flip each bit to its corresponding complement
 * 
 * @return A pointer to the newly allocated structure or NULL on allocation failure
 * 
 * @note User must manually free memory by calling freeSet() when done
 */
SmallSet setComplement(SmallSet sms);

/**
 * @brief Check if a specified value is in the set
 * 
 * Check if the corresponding bit is set to 1
 * 
 * @return True on match, False otherwise
 */
bool setContainsValue(SmallSet sms, uint8_t value);

/**
 * @brief Get the capacity of a set
 * 
 * @return Set capacity
 */
size_t getSetCapacity(SmallSet sms);

/**
 * @brief Free the memory allocated to a set structure
 */
void freeSet(SmallSet sms);

/**
 * @brief Insert a specified value into a set
 * @note Values must be specified using the newValue() macro
 * 
 * @note Values bigger than MAX_BITS are ignored and an error message is displayed
 */
void insertInSet(SmallSet sms, uint8_t value);

/**
 * @brief Print the elements of the set using special formatting
 */
void printSet(SmallSet sms);

/**
 * @brief Print the set as a UINT, based on GenericSize
 */
void printSetEncoding(SmallSet sms);

#endif
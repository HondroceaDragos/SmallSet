/**
 * @file compound_operations.h
 * @brief Compound set operations for SmallSet library
 */

#ifndef COMPOUND_OPERATIONS_H
#define COMPOUND_OPERATIONS_H

#include "./single_operations.h"

/**
 * @brief Create a new set containing the unique elements from the first set
 * 
 * Allocates and initializes a new set based on GenericSize
 * 
 * @return A pointer to the newly allocated structure or NULL on allocation failure
 * 
 * @note User must manually free memory by calling freeSet() when done
 */
SmallSet differenceBetweenSets(SmallSet sms1, SmallSet sms2);

/**
 * @brief Create a new set containing the intersection elements from the two sets
 * 
 * Allocates and initializes a new set based on GenericSize
 * 
 * @return A pointer to the newly allocated structure or NULL on allocation failure
 * 
 * @note User must manually free memory by calling freeSet() when done
 */
SmallSet intersectionBetweenSets(SmallSet sms1, SmallSet sms2);

/**
 * @brief Create a new set containing all the elements from both sets
 * 
 * Allocates and initializes a new set based on GenericSize
 * 
 * @return A pointer to the newly allocated structure or NULL on allocation failure
 * 
 * @note User must manually free memory by calling freeSet() when done
 */
SmallSet reunionBetweenSets(SmallSet sms1, SmallSet sms2);

/**
 * @brief Check if the two sets don't share any elements
 * 
 * @return True on match, False otherwise
 */
bool setsAreDisjoint(SmallSet sms1, SmallSet sms2);

/**
 * @brief Check if the second set is a subset of the first
 * 
 * @return True on match, False otherwise
 */
bool setIsSubsetOf(SmallSet sms2, SmallSet sms1);

#endif
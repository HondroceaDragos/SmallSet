/**
 * @file SmallSet.h
 * @brief Type definition for SmallSet library
 */

#ifndef SMALL_SET_H
#define SMALL_SET_H

#include <stdlib.h>

#include <stdint.h>
#include <inttypes.h>

/**
 * @brief Set the standard size of a set
 */
#ifndef GenericSize
#define GenericSize uint32_t
#endif

/**
 * @brief Compute the maximum size of a set
 */
#define MAX_BITS 8 * sizeof(GenericSize)

/**
 * @brief Generic printing macro for UINT values
 * @param x Value to be printed
 */
#define PRINT_UINT(x) printf(_Generic((x), \
    uint8_t: "%" PRIu8 "\n", \
    uint16_t: "%" PRIu16 "\n", \
    uint32_t: "%" PRIu32 "\n", \
    uint64_t: "%" PRIu64 "\n", \
    default: "%u\n"), (x))

/**
 * @brief SmallSet data type implementation
 * Internally stored as a bitmask, which can hold MAX_BITS entries
 */
typedef struct small_set {
    GenericSize elements;
    size_t capacity;
} *SmallSet;

#endif
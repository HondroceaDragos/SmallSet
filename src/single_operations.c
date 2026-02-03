#include "../include/single_operations.h"

SmallSet createEmptySet(void) {
    SmallSet sms = (SmallSet)calloc(1, sizeof(struct small_set));

    sms->capacity = MAX_BITS;

    return sms;
}

size_t getSetCapacity(SmallSet sms) {
    return sms->capacity;
}

void insertInSet(SmallSet sms, uint8_t value) {
    if (value >= MAX_BITS) {
        fprintf(stderr, "ERROR: Value to be inserted must be between 0 and %llu.\n", MAX_BITS);
        return;
    }

    sms->elements |= 1 << value;
}

bool setContainsValue(SmallSet sms, uint8_t value) {
    return !((sms->elements & (1u << value)) == 0);
}

SmallSet setComplement(SmallSet sms) {
    SmallSet result = createEmptySet();

    result->elements = ~sms->elements;

    return result;
}

void printSet(SmallSet sms) {
    printf("{");

    size_t capacity = sms->capacity;
    for (size_t idx = 0; idx < capacity; idx++) {
        if (setContainsValue(sms, idx)) {
            printf(" %zu", idx);
        }
    }

    printf(" }\n");
}

void printSetEncoding(SmallSet sms) {
    PRINT_UINT(sms->elements);
}

void freeSet(SmallSet sms) {
    free(sms);
}
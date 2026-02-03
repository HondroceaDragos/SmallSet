#include <stdio.h>

#include "smallset.h"

#define newline "\n"

/* Helper - declare a new set */
SmallSet debugger(int v1, int v2, int v3) {
    SmallSet sms1 = createEmptySet();

    printSet(sms1);

    insertInSet(sms1, newValue(v1));
    insertInSet(sms1, newValue(v2));
    insertInSet(sms1, v3);

    printf("Set encoding: ");
    printSetEncoding(sms1);
    printf("Set capacity: ");
    printf("%llu\n", getSetCapacity(sms1));
    printf("Set elements:\n");
    printSet(sms1);

    return sms1;
}

int main(void) {

    SmallSet sms1 = debugger(3, 5, 0);

    printf(newline);

    SmallSet sms2 = debugger(23, 5, 3);

    printf(newline);

    SmallSet intersection = intersectionBetweenSets(sms1, sms2);
    printf("Set intersection:\n");
    printSet(intersection);

    printf(newline);

    SmallSet reunion = reunionBetweenSets(sms1, sms2);
    printf("Set reunion:\n");
    printSet(reunion);

    printf(newline);

    SmallSet complement = setComplement(sms1);
    printf("Set complement (1):\n");
    printSet(complement);

    printf(newline);

    SmallSet diff12 = differenceBetweenSets(sms1, sms2);
    printf("Difference between sets (1 - 2):\n");
    printSet(diff12);
    
    printf(newline);

    SmallSet diff21 = differenceBetweenSets(sms2, sms1);
    printf("Difference between sets (2 - 1):\n");
    printSet(diff21);

    printf(newline);

    printf("Sets are: %s\n", setsAreDisjoint(sms1, sms2) ? "disjoint" : "not disjoint");
    printf("Set 1 is: %s subset of 2\n", setIsSubsetOf(sms1, sms2) ? "a" : "not a");
    printf("Set 2 is: %s subset of 1\n", setIsSubsetOf(sms2, sms1) ? "a" : "not a");

    freeSet(sms1);
    freeSet(sms2);
    freeSet(intersection);
    freeSet(reunion);
    freeSet(complement);
    freeSet(diff12);
    freeSet(diff21);

    return 0;
}
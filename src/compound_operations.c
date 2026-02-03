#include "../include/compound_operations.h"

SmallSet intersectionBetweenSets(SmallSet sms1, SmallSet sms2) {
    SmallSet result = createEmptySet();

    result->elements = sms1->elements & sms2->elements;

    return result;
}

SmallSet reunionBetweenSets(SmallSet sms1, SmallSet sms2) {
    SmallSet result = createEmptySet();

    result->elements = sms1->elements | sms2->elements;

    return result;
}

SmallSet differenceBetweenSets(SmallSet sms1, SmallSet sms2) {
    SmallSet result = createEmptySet();

    result->elements = sms1->elements & setComplement(sms2)->elements;

    return result;
}

bool setsAreDisjoint(SmallSet sms1, SmallSet sms2) {
    return ((sms1->elements & sms2->elements) == 0);
}

bool setIsSubsetOf(SmallSet sms2, SmallSet sms1) {
    return ((sms2->elements & setComplement(sms1)->elements) == 0);
}
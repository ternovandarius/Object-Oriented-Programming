#include "Compare.h"

bool Compare::compare(TElem t1, TElem t2) {
}

bool CompareAscendingByYear::compare(TElem t1, TElem t2) {
    if(t1.get_year()<=t2.get_year())
        return true;
    return false;
}

bool CompareDescendingByTitle::compare(TElem t1, TElem t2) {
    if(t1.get_title().compare(t2.get_title())>=0)
        return true;
    return false;
}
#include <stdio.h>
#include "MyVector.h"

int main() {
    vector* vec = vectorInit();
    
    pushBack(vec, makeHash(1, 2));
    pushBack(vec, makeHash(3, 4));
    pushBack(vec, makeHash(4, 2));
    pushBack(vec, makeHash(4, 4));
    pushBack(vec, makeHash(1, 1));
    pushBack(vec, makeHash(3, 3));
    for(int i = 0; i<vec->size; ++i) {
        printf("%s \n", hashToString(getElem(vec, i)));
    }
}
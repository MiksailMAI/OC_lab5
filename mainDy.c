#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include "MyVector.h"

int main() {
    void* lib;
    lib = dlopen("./libVector.so", RTLD_LAZY);
    if(!lib) {
        fputs(dlerror(), stderr);
        exit(1);
    }

    char (*getHDigit)(unsigned number);
    md5 (*makeHash)(unsigned long long p1, unsigned long long p2);
    char* (*hashToString)(md5 hash);

    vector* (*vectorInit)();
    void (*pushBack)(vector* in, md5 value);
    md5 (*getElem)(vector* in, unsigned i);
    void (*setElem)(vector* in, unsigned i, md5 value);
    void (*erase)(vector* in);
    unsigned (*getSize)(vector* in);


    getHDigit = dlsym(lib, "getHDigit");
    makeHash = dlsym(lib, "makeHash");
    hashToString = dlsym(lib, "hashToString");

    vectorInit = dlsym(lib, "vectorInit");
    pushBack = dlsym(lib, "pushBack");
    getElem = dlsym(lib, "getElem");
    setElem = dlsym(lib, "setElem");
    erase = dlsym(lib, "erase");
    getSize = dlsym(lib, "getSize");



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
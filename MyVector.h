#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <stdio.h>
#include <stdlib.h>

typedef struct MD5 {
    unsigned long long part1;
    unsigned long long part2;
} md5;

extern char getHDigit(unsigned number);
extern md5 makeHash(unsigned long long p1, unsigned long long p2);
extern char* hashToString(md5 hash);


typedef struct Vector {
    md5 *data;
    unsigned int size;
    unsigned int capacity;
} vector;

extern vector* vectorInit();
extern void pushBack(vector* in, md5 value);
extern md5 getElem(vector* in, unsigned i);
extern void setElem(vector* in, unsigned i, md5 value);
extern void erase(vector* in);
extern unsigned getSize(vector* in);

#endif
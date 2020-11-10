#include "MyVector.h"

md5 makeHash(unsigned long long p1, unsigned long long p2) {
    return (md5){.part1 = p1, .part2 = p2};
}

char getHDigit(unsigned number) {
    if (number < 10) {
        return '0' + number;
    } else {
        return 'A' + number - 10;
    }
}

char* hashToString(md5 hash) {
    char* result = malloc(sizeof(char) * 33);
    result[32] = '\0';
    for (int i = 0; i < 32; ++i) {
        unsigned long long* number = (i < 16 ? &hash.part1 : &hash.part2);
        unsigned cur_bits = ((*number) >> ((15 - i) * 4)) & 15u;
        result[i] = getHDigit(cur_bits);
    }
    return result;
}

vector* vectorInit() {
    vector* in = (vector*)malloc(sizeof(vector));
    in->size = 0;
    in->capacity = 1;
    in->data = (md5*)malloc(sizeof(md5)*in->capacity);
    return in;
}

void pushBack(vector* in, md5 value) {
    if (in->size >= in->capacity) {
        in->capacity *= 2;
        md5* new_data = (md5*)malloc(sizeof(md5)*in->capacity);
        for (unsigned i = 0; i < in->size; ++i) {
            new_data[i] = in->data[i];
        }
        free(in->data);
        in->data = new_data;
        in->data[in->size++] = value;
    }
    else {
        in->data[in->size++] = value;
    }
}

md5 getElem(vector* in, unsigned i) {
    if(i >= in->size) {
        return in->data[0];
    }
    else {
        return in->data[i];
    }
}

void setElem(vector* in, unsigned i, md5 value) {
    if(i < in->size) {
        in->data[i] = value;
    }
}

void erase(vector* in) {
    free(in->data);
}

unsigned getSize(vector* in) {
    return in->size;
}
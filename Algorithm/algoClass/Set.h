//
// Created by LanFear on 2021/4/29.
//

#ifndef ALGOCLASS_SET_H
#define ALGOCLASS_SET_H

typedef int data_type;
typedef int key_type;

struct dicElement {
    key_type key;
    data_type value;
};

struct hashDictionary {
    int m;
    struct dicElement *element;
};
typedef struct hashDictionary *pHashDictionary;

pHashDictionary createEmptyDictionary(int size);

int linearSearch(pHashDictionary pHash, key_type key, int *pos);

int linearInsert(pHashDictionary pHash, struct dicElement ele);

#endif //ALGOCLASS_SET_H

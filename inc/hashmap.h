#ifndef HASHMAP_H
#define HASHMAP_H

#include "stdlib.h"
#include "rowList.h"
#include <random>

#define ARRAY_SIZE 17

class Hashmap{
    private:
    int count;
    int length;
    RowList** map;
    

    public:
    int hash(char* key);
    char* rowId();
    Hashmap();
    int put(Row* row);
    Row* get(char* key);
    int getLength();
    void deleteRow(char* key);
    void printMap();

};


#endif /*HASHMAP_H*/
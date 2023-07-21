#ifndef HASHMAP_H
#define HASHMAP_H

#include "stdlib.h"
#include "llist.hpp"
#include "row.hpp"
#include "node.hpp"
#include <random>

#define ARRAY_SIZE 23

class Hashmap{
    private:
    int count;
    int length;
    Llist<Row>** map;
    int hash(char* key);
    char* rowId();

    public:
    Hashmap();
    int put(Row* row);
    Row* get(char* key);
    int getLength();
    void deleteRow(char* key);
    void printMap();

};


#endif /*HASHMAP_H*/
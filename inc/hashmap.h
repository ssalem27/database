#ifndef HASHMAP_H
#define HASHMAP_H

#include "stdlib.h"
#include "rowList.h"
#include "stdio.h"
#include <random>
#include <unistd.h>
#include <fcntl.h>

#define ARRAY_SIZE 17

class Hashmap{
    private:
    char* Id;
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
    void printTable(char* fileName);
    char* getId();
    void setId(char* key);

};


#endif /*HASHMAP_H*/
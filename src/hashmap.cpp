#include "hashmap.h"


Hashmap::Hashmap(){
    length = 0;
    count = 1;
    map = (RowList**) calloc(ARRAY_SIZE, sizeof(RowList));
    for(int i=0; i<ARRAY_SIZE; i++){
        map[i] = new RowList;
    }

}

char* Hashmap::rowId(){
    int id = this->count;
    char* rowId = (char*) calloc(BUFFER_SIZE, sizeof(char));
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 16);
    id<<=16;
    id= id+(dist(mt)<<12) + (dist(mt)<<8) + (dist(mt)<<4) + dist(mt);
    this->count++;
    snprintf(rowId,BUFFER_SIZE,"%x",id);
    return rowId;
}

int Hashmap::hash(char* key){
    int p = 11;
    int n = strlen(key);
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += key[i]* pow(p,i);
    }
    return sum%ARRAY_SIZE;
}

int Hashmap::put(Row* row){
    char* rowId;
    RowNode* nodeRow;
    if(row){
        rowId = this->rowId();
        row->setRowId(rowId);
        nodeRow = new RowNode(rowId,row);
        map[this->hash(rowId)]->append(nodeRow);
        this->length++;
        return 0;
    }
    return -1;
}

Row* Hashmap::get(char* key){
    RowNode* node = map[this->hash(key)]->get(key);
    if(node){
        return node->getValue();
    }
    return NULL;
}

int Hashmap::getLength(){
    return this->length;
}

void Hashmap::deleteRow(char* key){
    RowNode *node = map[this->hash(key)]->get(key);
    if(node){
        node->getValue()->deleteRow();
        node->freeNode();
        node = map[this->hash(key)]->deleteNode(key);
        delete(node);
        this->length--;
    }
}

void Hashmap::printMap(){
    printf("Hashmap\n{\n");
    printf("\"length\": %d\n",this->length);
    printf("\"map\":{\n");
    for(int i=0; i<ARRAY_SIZE; i++){
        if(map[i]->getLength()>0){
            printf("\"index: %d\n",i);
            map[i]->printList();
        }
    }
    std::cout<<"}\n}\n";
}

int main(){
    Hashmap* hashmap = new Hashmap();
    // Row* row1 = new Row();
    // row1->addColumn((char*)"key1",(char*)"val1");
    // row1->addColumn((char*)"key2",(char*)"val2");

    // Row* row2 = new Row();
    // row2->addColumn((char*)"key3",(char*)"val3");
    // row2->addColumn((char*)"key4",(char*)"val4");
    // row2->addColumn((char*)"key5",(char*)"val5");

    // Row* row3 = new Row();
    // row3->addColumn((char*)"key6",(char*)"val6");

    // Row* row4 = new Row();
    // row4->addColumn((char*)"key7",(char*)"val7");
    // row4->addColumn((char*)"key8",(char*)"val8");
    // row4->addColumn((char*)"key9",(char*)"val9");
    // row4->addColumn((char*)"key10",(char*)"val10");
    // row4->addColumn((char*)"key11",(char*)"val11");

    // hashmap->put(row1);
    // hashmap->get(row1->getRowId())->printRow();
    // hashmap->put(row2);
    // hashmap->get(row2->getRowId())->printRow();
    // hashmap->put(row3);
    // hashmap->get(row3->getRowId())->printRow();
    // hashmap->put(row4);
    // hashmap->get(row4->getRowId())->printRow();

    // hashmap->printMap();

    for(int i=0; i<500; i++){
        printf("%d\n",hashmap->hash(hashmap->rowId()));
    }
    return 0;
}
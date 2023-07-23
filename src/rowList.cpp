#include "rowList.h"



RowList::RowList(){
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

int RowList::append(RowNode *node){
    if(node){
        if(head==NULL){
            head= tail = node;
            length++;
            return 0;
        }
        tail->next = node;
        tail = node;
        this->length++;
        return 0;
    }
    return -1;
}


RowNode* RowList::deleteNode(char *key){
    RowNode* node = NULL;
    RowNode* deleted = NULL;
    RowNode* nodeNext = NULL; 
    RowNode* current = this->head;
    
    if(!current){
        return NULL;
    }

    if(head->compare(key)){
        RowNode* node;
        if(head->next){
            node = head->next;
            head->freeNode();
            deleted = head;
            head = node;
            length--;
            return deleted;
        }
        head->freeNode();
        deleted = head;
        head = tail = NULL;
        length--;
        return deleted;
    }
    while(current->next){
        if(current->next->compare(key)){
            node = current->next;
            nodeNext = node->next;
            current->next = nodeNext;
            node->freeNode();
            deleted = node;
            this->length--;
            return deleted;
        }
        current = current->next;
    }
    return NULL;
}

RowNode* RowList::get(char *key){
    RowNode* current = this->head;
    while(current){
        if (current->compare(key)){
            return current;
        }
        current = current->next;
    }
    return NULL;

}

void RowList::freeList(){
    RowNode* current = this->head;
    RowNode* temp = NULL;
    while(current->next){
        temp = current->next;
        current->freeNode();
        current = temp;
    }
    this->head = this->tail = current;
    length = 0;
}

void RowList::printList(){
    RowNode* current = this->head;
    while(current){
        current->printNode();
        current = current->next;
        std::cout << "\n";
    }
}

RowNode* RowList::getHead(){
    return this->head;
}

int RowList::getLength(){
    return this->length;
}
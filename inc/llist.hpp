#ifndef LLIST_H
#define LLIST_H
 
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include "node.hpp"

template <typename T>
class Llist{
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;

    public:

    Llist(){
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    }

    int append(Node<T> *node){
        if(node){
            if(head==NULL){
                head= tail = node;
                return 0;
            }
            tail->next = node;
            tail = node;
            this->length++;
            return 0;
        }
        return -1;
    }

    Node<T>* deleteNode(char *key){
        Node<T>* node = NULL;
        Node<T>* deleted = NULL;
        Node<T>* nodeNext = NULL; 
        Node<T>* current = this->head;
        
        if(!current){
            return NULL;
        }

        if(head->compare(key)){
            Node<T>* node;
            if(head->next){
                node = head->next;
                head->freeNode();
                deleted = head;
                head = node;
                this->length--;
                return deleted;
            }
            head->freeNode();
            deleted = head;
            head = tail = NULL;
            this->length--;
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

    Node<T>* get(char *key){
        Node<T>* current = this->head;
        while(current){
            if (current->compare(key)){
                return current;
            }
            current = current->next;
        }
        return NULL;

    }

    void freeList(){
        Node<T>* current = this->head;
        Node<T>* temp = NULL;
        while(current->next){
            temp = current->next;
            current->freeNode();
            current = temp;
        }
        this->head = this->tail = current;
        this->length = 0;
    }

    void printList(){
        Node<T>* current = this->head;
        while(current){
            current->printNode();
            current = current->next;
            std::cout << "\n";
        }
    }

    int getLength(){
        return this->length;
    }

    Node<T>* getHead(){
        return this->head;
    }
};

#endif /*LLIST_H*/



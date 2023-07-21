#include "llist.h"


template <typename T>
Llist<T>::Llist(){
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

template <typename T>
int Llist<T>::append(Node<T> *node){
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

template <typename T>
Node<T>* Llist<T>::deleteNode(char *key){
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
            return deleted;
        }
        head->freeNode();
        deleted = head;
        head = tail = NULL;
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

template <typename T>
Node<T>* Llist<T>::get(char *key){
    Node<T>* current = this->head;
    while(current){
        if (current->compare(key)){
            return current;
        }
        current = current->next;
    }
    return NULL;

}

template <typename T>
void Llist<T>::freeList(){
    Node<T>* current = this->head;
    Node<T>* temp = NULL;
    while(current->next){
        temp = current->next;
        current->freeNode();
        current = temp;
    }
    this->head = this->tail = current;
}

template <typename T>
void Llist<T>::printList(){
    Node<T>* current = this->head;
    while(current){
        current->printNode();
        current = current->next;
        std::cout << "\n";
    }
}


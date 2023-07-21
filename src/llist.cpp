#include "llist.h"



Llist::Llist(){
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}


int Llist::append(Node *node){
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


Node* Llist::deleteNode(char *key){
    Node* node = NULL;
    Node* deleted = NULL;
    Node* nodeNext = NULL; 
    Node* current = this->head;
    
    if(!current){
        return NULL;
    }

    if(head->compare(key)){
        Node* node;
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

Node* Llist::get(char *key){
    Node* current = this->head;
    while(current){
        if (current->compare(key)){
            return current;
        }
        current = current->next;
    }
    return NULL;

}

void Llist::freeList(){
    Node* current = this->head;
    Node* temp = NULL;
    while(current->next){
        temp = current->next;
        current->freeNode();
        current = temp;
    }
    this->head = this->tail = current;
}

void Llist::printList(){
    Node* current = this->head;
    while(current){
        current->printNode();
        current = current->next;
        cout << "\n";
    }
}


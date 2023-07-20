#include "llist.h"



Llist::Llist(){
    this->head = NULL;
    this->tail = NULL;
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


int Llist::deleteNode(char *key){
    Node* node = NULL;
    Node* nodeNext = NULL; 
    Node* current = this->head;
    
    if(!current){
        return -1;
    }

    if(head->compare(key)){
        Node* node;
        if(head->next){
            node = head->next;
            head->freeNode();
            head = node;
            return 0;
        }
        head->freeNode();
        head = tail = NULL;
        return 0;
    }
    while(current->next){
        if(current->next->compare(key)){
            node = current->next;
            nodeNext = node->next;
            current->next = nodeNext;
            node->freeNode();
            this->length--;
            return 0;
        }
        current = current->next;
    }
    return -1;
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

int Llist::updateVal(char *key, char *value){
    return get(key)->setValue(value);
}

int Llist::updateKey(char *oldKey, char *newKey){
    return get(oldKey)->setKey(newKey);
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


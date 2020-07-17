#include "LinkedList.hpp"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    head = NULL;
}

void LinkedList::insertSorted(LinkedList::Node*& _head,int _value){
    Node* newNode = new Node();
    newNode->data = _value;
    newNode->next = NULL;
    Node* prev;
    Node* temp = _head;
    if(temp == NULL){ // it's the first value to be inserted
        _head = newNode;
        return;
    }
    if(_value < temp->data){ // insert position is at the start
        newNode->next = temp;    
        _head = newNode;
        return;        
    }      
    while(temp->next != NULL){ // insert position is at the middle
        prev = temp;    // move forward
        temp = temp->next;  
        if(_value < temp->data){ // position is found
            prev->next = newNode;
            newNode->next = temp;    
            return;        
        }               
    }
    temp->next = newNode; // insert position is at the end
}
int LinkedList::length(LinkedList::Node*& _head){
    int len = 0;
    Node* temp = _head;
    if(temp == NULL){
        return 0;
    }
    len++;  // there is at least one node
    while(temp->next != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

int LinkedList::search(LinkedList::Node*& _head,int _value){
    int pos = 0;
    Node* temp = _head;
    if(temp == NULL)    return -1;
    if(temp->data == _value)    return pos; 
    while(temp->next != NULL){
        temp = temp->next;
        pos++;
        if(temp->data == _value)    return pos; 
    }
    return -1;
}
void LinkedList::remove(LinkedList::Node*& _head,int _value){
    Node* temp = _head;
    Node* prev;
    if(temp == NULL)    return;
    // data is at the start
    if(temp->data == _value){ 
        if(temp->next == NULL){
            _head = NULL;
            return;
        }
        _head = temp->next;
        return;
    }
    // data is at the middle
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
        if(temp->data == _value){
            prev->next = temp->next;
            return;
        }
    }
    // data is at the end
    if(temp->data == _value){
        prev->next = NULL;
        return;
    }
}

void LinkedList::display(LinkedList::Node*& _head){
    Node* iterator = _head; // Do not want to move the actual head, make a copy
    
    if (iterator == NULL){
        cout << "The list is empty";
    }
    
    while(iterator!=NULL)
    {
        cout << "[" + std::to_string(iterator->data) + "] ";
        iterator=iterator->next;
    }
}

LinkedList::Node*& LinkedList::getHead(){
    return*& this->head;
}

int main(){
    // test the functions
    LinkedList* test = new LinkedList();
    test->insertSorted(test->getHead(), 1);
    test->insertSorted(test->getHead(), 2);
    test->insertSorted(test->getHead(), 3);
    test->insertSorted(test->getHead(), 5);
    test->display(test->getHead());
    printf("lengh: %i\n", test->length(test->getHead()));
    printf("pos of 3: %i\n", test->search(test->getHead(), 3));
    test->remove(test->getHead(), 5);
    test->remove(test->getHead(), 1);
    test->display(test->getHead());
    test->~LinkedList();
    test->display(test->getHead());
    return 0;
}

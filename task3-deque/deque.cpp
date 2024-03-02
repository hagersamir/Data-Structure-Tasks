#include "deque.h"
#include <iostream>
using namespace std;

My_Deque::My_Deque(){
    front = rear = nullptr;
    size=0;
}
My_Deque::~My_Deque() {
    size = 0;
    front = rear = nullptr;

}

int My_Deque::end() {
    if (size==0){
        return  -1;
    }else
        return (rear->data);
}

int My_Deque::begin() {
    if (size==0){
        return  -1;
    }else
        return (front->data);
}
//check if list is empty and added the first node then front = rear else added node at the end
void My_Deque::push_back(int element) {
    node *OtherNode = new node;
    OtherNode ->data = element;
    if (size==0){
        OtherNode ->next =OtherNode ->prev = nullptr;
        front = rear = OtherNode;
    } else
    {
        OtherNode->prev = rear;
        rear ->next =OtherNode;
        OtherNode ->next =nullptr;
        rear = OtherNode;
    }
    size ++ ;
}
//check if list is empty and added the first node then front = rear else added node at the beginning
void My_Deque::push_front(int element) {
    node *OtherNode = new node;
    OtherNode ->data = element;
    if (size==0){
        OtherNode ->next =OtherNode ->prev = nullptr;
        front = rear = OtherNode;
    }else
    {
        OtherNode ->next =front;
        front ->prev = OtherNode;
        OtherNode ->prev = nullptr;
        front = OtherNode;
    }
    size ++;
}
//check if list is empty then can't remove anything return -1
// else create a new pointer and make it equal to
// rear and move the rear pointer to the previous node then delete the new pointer and return it's value
int My_Deque::pop_back() {
    if (size==0){
        return -1;
    } else{
        int  e = rear ->data;
        node *temp = rear;
        rear = rear ->prev;
        rear ->next = nullptr;
        free (temp);
        size--;
        return e;
    }
}
//check if list is empty then can't remove anything return -1
// else create a new pointer and make it equal to
// front and move the front pointer to the nest node then delete the new pointer and return it's value
int My_Deque::pop_front() {
    if (size == 0) {
        return -1;
    } else {
        int e = front->data;
        node *temp = front;
        front = front->next;
        free (temp);
        size--;
        return e;
    }
}
// convert the deque to vector and return that vector by creating node
// moving from front to the null to copy all data in deque in vector
std::vector<int> My_Deque::toVector() {
    vector<int> vec;
    node *temp = front;
    while (temp != nullptr){
        vec.push_back( temp -> data);
        temp =temp->next;
    }
    return vec;
}
//check if list is empty we don't have anything to print else we create
// a new pointer equal to front as it points to first element and make while loop to move the new pointer to
// reach to the rear as it points to last element and printing value of current in each loop
void My_Deque::print() {
    if (size==0){
        cout << "An empty deque"<< endl;
    }else
    {
        node *curr ;
        while (front != nullptr)
        {
            curr = front ;
            cout << curr ->data <<endl;
            front = front->next;
        }
    }

}
// delete all elements in deque
void My_Deque::clear() {
    node *temp;
    while (front != nullptr){
        temp= front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
    size =0;
}

int My_Deque::get_size() {
    return size;
}

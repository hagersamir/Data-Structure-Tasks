#include "da.h"
#include <iostream>
using namespace std;
My_DA :: My_DA ()
{
    size = 0;
    capacity = 1;
    data = new int[capacity];
}
My_DA::My_DA(int *arr, int size)
{
    this ->size = size;
    while (size >= capacity){
        capacity*=2;
    }
    data = new int[capacity];
    for(int i = 0; i < size ; i++)
    data[i] = arr [i];
}
int My_DA :: get(int index)
{
    return data [index];
}
void My_DA :: push(int element)
{
    if (size < capacity) {
        data[size++] = element;
    }
    if (size >= capacity) {
        expand();
    }
}
int My_DA ::pop()
{
    int element = data[size-1];
    if (size < 1) {
        return -1;
    }

        if (size-1 <= capacity/4){
        shrink();
    }
    size--;
    if (size==0){
        capacity = 1;
    }
    return element;
}
    void My_DA::insert(int index, int element)
{
    if (index > size){
        expand();
        data[index] = element;
    }
    for (int i = size; i > index ; i--)
        data[i] = data[i-1];
        data[index] = element;
        size++;
}
int My_DA::remove(int index)
{
    int element = data[index];
    if (index <0 || index > size-1)
    {
       cout<<"invalid index"<<endl;
        return -1;
    }
    if (size < 1)
    {
        cout<< "the array is empty"<<endl;
        return -1;
    }
    if (size<=capacity/4)
    {
        shrink();
    }
    for (int i = index; i < size-1 ; i++) {
        data[i] = data[i + 1];
    }
    size--;
    if (size==0){
        capacity = 1;
    }
    return element;
}
void My_DA::print()
{
    for (int i = 0; i < size; i++)
    {
        cout<<data[i]<<endl;
    }
}
void My_DA::expand()
{
    capacity *= 2;
    int *T = new int[capacity];
    for (int i = 0; i < size; i++){
    T[i] = data[i];
    }
    delete [] data;
    data = T;
}
void My_DA::clear()
{
    size = 0;
    capacity = size ;
    data = nullptr;
}
int My_DA::find(int element)
{
    for (int i = 0; i < size-1 ; i++) {
        if (data[i] == element)
            return i;
    }
    return -1;
}
int My_DA::get_size()
{
    return size;
}
int My_DA::get_capacity()
{
    return capacity;
}
void My_DA::shrink()
{
    capacity/=2;
    int *temp = new int[capacity];
    for (int i = 0; i < size ; i++) {
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
}
My_DA::~My_DA()
{
    size = 0;
    capacity = size;
    delete [] data;
}

// implement all the methods in da.h
// feel free to add new helper methods whether private or public
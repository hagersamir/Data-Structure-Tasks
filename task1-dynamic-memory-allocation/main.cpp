#include <iostream>
#include "da.h"
using namespace std;

int main(int argc, char** argv) {
    My_DA *my_arr = new My_DA();
    cout << my_arr->get_size() << endl;
    cout << my_arr->get_capacity() << endl;
    My_DA* my_arr1 = new My_DA();
    my_arr1->push(5);
    my_arr1->insert(0, 10);
    cout<< my_arr1->get(0)<<endl;
    cout<< my_arr1->get(1)<<endl;
    int arr[] = {5, 3, 2};
    My_DA* my_arr2 = new My_DA(arr, 3);
    cout<<my_arr2->remove(3)<<endl;
    cout<<my_arr2->remove(1)<<endl;
    cout<<my_arr2->pop()<<endl;
    cout<<my_arr2->remove(0)<<endl;
    cout<<my_arr2->pop()<<endl;
    cout<< my_arr2->get_size()<<endl;
    cout<< my_arr2->get_capacity()<<endl;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    My_DA* my_arr3 = new My_DA(arr1, 8);
    my_arr3->push(9);
    cout<< my_arr3->get_size()<<endl;
    cout<< my_arr3->get_capacity()<<endl;
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8,9};
    My_DA* my_arr4 = new My_DA(arr3, 9);
    my_arr4->pop();
    my_arr4->pop();
    my_arr4->pop();
    my_arr4->pop();
    my_arr4->pop();
    cout<<my_arr4->get_size()<<endl;
     cout<<my_arr4->get_capacity() <<endl;
}
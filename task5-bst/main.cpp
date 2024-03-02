#include <iostream>
#include "my_tree.h"
using namespace std;

int main(int argc, char** argv)
{
  
    MyTree<char> my_tree = MyTree<char>();
    cout<<my_tree.get_size()<<endl;
}
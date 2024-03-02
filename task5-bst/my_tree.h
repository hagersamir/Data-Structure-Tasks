#ifndef MY_TREE_H
#define MY_TREE_H
#include <queue>
#include <stack>
#include <vector>
#include<algorithm>
#include "iostream"
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
template <class T>
struct Node
 {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(T data) : data(data) {}
    // Add the constructors you want
};
 
template <class T>
class MyTree
{
    private:
    Node <T> *root=nullptr;
    Node<T>* constructor (vector<T> el ,int F ,int E)
    {
     if (F>E)
     {
       return NULL;
     }
     float m = ceil((F+E)/2.0) ;
     Node<T>*temp = new Node<T>(el[m]);
     temp->left = constructor(el,F,m-1);
     temp->right = constructor(el,m+1,E);
     root = temp;
     return root;
    }
    //sending the tree and element that we want to insert then return pointer to the last location we stop on it
    Node<T>* insert_priv (Node<T>* r,T key)
    {
     if (!r)
     {
       return new Node<T>(key);
     }
     if(key<r->data)
     {
       r->left = insert_priv(r->left,key);
     }
     else if (key>r->data)
     {
       r->right= insert_priv(r->right,key);
     }
     return r;
    }
    Node<T> *search_priv (Node<T>*root,T key)
    {
     if (root==NULL || key == root->data)
     {
       return root;
     }
     if (key < root -> data)
     {
       return search_priv(root->left,key);
     }
       return search_priv(root->right ,key);
    }
    Node<T>* Delete_node(Node<T>*root,T key) 
    {   
    //An empty tree
    if (root==NULL) 
    {
      return NULL;
    }
   //item exist in left subtree
    if (key < root->data)
    {
     root->left = Delete_node(root->left,key);
     return root;
    }
   //item exist in right subtree
   else if (key > root->data)
   {
     root->right = Delete_node(root->right,key);
     return root;
   }
   if (root->left == nullptr)
   {
    Node<T>* R = root->right;
    delete root;
    return R;
   }
   else if(root->right == nullptr)
   {
    Node<T>* L = root->left;
    delete root;
    return L;
   }
   else
   {
    Node<T>* temp1 = root;
    Node<T>* temp2 = root->right;
    while (temp2->left != nullptr)
    {
      temp1 = temp2;
      temp2 = temp2->left;
    }
    if (temp1 != root)
     temp1->left = temp2->right;
    else
     temp1->right = temp2->right;
    delete temp2;
    return root;
    }
   }
        void inorder_rec_priv( Node <T>* root,vector<T>& v) 
        { 
         if (root!=NULL)
         {  
         inorder_rec_priv (root->left,v);
         v.push_back( root->data);
         inorder_rec_priv (root->right,v);
         }
        }
        void preorder_rec_priv(Node <T> *root,vector <T>& v)
        { 
          if(root!=NULL)
          {
           v.push_back(root->data);
           preorder_rec_priv (root->left,v);
           preorder_rec_priv (root->right,v);
          }
        }
        void postorder_rec_priv(Node <T> *root,vector <T>& v)
        {
            if (root!=NULL)
            {
             postorder_rec_priv (root->left,v);
             postorder_rec_priv (root->right,v);
            v.push_back( root->data);
            }
        }
         //left->root->right (using stack)
        void inorder_it_priv(Node <T> *root, vector <T>& v )
        { 
         stack <Node<T>*> s;
         while (root != nullptr || !s.empty())
         {
          if (root != nullptr)
          {
            s.push(root);
            root = root->left;
          }
          else
          {
            root = s.top();
            s.pop();
            v.push_back(root->data);
            root = root->right;
          }
         }
        }
         //root->left->right (using stack)
        void preorder_it_priv(Node <T> *root,vector <T>& v)
        {  
          stack <Node<T>*> s;
          while (root != nullptr || !s.empty())
          {
           if (root != nullptr)
           {
             s.push(root);
             v.push_back(root->data);
             root = root->left;
           }
           else
           {
             root = s.top();
             s.pop();
             root = root->right;
           }
         }
        }
        //left->right->root (using stack)
        void postorder_it_priv(Node <T> *root,vector <T>& v)
        {
         stack <Node<T>*> s;
         Node <T> *temp = root;
         while (true)
         {
          if (temp!= NULL)
          {
           s.push(temp);
           temp=temp->left;
          }
          else
          {
            if (s.empty())
            {
              break;
            }
            temp=s.top()->right;
            if (temp == nullptr)
            {
             Node<T>* final = nullptr;
             while (!s.empty() && s.top()->right == final)
             {
              final = s.top();
              s.pop();
             v.push_back(final->data);
             }
            }  
          }
         }
        }
         // display level by level and from left to right using queue 
        void breadth_traversal_priv(Node<T>*root,vector <T>& v)
        {  
           if (root == NULL)
           {
            return;
           }  
            queue <Node<T> *> q ;
            //push the root
           q.push(root);
          while (!q.empty())
          {
            //pick the root
            Node<T>* temp = q.front();
           v.push_back(temp->data);
           //pop the root
          q.pop();
           if (temp->left!= NULL)
           {
            q.push(temp-> left);
           }
           if (temp->right != NULL)
           {
            q.push(temp-> right);
           }
           }
        }
        int height(Node<T>*root)
        {
            if (root == NULL)
            {
              return 0;
            }
            else{
            //compute the height of each subtree
             int Rheight = height(root->right);
             int Lheight = height(root->left);
            //by using the larger height of each subtree
            if (Lheight > Rheight)
            {
              return (1+Lheight);
            }
            else
            {
             return (1+Rheight);
            }
        }
      }
       void DeleteTree (Node<T>*temp)
        {
          if (temp == NULL) 
          return;
             DeleteTree(temp->left);
             DeleteTree(temp->right);
             delete temp;
        } 
        public:
        MyTree() { }

        MyTree(std::vector<T> elements)
        {
         sort (elements.begin(),elements.end());
         constructor (elements,0,elements.size()-1);
        }
        void insert(T key)
        {
          root = insert_priv(root,key);
        }
        void insert(const Node<T> node)
        {
          root = insert_priv(root,node->data);
        }
        const Node<T>* search(T key)
        {
          return search_priv(root,key);
        }
        const Node<T>* delete_node(T key)
        {
           return Delete_node(root,key);  
        }
        const Node<T>* delete_node(const Node<T> node)
        {
           return Delete_node(root,node->data);
        }
        bool isBST()
        {
          vector<T> v;
          v = inorder_rec();
            return is_sorted(v.begin(),v.end());
        }
        //left->root->right
        std::vector<T> inorder_rec() 
        { 
          vector <T> Inorder_rec;
          inorder_rec_priv(root,Inorder_rec);
          return Inorder_rec;
        }
        //root->left->right
        std::vector<T> preorder_rec()
        { 
          vector <T> Preorder_rec;
          preorder_rec_priv(root,Preorder_rec);
          return Preorder_rec;
        }
        //left->right->root
        std::vector<T> postorder_rec()
        {
          vector <T> Postorder_rec;
          postorder_rec_priv(root,Postorder_rec);
          return Postorder_rec;  
        }
        //left->root->right 
        std::vector<T> inorder_it()
        {  
          vector <T> Inorder_it;
          inorder_it_priv(root,Inorder_it);
          return Inorder_it;
        }
        //root->left->right 
        std::vector<T> preorder_it()
        {  
          vector <T> Preorder_it;
          preorder_it_priv(root,Preorder_it);
          return Preorder_it;
        }
        //left->right->root 
        std::vector<T> postorder_it()
        {
          vector <T> Postorder_it ;
          postorder_it_priv(root,Postorder_it);
          return Postorder_it;
        }
        // level by level  
        std::vector<T> breadth_traversal()
        {  
          vector <T> Breadth_traversal;
          breadth_traversal_priv(root,Breadth_traversal);
          return Breadth_traversal;
        }
        int get_size()
        {
         vector <T> v = inorder_rec();
         return v.size();
        }
        int get_height()
        {
          return (height(root)-1);    
        }
        void clear()
        {
          DeleteTree(root);
          root=nullptr;
        }
        ~MyTree()
        {
          clear();
        }
};
#endif

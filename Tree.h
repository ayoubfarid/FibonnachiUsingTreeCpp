//
// Created by farid on 19/12/22.
//
#include <iostream>

#ifndef TREECPP_TREE_H
#define TREECPP_TREE_H

using  namespace std;
//declare the node structure
template<class T>
 struct Noeud{
     //the data holding
    T data;
    //left node
    struct Noeud *left;
    //right node
    struct Noeud *right;
    //constructur with parameters
    explicit Noeud(T value){
        data=value;
        left= nullptr;
        right=nullptr;

    }
    //overriding the operator of output
      friend ostream& operator<<(ostream & out,Noeud<T> *nd)
     {
         out << " ("<< nd->data.first <<","<< nd->data.second<<")";// output -> ( key , value )
         return  out;
     }

};
template<class T>
        // define the tree class
class Tree {
public:
    //the root element of the tree
    Noeud<T>* root;
    //the default constructur
    Tree();
    //insert a value to the tree
    Noeud<T>* insert(Noeud<T>* root,T data);
    //show the tree on an ascendant way
    void show(Noeud<T>* root);
    //search the fibonachi of the key given
    long double searchFibOfValue(long double key,Noeud<T>* root);
    //test if the pair with the given key already inseted
    bool isKeyInserted(long double key,Noeud<T>* root);
    //show the tree horizontally
    void showHorizontal(Noeud<T> *node, long double Niv);

};


#endif //TREECPP_TREE_H

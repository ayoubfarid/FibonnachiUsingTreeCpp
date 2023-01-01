//
// Created by farid on 19/12/22.
//

#include "Tree.h"

using namespace std;
template<class T>
Tree<T>::Tree() {
    root= nullptr;
};
template<class T>
// insert the given data on the tree
 Noeud<T>* Tree<T>::insert(Noeud<T>* root,T data) {

    if (root==NULL) {
        root=new Noeud(data);

    }else if(data>root->data)
        root->right=insert(root->right,data);
    else
        root->left=insert(root->left,data);
     return root;
 }

template<class T>
//to show tree in ascendant order
 void Tree<T>::show(Noeud<T>* root){

     if (root){
         show(root->left);
         cout<<"\t"<<root;
         show(root->right);
     }

}

template<class T>
//to show tree horizontally
void Tree<T>::showHorizontal(Noeud<T> *node, long double Niv)
{
    long double esp;
    if (node)
    {
        showHorizontal(node->right, Niv + 1);
        cout<<endl;
        for (esp = 0; esp < Niv; esp++)
            cout<<"\t";
        cout << node;
        showHorizontal(node->left, Niv + 1);
    }
}
//search for the fibonnachi of the key given in the tree
template<class T>
long double Tree<T>::searchFibOfValue(long double key,Noeud<T>* root){
    if (root)
    {
        if (root->data.first>key)
            return  searchFibOfValue(key,root->left);
        else if(root->data.first<key)
             return searchFibOfValue(key,root->right);
        else
            return root->data.second;
    }
    return -1;

}
template<class T>
//the fonction return if the key already inserted on a node tree
bool Tree<T>::isKeyInserted(long double key,Noeud<T>* root){
    if (root)
    {
        if (root->data.first>key)
            return  isKeyInserted(key,root->left);
        else if(root->data.first<key)
            return isKeyInserted(key,root->right);
        else
            return true;
    }
    return false;
}
template<class T>
//function to calculate fibonachi using a tree
long double  fibonnachi(long double value,Tree<T> *tree){
    //if the value already inserted return the value fibonachi stocked at node
    if(tree->isKeyInserted(value,tree->root))
        return tree->searchFibOfValue(value,tree->root);
    //if the value equal to 0 return 0;
    if(value==0) {
        return  0;
    }
    //if the value equal to 1 return 1;
    if(value==1) {
        return  1;
    }
    //otherwise calculate the fibonachi of the key given and inserted to the tree and return his value
    tree->root=tree->insert(tree->root,make_pair(value,fibonnachi(value-1,tree)+fibonnachi(value-2,tree)));
    return tree->searchFibOfValue(value,tree->root);
}

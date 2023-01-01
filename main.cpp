#include <iostream>
#include "Tree.cpp"

int main() {
    //main of test
     cout.precision(0);
    cout << fixed << endl;
    //declare an empty tree and the node stock pair values (key,value)
    auto *tFib=new Tree<pair<long double , long double >>();
    long double  val=0;
    cout<<"\t *************************** Main test fibonnachi ***************************"<<endl;
    cout<<"\t tapez valeur:";
    cin>>val;
    //show and calculate the fibonnachi of the value given as input
    cout<<"\t"<<" the fibonnachi of "<<val<<" is "<<fibonnachi(val,tFib)<<endl;
    cout<<"\t *************************** show the tree horizontally ***************************";
    //show tree horizontally
    tFib->showHorizontal(tFib->root,0);

    return 0;
}

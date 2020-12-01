#include<bits/stdc++.h>
#include "Cola.h"
#define deb cout<<"deb"<<endl; 
using namespace std;
int main(){
    myqueue *x = new myqueue();
    x->push(5);
    cout<<x->front()<<endl;
    x->pop();
    if(x->empty())cout<<"yes"<<endl;
    for(int i=0;i<7;i++)x->push(i);
    while(!x->empty()){
        cout<<x->front()<<endl;
        x->pop();
    }
    x->push(66);
    cout<<x->front()<<endl;
    return 0;
}
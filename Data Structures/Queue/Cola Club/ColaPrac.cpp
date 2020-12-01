#include<bits/stdc++.h>
#include "Cola.h"

using namespace std;

int main(){
    myqueue *x = new myqueue();

    x->push(5);

    cout<<"\n\nel elemento hasta el frente es: "<<x->front()<<endl;

    x->pop();

    if(x->empty())
        cout<<"la cola esta vacia"<<endl;

    for(int i=0;i<7;i++)
        x->push(i);
    
    cout<<"el size es: "<<x->size()<<endl;

    while(!x->empty()){
        cout<<x->front()<<endl;
        x->pop();
    }
    
    cout<<"el size es: "<<x->size()<<endl;

    x->push(66);
    
    cout<<x->front()<<endl;
    
    return 0;
}
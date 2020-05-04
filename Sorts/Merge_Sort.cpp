#include <bits/stdc++.h>
#include "RanVec.h"
#define vi vector<int>
using namespace std;
vi Mix(vi a1,vi a2){
    vi r;
    while(a1.size() or a2.size()){
        if(a1.empty()){
            r.push_back(a2.at(0));
            a2.erase(a2.begin());
        }else if(a2.empty()){
            r.push_back(a1.at(0));
            a1.erase(a1.begin());
        }else if(a2.at(0)<a1.at(0)){
            r.push_back(a2.at(0));
            a2.erase(a2.begin());
        }else{
            r.push_back(a1.at(0));
            a1.erase(a1.begin());
        }
    }
    return r;
}
vi MergeSort(vi ar){
    int s=ar.size();
    if(s<2)return ar;
    vi a1,a2;
    a1.insert(a1.begin(),ar.begin(),ar.begin()+s/2);
    a2.insert(a2.begin(),ar.begin()+s/2,ar.end());
    return Mix(MergeSort(a1),MergeSort(a2));
}
int main(){
    vi a=GetRanVec();
    cout<<"Original array: ";
    PrintVec(a);
    cout<<"Array sorted: ";
    PrintVec(MergeSort(a));
    return 0;
}

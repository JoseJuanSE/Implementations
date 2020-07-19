#include<bits/stdc++.h>
#include "RanVec.h"
#define vi vector<int>
using namespace std;
vi a,L,D;
//optimal merge sort O(NlogN)

void mix(int ini,int mid,int fin){
    int szi=mid-ini+1;
    int szd=fin-mid;
    L.resize(szi);
    D.resize(szd);
    for(int i=0;i<szi;i++)
        L[i]=a[i+ini];
    for(int i=0;i<szd;i++)
        D[i]=a[i+mid+1];
    int j=0,k=0,i;
    for(i=ini;i<=fin;i++){
        if(L[j]<D[k] and j<szi){
            a[i]=L[j];
            j++;
        }
        else if(D[k]<=L[j] and k<szd){
            a[i]=D[k];
            k++;
        }
        if(j==szi or k==szd)break;
    }
    i++;
    while(j<szi){
        a[i]=L[j];
        j++;i++;
    }
    while(k<szd){
        a[i]=D[k];
        k++;i++;
    }
}
void merge_sort(int ini,int fin){
    if(ini>=fin)return;
    merge_sort(ini,(ini+fin)/2);
    merge_sort((ini+fin)/2+1,fin);  
    mix(ini,(ini+fin)/2,fin);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    a=GetRanVec();
    merge_sort(0,a.size()-1);
    PrintVec(a);
}
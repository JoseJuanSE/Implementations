#include<bits/stdc++.h>
#include "RanVec.h"
using namespace std;
//Receives any vector, and return it sorted.
//Algorithm Bubble_sort, complex O(n^2)  
void ImpVec(vector<int> in){
	for(int i=0;i<in.size();i++)
		cout<<in[i]<<" ";
	cout<<endl;
}
vector<int> Bubble_Sort(vector<int> n){	
	for(int i=n.size()-1;i>0;i--)
		for(int j=0;j<i;j++)
			if(n[j]>n[j+1])
				swap(n[j],n[j+1]);
	return n;
}
int main(){
	vector<int> n=GetRanVec();
	cout<<"Before Sort"<<endl;
	ImpVec(n);
	n=Bubble_Sort(n);
	cout<<"After Sort"<<endl;
	ImpVec(n);
}

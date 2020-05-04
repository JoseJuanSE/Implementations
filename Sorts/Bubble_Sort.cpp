#include<bits/stdc++.h>
#define vi vector<int>
#include "RanVec.h"
using namespace std;
//Receives any vector, and return it sorted.
//Algorithm Bubble_sort, complex O(n^2)  
vi Bubble_Sort(vi n){	
	for(int i=n.size()-1;i>0;i--)
		for(int j=0;j<i;j++)
			if(n[j]>n[j+1])
				swap(n[j],n[j+1]);
	return n;
}
int main(){
	vi n=GetRanVec();
	cout<<"Before Sort"<<endl;
	PrintVec(n);
	cout<<"After Sort"<<endl;
	PrintVec(Bubble_Sort(n));
}

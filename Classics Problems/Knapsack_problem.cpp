#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >a;
//dp table is full of zeros
int n,s,dp[1002][1002];
int f(int x,int b){
	//base solution
	if(x>=n or b<=0)return 0;
	//if we calculate this before, we just return the answer (value diferente of 0)
	if(dp[x][b])return dp[x][b];
	//calculate de answer for x (position) and b(empty space in knapsack)
	//we get max between take it or not and element, this gonna calculate all the
	//posible combinations, with dp we won't calculate what is already calculated.
	return dp[x][b]=max(f(x+1,b),b-a[x].second>=0?f(x+1,b-a[x].second)+a[x].first:0);
}
int main(){
	//fast scan and print
	ios_base::sync_with_stdio(0);cin.tie(0);
	//we obtain quantity of elements and size of knapsack 
	cin>>n>>s;
	a.resize(n);
	//we get value of elements
	for(int i=0;i<n;i++)
		cin>>a[i].first;
	//we get size of elements
	for(int i=0;i<n;i++)
		cin>>a[i].second;
	//print answer
	cout<<f(0,s);			
	return 0;
}

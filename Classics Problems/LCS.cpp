#include<bits/stdc++.h> 
using namespace std;
string a,b;
int dp[105][105];
pair<int,int> path[105][105];
int lcs(int i,int j){
	if(i==a.size() or j==b.size()){
		path[i][j] = {-1,-1};
		return 0;
	}
	if(dp[i][j]!=-1)return dp[i][j];
	if(a[i]==b[j]){
		path[i][j] = {i+1,j+1};
		return dp[i][j]=lcs(i+1,j+1)+1;
	}
	int op1 = lcs(i+1,j);
	int op2 = lcs(i,j+1);
	if(op1>op2)
		path[i][j] = {i+1,j};
	else
		path[i][j] = {i,j+1};
	return dp[i][j]=max(op1,op2);
}
string get_path(){
	string ans = "";
	int i=0,j=0;
	while(i!=-1 and j!=-1){
		if(a[i]==b[j])
			ans += a[i];
		tie(i,j) = path[i][j];
	}
	return ans;
}
int main(){
	memset(dp,-1,sizeof dp);
	cin>>a>>b;
	cout<<lcs(0,0)<<" "<<get_path()<<endl;
	return 0;
}
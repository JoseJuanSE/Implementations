//Problem: https://practice.geeksforgeeks.org/problems/word-boggle/0
#include <bits/stdc++.h>
using namespace std;

vector< vector< char > > boggle;
int a,b,t,n;

unordered_map<int,unordered_map<int,bool> >vis;
string current;

bool val(int i,int j,int index){
    if(i<0 or i>=a)
        return 0;
    if(j<0 or j>=b)
        return 0;
    if(index>=current.size())
        return 0;
    if(current[index]!=boggle[i][j])
            return 0;
    return true and !vis[i][j];
}
bool dfs(int i,int j,int index){
    bool ans=0;
    if(val(i,j,index)){
        if(index==current.size()-1 and current[index]==boggle[i][j])
            return 1;
        vis[i][j]=true;
        for(int k=-1;k<2;k++)
            for(int l=-1;l<2;l++)
                ans= ans || dfs(i+k,j+l,index+1);
    }
    return ans;
}
bool maping;
unordered_map<char,vector<pair<int,int> > > pos;
bool isthere(string x){
    bool posssol;
    if(!maping){
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                pos[boggle[i][j]].push_back({i,j});
        maping=true;
    }
    current=x;
    if(!pos[x[0]].empty()){
        vector<pair<int,int> > actual= pos[x[0]];
            for(pair<int,int> p:actual){
                vis.clear();
                posssol=dfs(p.first,p.second,0);
                if(posssol)return 1;   
            }
    }
    return false;
}
void solve(){
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    cin>>a>>b;
    boggle.resize(a);
    for(int i=0;i<a;i++){
        boggle[i].resize(b);
        for(int j=0;j<b;j++)
            cin>>boggle[i][j];
    }
    set<string>sol;
    maping=0;
    for(string i:s)
        if(isthere(i))
            sol.insert(i);
    if(sol.empty())
        cout<<-1;
    else
        for(string i:sol)
            cout<<i<<" ";
    cout<<endl;
}
int main() {
	cin>>t;
	while(t--)
        solve();
	return 0;
}
//LeetCode problem: Generate parentheses
//link: https://leetcode.com/problems/generate-parentheses/
#include<bits/stdc++.h>
using namespace std;
vector<string> sol;
int tot;
bool is_valid(string x){
    int s=0;
    for(int i=0;i<x.size();i++){
        if(x[i]=='(')s++;
        else s--;
        if(s<0)return false;
    }
    return true;
}
void gen(int ope,int clo,string cur){
    if(ope==0 and clo==0 and is_valid(cur))
        sol.push_back(cur);
    if(ope>0)
        gen(ope-1,clo,cur+'(');
    if(clo>0)
        gen(ope,clo-1,cur+')');
}
//problem funtion:
vector<string> generateParenthesis(int n){
    sol.clear();
    tot=n;
    gen(n,n,"");
    return sol;
}
void print(vector<string> imp){
    for(int i=0;i<imp.size();i++)
        cout<<imp[i]<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<string> ans=generateParenthesis(n);
    print(ans);
    return 0;
}
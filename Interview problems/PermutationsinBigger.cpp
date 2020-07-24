#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int>per;
unordered_map<char,pair<int,bool> > sw;
int c;

/*
Problem: Given a smaller string s and a bigger string b, design a algorithm to find 
all the permutations of the shorther string within the longer one. Print how many there is it. 
*/

void update(int index,int sum,string s,string b){
    sw[b[index]].first+=sum;
    if(sw[b[index]].second==true){
        c--;
        sw[b[index]].second=false;
    }
    if(sw[b[index]].first==per[b[index]]){
        c++;
        sw[b[index]].second=true;
    }
}
//number of 
int nsbp(string s,string b){
    for(char i:s)
        per[i]++;
    //O(B) where B is b.size() solution
    int ans=0;
    for(int i=0;i<b.size();i++){
        update(i,1,s,b);
        if(i>=s.size())
            update(i-s.size(),-1,s,b);
        if(i>=s.size() and c==per.size())ans++;
    }
    return ans;
}
int main(){
    string x,y;
    cin>>x>>y;
    cout<<nsbp(x,y);
}
/*
    Example case:
    Input:
    abc 
    abbcbabcbabbabc
    Output:
    4
*/
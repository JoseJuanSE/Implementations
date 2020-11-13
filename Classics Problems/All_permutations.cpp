//having a set{empty,1,2,3,..,n} print all the subsets
#include<bits/stdc++.h>
using namespace std;
vector<int> s;
void ap(int a){
    if(a==0){
        for(int i:s)
            cout<<i<<" ";
        cout<<endl;
        return;
    }
    //not taking
    ap(a-1);
    //taking
    s.push_back(a);
    ap(a-1);
    s.pop_back();
}
int main(){
    int n;
    cin>>n;
    ap(n);
    return 0;
}
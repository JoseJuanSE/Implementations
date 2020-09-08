#include<bits/stdc++.h>
using namespace std;
/*
other solution using funtions already implement:
vector<vector<int>> permute(vector<int>& arre) {
    vector<vector<int> > ans;
    sort(begin(arre),end(arre));
    do{
        ans.push_back(arre);
    }while(next_permutation(begin(arre),end(arre)));
    return ans;
}*/
vector<vector<int> >  ans;

void solu(vector<int> tot,vector<int> sol){
    if(tot.size()==0)
    if(sol.size()>0){
        ans.push_back(sol);
        return;
    }
    for(int i=0;i<tot.size();i++){
        vector<int> auxtot=tot,auxsol=sol;
        auxsol.push_back(tot[i]);
        auxtot.erase(auxtot.begin()+i);
        solu(auxtot,auxsol);
    }
}
void permute(vector<int>  arre){
    ans.clear();
    vector<int> empty;
    empty.clear();
    solu(arre,empty);
}
void pritn(vector<vector<int> > a){
    for(vector<int> i:a){
        for(int j:i){
        cout<<j<<" ";
    }
    cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int>arre = {1,2,3,4};
    permute(arre);
    pritn(ans);
    return 0;
}

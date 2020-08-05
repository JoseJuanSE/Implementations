#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > graph;
int nv,ed;
void readdata(){
    cout<<"\nNumber of vertex: ";
    cin>>nv;
    cout<<"\nNumber of edges: ";
    cin>>ed;
    graph.resize(nv+2);
    while(ed--){
        cout<<"from: ";
        int f,t;
        cin>>f;
        cout<<"to: ";
        cin>>t;
        graph[f].push_back(t);
        graph[t].push_back(f);
    }
}
int BFS(int a,int b){
    queue<pair<int,int> >cola;
    vector<bool>vis(nv+2,false);
    cola.push({a,0});
    while(!cola.empty()){
        pair<int,int> cur=cola.front();
        if(cur.first==b)return cur.second;
        cola.pop();
        vis[cur.first]=true;
        for(int i : graph[cur.first]){
            if(!vis[i])
                cola.push({i,cur.second+1});
        }
    }
    return -1;
}
int main(){
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    readdata();
    int from,to;
    cin>>from>>to;
    cout<<"Minimum number of steps to arrive from: "<<from<<" to: "<<to<<" = "<<BFS(from,to);
    return 0;
}
/*
case:
input:
7 9

1 4
1 2
2 3
4 3
4 6
3 5
6 5
5 7
1 7

1 7
output:
1
*/
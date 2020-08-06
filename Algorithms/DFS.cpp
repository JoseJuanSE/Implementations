#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > graph;
vector<bool>vis;
int nv,ed;
void readdata(){
    cout<<"\nNumber of vertex: ";
    cin>>nv;
    cout<<"\nNumber of edges: ";
    cin>>ed;
    graph.resize(nv+2);
    vis.assign(nv+2,false);
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
/* A DFS IS AN BFS BUT USING A STACK
bool DFS(int a,int b){
    stack<int>cola;
    vector<bool>vis(nv+2,false);
    cola.push(a); //starting state
    while(!cola.empty()){
        int cur=cola.top();
        if(curt==b)return true;
        cola.pop();
        vis[cur]=true;
        for(int i : graph[cur]){
            if(!vis[i])
                cola.push(i);
        }
    }
    return 0;
}*/
int to;
bool DFS(int curr){
    vis[curr]=true;
    if(curr==to)
        return 1;
    for(int i:graph[curr])
        if(!vis[i] and DFS(i)) return 1;
    return 0;
}
int main(){
    readdata();
    int from;
    cin>>from>>to;
    cout<<"Is There a path to get to: "<<to<<" from: "<<from<<"?: ";
    string x=DFS(from)?"YES, it does":"No, it doesn't";
    cout<<x;
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
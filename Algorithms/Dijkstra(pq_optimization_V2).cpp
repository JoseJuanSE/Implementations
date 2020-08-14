#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > graph;
//first position is node number, second cost
vector< pair< int, bool > > finalv;
//if false -> temparal, true -> final
int ini;
void readgraph(){
    int nv,ed,f,t,v;
    //read number of vertex
    cin>>nv;
    finalv.assign(nv+2,{INT_MAX,false});
    //reading number of edges
    cin>>ed;
    graph.resize(nv+2);
    //read edges
    while(ed--){
        cin>>f>>t>>v;
        graph[f].push_back(make_pair(t,v));
        graph[t].push_back(make_pair(f,v));
    }
}

void dijkstra(int a){
    priority_queue<pair<int,int> > pq;
    // first value of pair in pq will be cost
    pq.push(make_pair(0,a));
    finalv[a].first=0;
    while(!pq.empty()){
        pair<int,int> curr=pq.top();
        pq.pop();
        int currva= -1*curr.first;
        int currnode=curr.second;
        finalv[currnode].second=true;
        for(auto node:graph[currnode]){
            if(!finalv[node.first].second){
                if(currva+node.second<finalv[node.first].first){
                    finalv[node.first].first=currva+node.second;
                    pq.push({-1*(currva+node.second),node.first});
                }
            }
        }
    }
}
vector<int> findpath(int a,int b){
    vector<int> ans;
    ans.push_back(b);
    int currnode=b;
    int currva = finalv[b].first;
    while(currnode!=a){
        for(auto node : graph[currnode]){
            if(currva-node.second==finalv[node.first].first){
                ans.push_back(node.first);
                currnode = node.first;
                currva = finalv[currnode].first;
            }
        }
    }
    return ans;
}
void print(vector<int> ans){
    reverse(ans.begin(),ans.end());
    for(int i : ans)
        cout<<i<<" ";
}
int main(){
    //freopen("input.txt","r",stdin);
    readgraph();
    //source
    cin>>ini;
    dijkstra(ini);
    //minimum cost to anynode from source
    for(int i=0;i<finalv.size()-2;i++)
        cout<<finalv[i].first<<" ";
    cout<<endl;
    //find path example
    vector<int>path = findpath(ini,6);
    print(path);
    return 0;
}
//Case: 
/*
input:
7
11
0 2 2  
0 1 6 
1 3 2 
2 3 5
3 5 2
2 5 7
5 6 1
3 6 6
3 4 7
4 6 6
1 4 9
0
output:
//all the shortest numebers per each node
0 6 2 7 14 9 10
//path to go from 0 to 2
0 2
//path to go from 0 to 6
0 2 3 5 6

*/
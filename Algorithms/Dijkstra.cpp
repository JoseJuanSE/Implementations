#include<bits/stdc++.h>
#define infty int(1e15)
using namespace std;
//num of graph vertex
int n;

//weighted graph first-> graph, second-> weight
vector<pair <int,int> > graph[1000];

//shorthest paths vector
vector<int>sp;
//paths
vector<int>p;
//visited array
vector<bool>vis;
void getnodes(){
    int e,x,y,w;
    cin>>n>>e;
    while(e--){
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    //cout<<"hola"<<endl;
}
//build shorthest paths
void dijkstra(){
    sp[0]=0;
    for(int i=0;i<n;i++){
        //buscamos mas pequeño de todos, que no este visitado
        int mini=int(1e14),in;    
        for(int j=0;j<n;j++){
            if(!vis[j]){
                if(sp[j]<mini){
                    mini=sp[j];
                    in=j;
                }
            }
        }
        //si es infinito, ya no hay mas que buscar, pues este nodo no tiene conexion
        if(sp[in]==infty)break;
        //marcamos visitado el mas pequeño
        vis[in]=true;
        //construimos todos lo caminos disponibles a partir de este
        for(auto nodo : graph[in]){
            int y=nodo.first;
            int w=nodo.second;
            if(sp[y]>sp[in]+w){
                sp[y]=sp[in]+w;
                p[y]=in;
            }
        }
    }
    int gg=0;
    for(auto val : sp){
        if(gg++==n)break;
        cout<<val<<" ";
    }
    cout<<endl;
}
void getpath(int x){
    vector<int>res;
    res.push_back(x);
    while(x!=0){
        x=p[x];
        res.push_back(x);
    }
    reverse(res.begin(),res.end());
    for(auto i : res){
        cout<<i<<" ";
    }
}
//source node always is going to be in zero node.

//La complejidad de esta implementacion es O(n^2) donde n es el numero de nodos
int main(){
    //iniciamos la distancia minima a cada nodo en infinio
    sp.assign(1000,infty);
    //vector de nodos visitados
    vis.assign(1000,0);
    //vector que indica su padre (el nodo mas optimo para llegar a el)
    p.resize(1000);
    //lee el grafo
    getnodes();
    //construye dijkstra
    dijkstra();
    //nos imprime el camino mas barato al nodo 6
    getpath(6);
    return 0;
}

#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(v) v.begin(), v.end()
#define deb cout<<"HOLA\n";
#define UNIQUE(v) (v).resize(unique(ALL(v))-(v).begin())
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define bs(v,f) binary_search(v.begin(),v.end(),f)
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
//max heap
struct pq{
	int size,heap[100005];
	pq(){
		size=0;
	}
	int pa(int x){
		return x>>1;
	}	
	int iz(int x){
		return x<<1;
	}	
	int de(int x){
		return (x<<1)+1;
	}	
	void push(int x){
		size++;
		heap[size]=x;
		int ac=size;
		while(pa(ac) and heap[pa(ac)]<heap[ac]){
			swap(heap[pa(ac)],heap[ac]);
			ac=pa(ac);
		}
	}
	bool empty(){
		return  size;
	}
	void pop(){
		if(size==0){
			cout<<"COLA VACIA\n";
		}
		heap[1]=heap[size];
		size--;
		int ac=1;
		while(ac<=size){
			int izq=iz(ac),der=de(ac),l=ac;
			if(izq<=size and heap[l]<heap[izq])
				l=izq;
			if(der<=size and heap[l]<heap[der])
				l=der;
			if(ac!=l){
				swap(heap[l],heap[ac]);
				ac=l;
			}else break;
		}
	}
	int maxi(){
		return heap[1];
	}
}cola;
void solve(){
	int n,k;
	cin>>n>>k;
	forn(i,n){
		int x;
		cin>>x;
		cola.push(-1*x);
		if(cola.size==k+1){
			cola.pop();
		}	
	}
	stack<int>f;
	forn(i,k){
		f.push(-1*cola.maxi());
		cola.pop();
	}
	while(!f.empty()){
		cout<<f.top()<<" ";
		f.pop();
	}
	cout<<endl;
}
int main(){
	fast
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
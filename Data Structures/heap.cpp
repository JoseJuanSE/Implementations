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
			cout<<"Empty queue\n";
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

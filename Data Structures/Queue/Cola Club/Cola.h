struct nodo{
    int val;
    nodo *next;
    nodo (int x){
        val = x;
        next = nullptr;
    }
};
struct myqueue{
    nodo *ini,*fin;
    int s;
    myqueue(){
        ini = fin = nullptr;
        s = 0;
    }
    bool empty(){return fin==nullptr;}
    void push(int x){
        s++;
        if(fin == nullptr){
            ini = fin = new nodo(x);
            return ;
        }
        fin->next = new nodo(x);
        fin = fin->next;
        fin->next = nullptr;
    }
    void pop(){
        nodo *t =ini;
        if(ini == fin)
            ini = fin = nullptr;
        else 
            ini=ini->next;
        s--;
        delete(t);
    }
    int front(){return ini->val;}
    int size(){return s;}
};
//impletar estatica
//implementar en dimica
//2, 3
//canguros de omega up
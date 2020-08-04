#include <iostream>
using namespace std;
typedef struct trienode{
    trienode *children[28];
    bool is_word;
}*trie;
trie GetNode(){
    trie newtrie = (trie)malloc(sizeof(trienode));
    newtrie->is_word=false;
    for(int i=0;i<28;i++)
        newtrie->children[i]=NULL;
    return newtrie;
}
void insert(string s,trie root){
    trie cur=root;
    for(int i=0;i<s.size();i++){
        int index=int(s[i]-'a');
        if(!cur->children[index])
            cur->children[index] = GetNode();
        cur=cur->children[index];
    }
    cur->is_word=true;
}
int isthere(string s,trie root){
    trie cur=root;
    for(int i=0;i<s.size();i++){
        int index=int(s[i]-'a');
        if(!cur->children[index])
            return 0; 
        cur=cur->children[index];
    }
    if(cur->is_word)return 1;
    return 0;
}
int main() {
    int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        trie my_trie=GetNode();
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            insert(s,my_trie);
        }   
        string look;
        cin>>look;
        cout<<isthere(look,my_trie)<<endl;
	}
	return 0;
}
/*
test case:
input:
2
8
the a there answer any by bye their
the
3
cey vpj hvf
gxp

output:
1
0
*/

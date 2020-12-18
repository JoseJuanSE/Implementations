#include<bits/stdc++.h>
using namespace std;
int steps = 0;
int hanoi(int disks,int start,int end){
    if(disks==0)return 0;
    int other = 6 - start - end;
    hanoi(disks-1,start,other);
    cout<<start<<" "<<end<<endl;
    steps++;
    hanoi(disks-1,other,end);
    return steps;
}

int main(){
    int n;
    //number of disks
    cin>>n;
    //minimun number of movs
    cout<<hanoi(n,1,3);
}
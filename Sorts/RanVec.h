//We will use this library in order to 
//generate fast test to our sorts
#include<time.h> 
using namespace std;
int random(){
	return rand()%1000;
}
vector<int> GetRanVec(){
	vector<int> a(25);
	srand(time( NULL ));
	for(int i=0;i<25;i++)
		a[i]=random();
	return a;
}

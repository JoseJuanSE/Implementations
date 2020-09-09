#include<bits/stdc++.h>
using namespace std;
class person{
    private: 
        string name;
        int age;
    public:
        person(int,string);
        void see_name();
        void see_age();
        
};
person::person(int edad,string nom){{
    age=edad;
    name=nom;
}

}
void person::see_name(){
    cout<<"hi!, my name is "<<name<<endl;
}
void person::see_age(){
    cout<<"I'm "<<age<<" years old.\n";
}
int main(){
    person p1 = person(16,"Jose");
    p1.see_name();
    p1.see_age();
    person p2(18,"Vero");
    p2.see_name();
    p2.see_age();
    return 0;
}

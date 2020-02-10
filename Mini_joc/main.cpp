#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
class joc
{
    static int a;
    public:
    joc(){
    a=rand()%13+1;}
    friend bool operator >(joc j,int a);
    friend bool operator <(joc j,int a);
    int get_a(){return (*this).a;}
     void roll(){
    a=rand()%13+1;}
};
int joc::a;
bool operator >(joc j,int a)
{
    if(j.a==a){cout<<"A picat acelasi numar"<<endl;return false;}
    if(j.a>a)return true;
    else return false;
}
bool operator <(joc j,int a)
{
    if(j.a==a){cout<<"A picat acelasi numar"<<endl;return false;}
    if(j.a<a)return true;
    else return false;
}
int main()
{
    srand(time(NULL));
    int streak=0,cifra;
    char n;
    joc j;
    while(1){
    cout<<"Numarul curent este: "<<j.get_a()<<endl<<"Alegeti daca urmatoru nr. este: '<' pentru mai mic, sau '>' pentru mai mare"<<endl;
    cout<<"Introduceti 0 pentru a iesi"<<endl;
    cout<<"Streakul este: "<<streak<<endl;
    cin>>n;
    switch (n)
    {
    case '>':
        cifra=j.get_a();
        j.roll();
        if(j>cifra){streak++;}
        else streak=0;
        break;
    case '<':
        cifra=j.get_a();
        j.roll();
        if(j<cifra){streak++;}
        else streak=0;
        break;
    case '0':
        return 0;
        break;
    }
    }
}

#include<iostream>
using namespace std;
void printHourGlass(int a,int b){
    if(a < 1) return;
    for(int i=0 ; i< b ; i++) cout << ' ';
    for(int i=0 ; i< a ; i++) cout << "* ";
    for(int i=0 ; i< b ; i++) cout << ' ';
    cout << '\n';
    printHourGlass(a-2,b+2);
    for(int i=0 ; i< b ; i++) cout << ' ';
    for(int i=0 ; i< a ; i++) cout << "* ";
    for(int i=0 ; i< b ; i++) cout << ' ';
    cout << '\n';
}
int main(){
    printHourGlass(7,0);
    return 0;
}
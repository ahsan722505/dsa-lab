#include<iostream>
using namespace std;
void printHourGlass(int n , int b, int n1){
    if(n <= 0) return;
    else if(n1 > 0){
        cout << "* ";
        printHourGlass(n,b,n1-1);
    }
    else{
        cout << '\n';
        printHourGlass(n-2,b,n-2);
    }
    

}
int main(){
    printHourGlass(5,0,5);
    return 0;
}
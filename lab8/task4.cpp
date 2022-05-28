#include<iostream>
using namespace std;
void convert(int n,int p){
    int rem;
    if(n >=1){
        rem=n % p;
        convert((n/p),p);
        cout << rem;
    }
}
int main(){
    convert(5,7);
    return 0;
}
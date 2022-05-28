#include<iostream>
using namespace std;
    int findNum(int num, int initial, int count){
        if(num > 0){
            return findNum(num - 1 ,initial + count, count + 1 );
        }else{
            return initial;
        }
    }
int main(){
    cout << findNum(5,0,1);
    return 0;
}
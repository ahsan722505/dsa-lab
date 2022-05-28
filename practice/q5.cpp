#include<iostream>
using namespace std;
bool onlyDigits(char* str,int size){
    for(int i=0 ; i< size ; i++){
        if(str[i] < 48 || str[i] > 57) return false;
    }
    return true;
}
int main(){
    char str[]="12345";
    if(onlyDigits(str,5)){
        cout << "yes only digits\n";
    }else{
        cout << "not only digits\n";
    }
    return 0;
}
// How do you check if a string contains only digits?
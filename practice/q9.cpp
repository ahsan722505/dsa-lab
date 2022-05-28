#include<iostream>
#include<cmath>
using namespace std;
int findLength(char *str){
    int length=0;
    for(int i=0 ; str[i] != '\0' ; i++) length++;
    return length;
}
int convertStringToInt(char *str){
    int length=findLength(str);
    int value=0;
    for(int i=0,j=length-1 ; i< length ;i++,j--){
        value+= ((str[i] - 48)* pow(10,j));
    }
    return value;
}
int main(){
    char str[]="100";
    int value=convertStringToInt(str);
    cout << value << '\n';
    return 0;
}
// How do you convert a given String into int like the atoi()?
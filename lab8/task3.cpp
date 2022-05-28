#include<iostream>
using namespace std;
void replace(char *s,const char from, const char to, int i){
    if(s[i] != '\0'){
        if(s[i] == from) s[i]=to;
        replace(s,from,to,i+1); 
    }
}
int main(){
    char str[]="ahsan";
    int i=0;
    replace(str,'a','j',i);
    cout << str << '\n';
    return 0;
}
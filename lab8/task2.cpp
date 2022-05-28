#include<iostream>
using namespace std;
int count_character(char *str,const char c,int i, int count){
    if(str[i] != '\0'){
        if(str[i] == c){
                return count_character(str,c,i+1,count + 1);
        } 
        else{
            return count_character(str,c,i+1,count);
        } 
    }else{
        return count;
    }
}
int main(){
    char str[]="yasirarar";
    int count=0;
    int i=0;
    cout << count_character(str,'r',i,count) << '\n';
    return 0;
}
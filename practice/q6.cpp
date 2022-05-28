#include<iostream>
using namespace std;
void toUpperCase(char *a){
    int x=32;
    for (int i=0; a[i]!='\0'; i++)
        a[i] = a[i] & ~x;
  
}
void count(char* str,int &vowels,int &cons){
    toUpperCase(str);
    for(int i=0 ; str[i] != '\0' ; i++){
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') vowels++;
        else cons++;
    }

}
int main(){
    char str[]="ahsan";
    int vowels=0,cons=0;
    count(str,vowels,cons);
    cout << "vowels: " << vowels << '\n';
    cout << "consonents: " << cons << '\n';
    return 0;
}
// How do you count a number of vowels and consonants in a given string?
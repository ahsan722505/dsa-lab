#include<iostream>
using namespace std;
void countOccurence(char* str,const char character,int &count){
    for(int i=0 ; str[i] != '\0' ; i++){
        if(str[i] == character) count++;
    }
}
int main(){
    char str[]="javeria";
    int count=0;
    countOccurence(str,'a',count);
    cout << count << '\n';
    return 0;
}
// How do you count the occurrence of a given character in a string?
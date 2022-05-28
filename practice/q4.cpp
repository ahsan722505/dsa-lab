#include<iostream>
using namespace std;
void swap(char *str,int first,int second){
    char temp=str[first];
    str[first]=str[second];
    str[second]=temp;
}
char* reverse(char *str, int start,int end){
    if(start == end || start > end) return str;
    swap(str,start,end);
    return reverse(str,start+1, end-1);
}
int main(){
    char str[]="javeria";
    int start=0,end=6;
    char *reversed=reverse(str,start,end);
    cout << reversed;

    return 0;
}
// How can a given string be reversed using recursion?
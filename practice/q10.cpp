#include<iostream>
using namespace std;
void swap(char *str,int first,int second){
    char temp=str[first];
    str[first]=str[second];
    str[second]=temp;
}
void reverse(char *str, int start,int end){
    if(start == end || start > end) return;
    swap(str,start,end);
    reverse(str,start+1, end-1);
}
void reverseWords(char *sentence){
    int start=0,end;
    for(int i=0 ; sentence[i] != '\0' ; i++){
        if(sentence[i+1] == ' ' || sentence[i+1] == '\0'){
            end=i;
            reverse(sentence,start,end);
            start=i+2;
        }
    }
}

int main(){
    char sentence[]="Hello my name is ahsan";
    reverseWords(sentence);
    cout << sentence << '\n';
    return 0;
}
// How do you reverse words in a given sentence without using any library method?
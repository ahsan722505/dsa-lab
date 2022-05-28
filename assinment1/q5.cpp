#include<iostream>
using namespace std;
void letters(char c){
    if(c == 'A'){
        cout << c;
        return;
    }
    letters(c-1);
    cout << c;
    letters(c-1);
}
int main(){
    char c='C';
    letters(c);
    return 0;
}
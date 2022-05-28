#include<iostream>
using namespace std;
void printFirstNonRepeatedCharacter(char* str){
    for(int i=0 ; str[i] != '\0' ; i++){
        bool rep=false;
        for(int j=0 ; str[j] !='\0' ; j++){
            if(i==j) continue;
            if(str[i] == str[j]){
                rep=true;
                break;    
            };
        }
        if(!rep){
            cout << str[i] << '\n';
            return;
        }
    }

}
int main(){
    char str[]="ahsan";
    printFirstNonRepeatedCharacter(str);
    return 0;
}
// How do you print the first non-repeated character from a string?
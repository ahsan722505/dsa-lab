#include<iostream>
using namespace std;
class AhsanString{
public:
    char* str;
    int length;
    AhsanString(const char* str){
        length=0;
        this->str=new char[100];
        int i;
        for( i=0 ; str[i] != '\0' ; i++){
            length++;
            this->str[i]=str[i];
        }
        this->str[i]='\0';
    }
    bool includes(char character){
        for(int i=0 ; i<length ; i++){
            if(str[i] == character) return true;
        }
        return false;
    }

};
bool areAnagrams(const char* str1,const char* str2){
    AhsanString stri1(str1),stri2(str2);
    if(stri1.length != stri2.length) return false;
    // now checking one to one correspondence
    for(int i=0 ; i< stri1.length ; i++){
        if(!stri2.includes(stri1.str[i])) return false;
    }
    return true;

}
int main(){
    if(areAnagrams("car" , "arc")){
        cout << "They are anagrams" << '\n';
    }else{
        cout << "They are not  anagrams" << '\n';
    }
    return 0;
}
// How do you check if two strings are anagrams of each other?
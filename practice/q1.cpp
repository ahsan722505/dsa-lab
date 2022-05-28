#include<iostream>
using namespace std;
class Arr{
    char *arr,noOfElements;
public:
    Arr(const int size ){
        noOfElements=0;
        arr=new char[size];
    }
    void push(char element){
        arr[noOfElements++]=element;
    }
    bool includes(char element){
        for(int i=0 ; i<noOfElements ; i++){
            if (arr[i] == element) return true;
        }
        return false;
    }
};

void printDuplicate(const char* str,const int n){
    Arr myArr(n);
    for(int i=0 ; i<n-1 ; i++){
        if(!myArr.includes(str[i])){
            for(int j=i+1 ; j< n ; j++){
                if(str[i] == str[j]){
                    myArr.push(str[i]);
                    cout << str[i] << '\n';
                    break;
                }
            }
        }
    }
    
}
int main(){
    printDuplicate("aahasann",8);
    return 0;
}
// How do you print duplicate characters from a string?
#include<iostream>
#include<cmath>
using namespace std;
template <class T>
class Stack{
    T *arr;
    int capacity,top;
public:
    Stack(int size){
        capacity=size;
        top=-1;
        arr=new T[capacity];
    }
    bool isFull(){
        return top == (capacity - 1);
    }
    bool isEmpty(){
        return top == -1;
    }
    void push(T val){
        if(!isFull()) arr[++top]=val;
        else{
            cout << "Stack is full\n";
        }
    }
    T pop(){
        if(!isEmpty()) return arr[top--];
        cout << "Stack is empty\n";
        return -1;
    }
    T seeTop(){
        if(!isEmpty()) return arr[top];
        cout << "Stack is empty\n";
        return -1;
    }
    int getCurrentSize(){
        return top+1;
    }

};
int main(){
    int number;
    cout << "Enter number: ";
    cin >> number;
    Stack<int> s1(100);
    Stack<int> s2(100);
    while(number){
        s1.push(number%10);
        number/=10;
    }
    int numLength=s1.getCurrentSize();
    int power=numLength-1;
    int result=0;
    for(int i=0 ; i< (numLength/3) ; i++){
        for(int  j=0 ; j<3 ; j++){
            s2.push(s1.pop());
        }
        for(int  k=0 ; k<3 ; k++){
            result+=(s2.pop()* pow(10,power--));
        }

    }
    while(s1.getCurrentSize()){
        result+=(s1.pop()* pow(10,power--));
    }
    cout << "Reverse is: " << result << '\n';
    return 0;
}
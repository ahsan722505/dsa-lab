#include<iostream>
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

};
bool isBalanced(char* str){
    Stack<char> s1(100);
    for(int i=0 ; str[i] !='\0' ; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            s1.push(str[i]);
            continue;
        }
        if(str[i] == ')'){
            if(s1.pop() == '(') continue;
            else return false;
        }
        if(str[i] == '}'){
            if(s1.pop() == '{') continue;
            else return false;
        }
        if(str[i] == ']'){
            if(s1.pop() == '[') continue;
            else return false;
        }
    }
    if(!s1.isEmpty()) return false;
    return true;
}
int main(){
    char str[]="({a+b}+c)";
    if(isBalanced(str)) cout << "Balanced\n";
    else cout << "not balanced\n";

    return 0;
}
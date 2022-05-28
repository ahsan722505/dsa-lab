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
int main(){
    int number;
    cin >> number;
    int num2=number;
    int numlength=0;
    Stack<int> s1(100);
    while(number){
        s1.push(number%10);
        numlength++;
        number=number/10;
    }
    for(int i=0 ; i<numlength ; i++,num2/=10){
        if(s1.pop() != num2%10){
            cout << "number is not palindrome\n";
            return 0;
        }
    }
    cout << "number is palindrome\n";



    return 0;
}
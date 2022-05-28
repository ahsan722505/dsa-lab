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
    Stack<int> s1(5);
    s1.pop();
    s1.push(3);
    s1.push(2);
    s1.push(1);
    cout << s1.seeTop() << '\n';
    s1.pop();
    cout << s1.seeTop() << '\n';
    s1.pop();
    cout << s1.seeTop() << '\n';
    s1.pop();
    cout << s1.seeTop() << '\n';

    return 0;
}
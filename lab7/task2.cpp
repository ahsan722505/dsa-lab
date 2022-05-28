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
        // if(!isEmpty()) return arr[top--];
        // cout << "Stack is empty\n";
        // return -1;
        if(!isEmpty()){
            int element=arr[0];
            for(int i=0 ; i< top ; i++){
                arr[i]=arr[i+1];
            }
            top--;
            return element;
        }
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
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << '\n';
    cout << s.pop() << '\n';
    cout << s.pop() << '\n';
    cout << s.pop() << '\n';
    return 0;
}
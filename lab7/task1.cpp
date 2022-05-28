#include<iostream>
using namespace std;
template <class T>
class Queue{
    T *arr;
    int rear,front,size;
public:
    Queue(int size){
        this->size=size;
        arr=new T[size];
        rear=-1;
        front=-1;
        
    }
    bool isEmpty(){
        return rear == -1 && front == -1;
    }
    bool isFull(){
        return (rear +1)%size == front;
    }
    void enque(T element){
        if(!isFull()){
            rear=(rear+1)%size;
            arr[rear]=element;
            if(front == -1) front=0;
        }else{
            cout << "Stack is full\n";
            
        }
        
    }
    T deque(){
        if(!isEmpty()){
            T element=arr[front];
            if(front == rear) front=rear=-1;
            else front=(front + 1)% size;
            return element;
        }else{
            cout << "Stack is empty\n";
            return -999;
        }

    }
    
};

int main(){
    Queue<int> q(5);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.enque(6);
    cout << q.deque() << '\n';
    q.enque(5);
    cout << q.deque() << '\n';
    cout << q.deque() << '\n';
    cout << q.deque() << '\n';
    cout << q.deque() << '\n';
    cout << q.deque() << '\n';

    
    // cout << q.deque() << '\n';
    // cout << q.deque() << '\n';
    // cout << q.deque() << '\n';
    // cout << q.deque() << '\n';
    return 0;
}

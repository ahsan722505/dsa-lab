#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data=data;
            this->next=0;
        }
};
class List{
public:
    Node *Head,*Tail;
    
        List(){
            Head=Tail=0;
        }
        bool isEmpty(){
            return Head == 0;
        }
        
        void addToTail(int e){
            if(Tail != 0){
                Tail->next=new Node(e);
                Tail=Tail->next;
            }
            else{
                Tail=Head=new Node(e);
            }
            
        }
        
        
        void DisplayReverse(Node *p){
            if(p->next == 0){
                cout << "Data= " << p->data << '\n';
                return;
            } 
            DisplayReverse(p->next);
            cout << "Data= " << p->data << '\n';
        }
};
int main(){
    List l;
    int nodes;
    int eachData;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    for(int i=0 ; i< nodes ; i++){
        cout << "Input data for node " << i+1  << " : ";
        cin >> eachData;
        l.addToTail(eachData);
    }
    cout << "Data entered in the list:\n";
    l.DisplayReverse(l.Head);


    return 0;
}
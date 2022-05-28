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
    Node *Head,*Tail;
    public:
        List(){
            Head=Tail=0;
        }
        bool isEmpty(){
            return Head == 0;
        }
        void addToHead(int e){
            Node *temp=new Node(e);
            temp->next=Head;
            Head=temp;
            if(Tail == 0) Tail=Head;
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
        void insertAtMiddle(int pos, int e){
            Node *temp=Head;
            for(int i=1 ; i< pos -1 ; i++) temp= temp->next;
            Node *n =new Node(e);
            n->next= temp->next;
            temp->next=n;
            cout << "Insertion completed successfully.\n";
        }
        
        
        void Display(){
            Node *p=Head;
            while(p != 0){
                cout << "Data = " <<  p->data << '\n';
                p=p->next;
            }
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
    l.Display();
    int e,pos;
    cout << "Input data to insert in the middle of the list : "; 
    cin >> e;
    cout << "Input the position to insert new node : ";
    cin >> pos;
    l.insertAtMiddle(pos,e);
    cout << "The new list are: ";
    l.Display();
    

    return 0;
}
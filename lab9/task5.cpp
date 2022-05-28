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
        int deleteFromHead(){
            if(!isEmpty()){
                int e=Head->data;
                Node *temp=Head;
                if(Head == Tail) Head=Tail=0;
                else Head=Head->next;
                delete temp;
                return e;
            }else{
                return -1;
            }

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
     cout << "Data of node 1 which is being deleted is : " << l.Head->data << '\n';
     l.deleteFromHead();
     cout << "Data, after deletion of first node :\n";
     l.Display();
    

    return 0;
}
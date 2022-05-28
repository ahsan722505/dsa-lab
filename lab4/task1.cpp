#include<iostream>
using namespace std;
class Collection{
    int *data;
    int size;
public:
    Collection(int size){
        this->size=size;
        if(size < 0){
            data=nullptr;
        }else{
            data=new int[size];
            for(int i=0 ; i< size ; i++) data[i]=0;

        }
    }
    Collection(int *data, int size){
        this->size=size;
        this->data=new int[size];
        for(int i=0 ; i< size ; i++) this->data[i]=data[i];

    }
    Collection( const Collection &c){
        size=c.size;
        data=new int[size];
        for(int i=0 ; i< size ; i++) data[i]=c.data[i];
    }
    int getSize(){
        return size;
    }
    friend ostream& operator << (ostream &out, Collection &c){
        for(int i=0 ; i<c.size ; i++){
            out << c.data[i] << ' ';
        }
        out << '\n';
        return out;
    }
    friend istream& operator >> (istream &in, Collection &c){
        cout << "Enter data: " << '\n';
        for(int i=0 ; i<c.size ; i++){
            in >> c.data[i];
        }
        return in;
    }
    void insertElement(int k, int index){
        if(index < 0 || index >= size){
            cout << "Index out of bound error" << '\n';
        }else if(data[index] != 0){
            cout << "Element already exists." << '\n';
        }else{
            data[index]=k;
        }

    }
    bool findElement(int k){
        for(int i=0 ; i<size ; i++){
            if(data[i] == k) return true;
        }
        return false;
    }
    void operator = (Collection &c){
        size=c.size;
        int *tempData=new int[size];
        for(int i=0 ; i<size ;i++) tempData[i]=c.data[i];
        delete []data;
        data=tempData;
    }
    Collection operator + (const Collection &c){
        if(c.size !=size){
            cout << "Addition not possible" << '\n';
            Collection res(-1);
            return res;
        }else{
            Collection res(size);
            for(int i=0 ; i<size ; i++){
                res.data[i]= data[i] + c.data[i];
            }
            return res;

        }

    }
    bool operator == (Collection &c){
        if(size != c.size) return false;
        for(int i=0 ; i<size ; i++){
            if(data[i] != c.data[i]) return false;
        }
        return true;
    }   

    ~Collection(){
        delete []data;
    }
};
int main(){
    // Collection c1(5);
    // cin >> c1;
    // cout << c1;
    // int data[]={1,2,3,4};
    // Collection c2(data,4);
    // cout << c2;
    // c2.insertElement(3,0);
    // Collection c3(5);
    // c3.insertElement(9,1);
    // cout << c3;
    // if(c3.findElement(9)){
    //     cout << "9 exists\n";
    // }else{
    //     cout << "9  dont exists\n";        
    // }
    // int data1[]={1,2,3,4};
    // int data2[]={22,15,52,33,45};
    // Collection c4(data1,4);
    // Collection c5(data2,5);
    // cout << c4;
    // cout << c5;
    // c4=c5;
    // cout << c4;
    int data1[]={1,2,3,4,5};
    int data2[]={22,15,52,33};
    Collection c6(data1,5);
    Collection c7(data2,5);
    Collection c8=c6+c7;
    cout << c8;
    // if(c6 == c7){
    //     cout << "equal\n";
    // }else{
    //     cout << " not equal\n";
    // }

    return 0;
}
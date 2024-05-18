#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    
    Node(int data = 0){
        this->data = data;
        next = NULL;
    }
    
};

class Stack{
    
public:
    Node * head;
    
    Stack(){
        head = NULL;
    }
    
    bool isEmpty(){
        return(head==NULL);
    }
    
    void Push(int value){
        
        if(isEmpty()){
            head = new Node(value);
        }
        else{
            Node * temp = new Node(value);
            temp->next = head;
            head = temp;
        }
    }
    
    void Pop(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = head->next;
            delete head;
            head = temp;
        }
    }
    
    void Print(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = head;
            while (temp!=NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
    
    void Reset(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = head;
            while (head!=NULL) {
                temp = head;
                head = head->next;
                delete temp;
            }
            delete head;
            head = NULL;
            cout << "Stack sifirlandi" << endl;
        }
    }
    
};

int main(){
    
    int sayi, secim;
    Stack s;
    
    while(1){
        
        cout << endl;
        cout << "1) Ekle" << endl;
        cout << "2) Cikar" << endl;
        cout << "3) Yazdir" << endl;
        cout << "4) Sifirla" << endl;
        cout << "0) Cikis" << endl;
        
        cout << "Secimin: "; cin >> secim;
        
        switch(secim){
                
            case 1: cout << "Sayi: "; cin >> sayi;
                s.Push(sayi);
                s.Print();
                break;
            case 2: s.Pop();
                s.Print();
                break;
            case 3: s.Print();
                break;
            case 4: s.Reset();
                break;
            case 0: cout << "Cikis yapiliyor..." << endl;
                return 0;
        }
        
    }
    
    
    return 0;
}

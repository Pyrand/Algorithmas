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

class Queue{
public:
    Node * head;
    Node * last;
    
    Queue(){
        head = NULL;
        last = NULL;
    }
    
    bool isEmpty(){
        return(head==NULL);
    }
    
    void enQueue(int value){
        
        if(isEmpty()){
            head = new Node(value);
            last = head;
        }
        else{
            last->next = new Node(value);
            last = last->next;
        }
    }
    
    void deQueue(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            if(head->next==NULL){
                delete head;
                head = last = NULL;
            }
            else{
                Node * temp = head->next;
                delete head;
                head = temp;
            }
        }
    }
    
    void reset(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = head;
            while(head!=NULL){
                temp = head;
                head = head->next;
                delete temp;
            }
            cout << "Liste resetlendi" << endl;
        }
    }
    
    void print(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = head;
            while(temp!=NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
    
    void first(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            cout << "Kuyruk basinda ki sayi: " << head->data << endl;
        }
    }
    
};


int main(){
    
    int secim, sayi;
    Queue q;
    
    while(1){
        
        cout << endl;
        cout << "Queue Yapisi" << endl;
        cout << "1) Ekle" << endl;
        cout << "2) Cikar" << endl;
        cout << "3) Sifirla" << endl;
        cout << "4) Ilk Eleman" << endl;
        cout << "5) Yazdir" << endl;
        cout << "Secim: "; cin >> secim;
        
        switch(secim){
                
            case 1: cout << "Sayi:"; cin >> sayi;
                q.enQueue(sayi);
                q.print();
                break;
            case 2: q.deQueue();
                q.print();
                break;
            case 3: q.reset();
                break;
            case 4: q.first();
                break;
            case 5: q.print();
                break;
            default: cout << "Yanlis tuslama..." << endl;
                return 0;
        }
    }
    
    
    return 0;
}

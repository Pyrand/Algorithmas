#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node * prev;
    
    Node(int data = 0){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
    
};

class List{
public:
    Node * head;
    Node * last;
    
    List(){
        head = NULL;
        last = NULL;
    }
    
    bool isEmpty(){
        return(head==NULL);
    }
    
    void pushFront(int value){
        
        if(isEmpty()){
            head = new Node(value);
            last = head;   //Head ve last'in next-prev degeri varsayilan NULL oldugu icin atama yapmaya gerek yok
        }
        else{
            Node * temp = new Node(value);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    
    void pushBack(int value){
        
        if(isEmpty()){
            head = new Node(value);
            last = head;
        }
        else{
            Node * temp = new Node(value);
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }
    
    void popFront(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            if(head->next==NULL){
                delete head;
                head = NULL;
                last = NULL;
            }
            else{
                Node * temp = head->next;
                delete head;
                head = temp;
                head->prev=NULL;
            }
        }
    }
    
    void popBack(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            if(head->next == NULL){
                delete head;
                head = NULL;
                last = NULL;
            }
            else{
                Node * temp = last->prev;
                delete last;
                last = temp;
                last->next=NULL;
            }
        }
    }
    
    void print(){
        
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
    
    void reserve(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = last;
            while(temp!=NULL){
                cout << last->data << " ";
                temp = temp->prev;
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
                temp=head;
                head = head->next;
                delete temp;
            }
            head = NULL;
            last = NULL;
            cout << "Liste resetlendi" << endl;
        }
    }
    
};



int main(){
    
    List l;
    int secim, sayi;
    
    while(1){
        cout << endl;
        cout << "Cift Yonlu Dogrusal Bagli Liste" << endl;
        cout << "1) Basa Ekle" << endl;
        cout << "2) Sona Ekle" << endl;
        cout << "3) Bastan Sil" << endl;
        cout << "4) Sondan Sil" << endl;
        cout << "5) Tersten Yaz" << endl;
        cout << "6) Sifirla" << endl;
        cout << "7) Sirala" << endl;
        cout << "0) Cikis" << endl;
        cout << "Seciminiz: "; cin >> secim;
        
        switch(secim){
            case 1: cout << "Sayi: "; cin >> sayi;
                l.pushFront(sayi);
                l.print();
                break;
            case 2: cout << "Sayi: "; cin >> sayi;
                l.pushBack(sayi);
                l.print();
                break;
            case 3: l.popFront();
                l.print();
                break;
            case 4: l.popBack();
                l.print();
                break;
            case 5: l.reserve();
                l.print();
                break;
            case 6: l.reset();
                break;
            case 0: cout << "Cikis yapiliyor..." << endl;
                return 0;
            default: cout << "Yanlis tuslama..." << endl;
                break;
        }
    }
    
    return 0;
}

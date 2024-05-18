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
        return(head == NULL);
    }
    
    void pushFront(int value){
        
        if(isEmpty()){
            head = new Node(value);
            head->next=head;
            head->prev=head;
            
            last = head;
        }
        else{
            Node * temp = new Node(value);
            temp->next = head;
            head->prev = temp;
            head = temp;
            
            last->next= head;
            head->prev = last;
        }
    }
    
    void pushBack(int value){
        
        if(isEmpty()){
            head = new Node(value);
            head->next = head;
            head->prev = head;
            
            last = head;
        }
        else{
            Node * temp = new Node(value);
            last->next = temp;
            temp->prev = last;
            last = temp;
            
            head->prev=last;
            last->next=head;
            
        }
    }
    
    void popFront(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            if(head->next==head){
                delete head;
                head = NULL;
                last = NULL;
            }
            else{
                Node * temp = head->next;
                delete head;
                head = temp;
                
                head->prev=last;
                last->next=head;
            }
        }
    }
    
    void popBack(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            if(head->next==head){
                delete head;
                head = NULL;
                last = NULL;
            }
            else{
                Node * temp = last->prev;
                delete last;
                last = temp;
                
                last->next=head;
                head->prev=last;
            }
        }
    }
    
    void reserve(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = last;
            while(temp->prev!=last){
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << temp->data << " ";
            
        }
    }
    
    void reset(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = head;
            while(head->next!=last){
                temp = head;
                head = head->next;
                delete temp;
            }
            delete last;
            head = NULL;
            last = NULL;
            cout << "Liste resetlendi" << endl;
        }
    }
    
    void print(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            
            Node * temp = head;
            while(temp->next!=head){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << temp->data << " ";
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
        cout << "5) Ters Cevir" << endl;
        cout << "6) Reset" << endl;
        cout << "7) Yazdir" << endl;
        cout << "0) Cikis" << endl;
        cout << "Secim: "; cin >> secim;
        
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
                break;
            case 6: l.reset();
                break;
            case 7: l.print();
                break;
            case 0: cout << "Cikis yapiliyor" << endl;
                return 0;
            default: cout << "Yanlis tuslama..." << endl;
                break;
        }
    }
    
    
    
    return 0;
}

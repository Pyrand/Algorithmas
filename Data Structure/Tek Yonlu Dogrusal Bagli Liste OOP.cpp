#include <iostream>
using namespace std;

class Node{
public:
    int Data;
    Node * next;
    
    Node(int data = 0){
        Data = data;
        next = NULL;
    }
};

class List{
public:
    Node * head;
    
    List(){   //Head'a varsayilan NULL atadik
        head = NULL;
    }
    
    bool isEmpty(){
        return(head == NULL);
    }
    
    void insertFront(int data){   //Dugum basina eleman ekleme
        
        if(isEmpty()){
            head = new Node(data);
            cout << "Liste olusturuldu ve ilk eleman eklendi" << endl;
        }
        else{
            Node * temp = new Node(data);
            temp->next = head;
            head = temp;
            cout << "Liste basina eleman eklendi" << endl;
        }
    }
    
    void insertBack(int data){   //Dugum sonuna eleman ekleme
        
        if(isEmpty()){
            head = new Node(data);
            cout << "Liste olusturuldu ve ilk eleman eklendi" << endl;
        }
        else{
            
            Node * temp = head;
            while (temp->next!=NULL) {
                temp = temp->next;
            }
            
            temp->next = new Node(data);
            cout << "Liste sonuna eleman eklendi" << endl;
        }
    }
    
    void insert(int data){   //Araya ekleme
        
        if(isEmpty()){
            head = new Node(data);
            cout << "Liste olusturuldu ve ilk eleman eklendi" << endl;
        }
        else{
            int secim;
            cout << "Hangi sayidan once eklensin: "; cin >> secim;
            
            if(head->next==NULL && head->Data==secim){   //Listede tek dugum varsa
                Node * temp = new Node(data);
                temp->next = head;
                head = temp;
                cout << "Eleman eklendi" << endl;
            }
            else if(head->next!=NULL && head->Data==secim){   //Listede birden fazla dugum varsa ve basa deger eklenmek isteniyorsa
                Node * temp = new Node(data);
                temp->next = head;
                head = temp;
                cout << "Eleman eklendi" << endl;
            }
            else{
                Node * temp = head;
                Node * prev = head;
                
                while(temp!=NULL){
                    
                    if(temp->Data==secim){
                        prev->next = new Node(data);
                        prev->next->next = temp;
                        cout << "Eleman eklendi" << endl;
                    }
                    
                    prev = temp;   //temp yani son dugumden onceki dugumu tutmak icin
                    temp = temp->next;
                }
            }
        }
    }
    
    void popFront(){   //Bastaki elemani silme
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else if(head->next==NULL){
            delete head;
            head->next=NULL;
            cout << "Listekedi son eleman silindi" << endl;
        }
        else{
            Node * temp = head->next;
            delete head;
            head = temp;
            cout << "Bastaki eleman silindi" << endl;
        }
    }
    
    void popBack(){   //Sondaki elemani silme
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else if(head->next==NULL){
            delete head;
            head->next=NULL;
        }
        else{
            Node * temp = head;
            Node * prev = head;
            
            while(temp->next!=NULL){
                
                prev = temp;
                temp = temp->next;
            }
            
            delete temp;
            prev->next=NULL;
            cout << "Sondaki eleman silindi" << endl;
        }
    }
    
    void erase(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            int data;
            cout << "Silinecek eleman: "; cin >> data;
            
            if(head->next == NULL && head->Data==data){
                delete head;
                head->next=NULL;
                cout << "Listedeki son eleman silindi" << endl;
            }
            else if(head->next!=NULL && head->Data==data){
                Node * temp = head->next;
                delete head;
                head = temp;
                cout << "Eleman silindi" << endl;
            }
            else{
                Node * temp = head;
                Node * prev = head;
                
                while(temp->next!=NULL){
                    
                    if(temp->Data == data){
                        
                        prev->next = temp->next;
                        delete temp;
                        cout << "Eleman silindi" << endl;
                        break;
                    }
                    
                    prev = temp;
                    temp = temp->next;
                }
                if(temp->Data == data){
                    
                    delete temp;
                    prev->next = NULL;
                    cout << "Eleman silindi" << endl;
                }
            }
        }
    }
    
    
    void print(){
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = head;
            while (temp->next!=NULL) {
                cout << temp->Data << " ";
                temp = temp->next;
            }
            cout << temp->Data << " ";
        }
    }
    
};



int main(){
    
    //Uygulama manuel olarak çalıştırılır, herhangi bir menü yapılmadı...
    List l;
    
    l.insertBack(10);
    l.insertBack(20);
    l.insertBack(30);
    l.insertBack(40);
    l.erase();
    
    l.print();
    return 0;
}

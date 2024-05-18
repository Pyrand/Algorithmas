#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    
    Node(int data = 0){
        this->data=data;
        next = NULL;
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
            head->next = head;
            
            last = head;
            last->next = head;
        }
        else{
            Node * temp = new Node(value);
            temp->next = head;
            head = temp;
            last->next = head;
        }
    }
    
    void pushBack(int value){
        
        if(isEmpty()){
            head = new Node(value);
            head->next = head;
            
            last = head;
            last->next=head;
        }
        else{
            last->next = new Node(value);
            last = last->next;
            last->next = head;
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
                head=NULL;
                last=NULL;
            }
            else{
                Node * temp = head;
                while(temp->next!=last){
                    temp = temp->next;
                }
                
                delete last;
                last = temp;
                temp->next=head;
            }
        }
    }
    
    void clear(){
        
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = head;
            while(head!=last){
                temp = head;
                head = head->next;
                delete temp;
            }
            delete last;
            head = NULL;
            last = NULL;
        }
    }
    
    void print(){
        if(isEmpty()){
            cout << "Liste bos" << endl;
        }
        else{
            Node * temp = head;
            while(temp!=last){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << temp->data << " ";
        }
    }
    
    
};


int main(){
    
    //Uygulama manuel olarak çalıştırılır, herhangi bir menü yapılmadı...
    
    List l;
    
    l.pushBack(10);
    l.print();
    
    return 0;

}

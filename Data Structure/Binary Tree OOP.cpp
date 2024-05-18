#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;
    
    Node(int data = 0){
        this->data=data;
        left = NULL;
        right = NULL;
    }
};

class Tree{
public:
    Node * head;
    Tree(){
        head = NULL;
    }
    
    bool isEmpty(){
        return(head==NULL);
    }
    
    Node * insert(Node * head, int value){
        if(head!= NULL){
            if(value > head->data){
                head->right = insert(head->right, value);
            }
            else{
                head->left = insert(head->left, value);
            }
        }
        else{
            return new Node(value);
        }
        return head;
    }
    
    void insert(int value){
        head = insert(head, value);
    }
    
    void preOrder(Node * head){   //Once kok
        
        if(head!=NULL){
            cout << head->data << " ";
            preOrder(head->left);
            preOrder(head->right);
        }
    }
    
    void inOrder(Node * head){   //Ortada kok, kucukten buyuge siralama
        
        if(head!=NULL){
            
            inOrder(head->left);
            cout << head->data << " ";
            inOrder(head->right);
        }
    }
    
    void postOrder(Node * head){   //Sonda kok
        
        if(head!=NULL){
            
            postOrder(head->left);
            postOrder(head->right);
            cout << head->data << " ";
        }
    }
    
    int size(Node * head){
        if(head==NULL){
            return 0;
        }
        else{
            return size(head->left) + 1 + size(head->right);
        }
    }
    
    int height(Node * head){
        
        if(head==NULL){
            return 0;
        }
        else{
            int sol, sag;
            sol = height(head->left);
            sag = height(head->right);
            
            if(sol > sag){
                return sol + 1;
            }
            else{
                return sag + 1;
            }
        }
    }
    
    int min(Node * head){   //Tree'nin en kucuk elemani en soldakidir
        
        Node * temp = head;
        if(head==NULL){
            return 0;
        }
        else{
            while (temp->left!=NULL) {
                temp = temp->left;
            }
            return temp->data;
        }
    }
    
    int max(Node * head){   //Tree'nin en buyuk elemani en sagdakidir
        
        Node * temp = head;
        if(head==NULL){
            return 0;
        }
        else{
            while (temp->right!=NULL) {
                temp = temp->right;
            }
            return temp->data;
        }
    }
};

    

int main(){
    
    //Uygulama manuel olarak çalıştırılır, herhangi bir menü yapılmadı...
    
    Tree t;
    
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(30);
    t.insert(40);
    t.insert(15);
    t.insert(3);
    
    
    cout << "Once kok: "; t.preOrder(t.head);
    cout << endl;
    cout << "Ortada kok: "; t.inOrder(t.head);
    cout << endl;
    cout << "Sonda kok: "; t.postOrder(t.head);
    cout << endl;
    cout << "Dugum sayisi: " << t.size(t.head);
    cout << endl;
    cout << "Yukselik: " << t.height(t.head);
    cout << endl;
    cout << "En kucuk sayi: " << t.min(t.head);
    cout << endl;
    cout << "En buyuk sayi: " << t.max(t.head);
    cout << endl;
    return 0;
}

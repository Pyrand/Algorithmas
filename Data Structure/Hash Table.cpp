#include <iostream>
#include <string>
#define SIZE 5
using namespace std;

class Node{
public:
    int key;
    string value;
    Node * next;
    
    Node(){
        key = 0;
        value = "";
        next = NULL;
    }
};

class HashTable{
public:
    Node * dizi[SIZE];
    
    HashTable(){
        for(int i = 0; i < SIZE; i++){
            dizi[i] = new Node();
        }
    }
    
    int mod(int key){
        return key % SIZE;
    }
    
    void Add(){
        
        Node * eleman = new Node();
        cout << "Key: "; cin >> eleman->key;
        cout << "Value: "; cin >> eleman->value;
        
        int index = mod(eleman->key);
        
        Node * temp = dizi[index];
        while(temp->next!=NULL){
            temp = temp->next;
        }
        
        temp->next = eleman;
        cout << "Ekleme islemi yapildi..." << endl;
    }
    
    void Delete(){
        
        int numara;
        cout << "Key: "; cin >> numara;
        bool sonuc = false;
        
        int index = mod(numara);
        Node * temp = dizi[index];
        Node * temp2 = dizi[index];
        
        while(temp->next!=NULL){
            temp2 = temp;
            temp = temp->next;
            
            if(numara == temp->key){
                temp2->next = temp->next;
                delete temp;
                sonuc = true;
                break;
            }
        }
        
        if(sonuc){
            cout << "Eleman silindi" << endl;
        }
        else{
            cout << "Eleman yok" << endl;
        }
        
    }
    
    void Print(){
        
        for(int i=0; i < SIZE; i++){
            Node * temp = dizi[i];
            cout << "\nDizi[" << i << "]" << " -> ";
            while(temp->next!=NULL){
                temp = temp->next;
                cout << temp->key << " " << temp->value << " -> ";
            }
        }
    }
    
};


int main(){
    
    //Uygulama manuel olarak çalıştırılır, herhangi bir menü yapılmadı...
    
    HashTable ht;
    
    ht.Add();
    ht.Add();
    ht.Add();
    
    ht.Print();
    
    
    return 0;
}

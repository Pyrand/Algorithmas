//Queue Dinamik Uygulama
#include <iostream>
#define SIZE 10
using namespace std;

struct node{   //Dinamik kuyruk yapmak icin bagli liste kullanacagiz
    int data;
    struct node * next;
};

struct queue{
    int cnt;
    struct node * front;  //Kuyrugun ilk indisi
    struct node * rear;   //Kuyrugun son indisi
};

void initializing(queue * q){   //Kuyruga ilk degerleri atiyoruz
    q->cnt=0;
    q->front = q->rear = NULL;
}

bool isFull(queue * q){   //Kuyruktaki cnt SIZE'a esit ise kuyruk doludur
    return(q->cnt == SIZE);
}

bool isEmpty(queue * q){   //Kuyruktaki cnt 0'a esit ise kuyruk bostur
    return(q->cnt==0);
}

void enqueue(queue * q, int veri){
    
    struct node * eleman = new node();
    eleman->data=veri;
    
    if(isFull(q)){   //Kuyruk dolu ise eleman eklenmez
        cout << "Kuyruk doludur!" << endl;
    }
    else if(isEmpty(q)){   //Kuyrukta eleman yoksa ilk eleman ekleme islemi burada olur
        eleman->next=NULL;   //Tek bir eleman olduğu için next'i NULL olur, front ve rear'da elemana esit olur
        q->front=eleman;
        q->rear=eleman;
        
        q->cnt++;
        cout << "Kuyruga ilk eleman eklendi" << endl;
    }
    else{   //Kuyrukta birden fazla eleman var ise burada islem gerceklesir
        eleman->next=q->rear;   //Rear'ın onune girilen deger gelir ve rear'ı bu deger olarak guncelleriz
        q->rear=eleman;
        
        q->cnt++;
        cout << "Kuyruga eleman eklendi" << endl;
    }
}

void dequeue(queue * q){
    
    if(isEmpty(q)){
        cout << "Kuyruk bostur!" << endl;
    }
    else if(q->cnt == 1){   //Kuyrukta bir eleman varsa burasi calisir
        delete q->front;
        q->front = NULL;
        q->rear = NULL;
        
        q->cnt--;
        cout << "Kuyruktaki son eleman silindi" << endl;
    }
    else{   //Kuyrukta birden fazla eleman varsa burasi calisir
        struct node * temp = q->rear;
        
        while(temp->next!=q->front){   //Temp fronttan bir onceki degeri tutar
            temp=temp->next;
        }
        
        delete q->front;   //Front silinir yerine temp yani fronttan onceki eleman front'a atanir.
        q->front = temp;
        q->front->next = NULL;
        
        q->cnt--;
        cout << "Kuyruktan eleman silindi" << endl;
    }
}

void print(queue * q){
    system("cls");
    
    if(isEmpty(q)){
        cout << "Kuyruk bostur!" << endl;
    }
    else{
        struct node * temp = q->rear;
        while (temp->next!=NULL) {
            cout << temp->data << " -> ";
            temp=temp->next;
        }
        cout << temp->data;
    }
}

int main(){
    queue qu;
    initializing(&qu);   //Program ilk acildiginda ilk degerlerin girilmesi icin
    int secim, sayi;
    
    while (1) {
        cout << endl;
        cout << "Queue Dinamik Uygulama" << endl;
        cout << "1- Enqueue" << endl;
        cout << "2- Dequeue" << endl;
        cout << "3- Print" << endl;
        cout << "0- Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;
        
        switch(secim){
            case 1: cout << "Girmek istediginiz sayi: ";
                cin >> sayi;
                enqueue(&qu, sayi);
                break;
                
            case 2: dequeue(&qu);
                break;
                
            case 3: print(&qu);
                break;
                
            case 0: cout << "Cikis yapiliyor..." << endl;
                return 0;
                
            default: cout << "Yanlis tuslama yaptiniz!" << endl;
                break;
        }
        
    }
}

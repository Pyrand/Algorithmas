#include <iostream>
#define SIZE 100
using namespace std;

struct node{   //Linked List yapisi
    int data;
    struct node * next;
};

struct stack{   //Stack yapisi
    int cnt;
    struct node * top;
};

struct queue{   //Queue yapisi
    int cnt;
    struct node * front;
    struct node * rear;
};

//********************************************

//Bu iki fonksiyonda stack ve queue'e baslangic degerlerini veriyoruz

void sInitialize(stack * s){
    s->cnt = 0;
    s->top = NULL;
}

void qInitialize(queue * q){
    q->cnt = 0;
    q->front = q->rear = NULL;
}

//********************************************

//Stack'e deger ekleme yapan fonksiyon

bool sisFull(stack * s){
    return(s->cnt == SIZE);
}

bool sisEmpty(stack * s){
    return(s->cnt == 0);
}

void sPush(stack * s, int data){
    struct node * eleman = new node();
    eleman->data=data;
    
    if(sisFull(s)){
        cout << "Stack dolu" << endl;
    }
    else if(sisEmpty(s)){   //Stack'e ilk eleman burada eklenir.
        eleman->next = NULL;
        s->top = eleman;
        s->cnt++;
    }
    else{
        eleman->next = s->top;
        s->top = eleman;
        s->cnt++;
    }
}

//********************************************

//Queue'e deger ekleme yapan fonksiyon

bool qisFull(queue * q){
    return(q->cnt==SIZE);
}

bool qisEmpty(queue * q){
    return(q->cnt==0);
}

void qEnqueue(queue * q, int data){
    struct node * eleman = new node();
    eleman->data=data;
    
    if(qisFull(q)){
        cout << "Queue dolu" << endl;
    }
    else if(qisEmpty(q)){
        eleman->next = NULL;
        q->front = q->rear = eleman;
        q->cnt++;
    }
    else{
        eleman->next = q->rear;
        q->rear = eleman;
        q->cnt++;
    }
}

//********************************************

//Stack'den deger silen fonksiyon

int sPop(stack * s){
    
    if(sisEmpty(s)){
        cout << "Stack bos" << endl;
        return 0;
    }
    else if(s->cnt==1){
        int x = s->top->data;
        delete s->top;
        s->top = NULL;
        s->cnt--;
        
        return x;
    }
    else{
        int x = s->top->data;
        struct node * temp = s->top->next;
        delete s->top;
        s->top = temp;
        s->cnt--;
        
        return x;
    }
}

//********************************************

//Queue'den deger silen fonksiyon

int qDequeue(queue * q){
    
    if(qisEmpty(q)){
        cout << "Queue bos" << endl;
        return 0;
    }
    else if(q->cnt==1){
        int x = q->front->data;
        delete q->front;
        q->front = q->rear = NULL;
        q->cnt--;
        
        return x;
    }
    else{
        int x = q->front->data;
        struct node * temp = q->rear;
        while (temp->next!=q->front) {
            temp = temp->next;
        }
        delete q->front;
        q->front = temp;
        q->front->next = NULL;
        q->cnt--;
        
        return x;
    }
}


int main(){
    stack s;
    queue q;
    sInitialize(&s);
    qInitialize(&q);
    
    string kelime = "";
    cout << "Kelime giriniz: ";
    cin >> kelime;
    
    int i = 0;
    while (i < kelime.length()) {   //Burada kelimeyi stack ve queue'e sırayla ekledik
        sPush(&s, kelime[i]);
        qEnqueue(&q, kelime[i]);
        i++;
    }
    
    int sonuc = 0;
    
    while (!sisEmpty(&s)) {   //Kelimeleri stack'ten sondan, queue'den bastan alarak karsilastiriyoruz
        if(sPop(&s) != qDequeue(&q)){
            sonuc = 1;   //Eger eslesen sonuc farkli ise bu kelime palindrom olmuyor
            break;
        }
    }
    
    if(sonuc == 0){
        cout << "Kelime palindromdur." << endl;
    }
    else{
        cout << "Kelime palindrom değildir" << endl;
    }
}

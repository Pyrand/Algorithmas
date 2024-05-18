#include <iostream>
using namespace std;


int a[] = {1,5,8,3,4,2,6,0};
int b[8];


void merge(int bas, int orta, int son){
    
    int i, j, k;
    
    for(i = bas; i<=son; i++){
        b[i] = a[i];   //b dizisi icine a dizi degerlerini kopyaladik
    }
    
    i = bas;
    k = bas;
    j = orta+1;
    
    while (i <= orta && j <= son) {
        if(b[i] <= b[j]){
            a[k++] = b[i++];
        }
        else{
            a[k++] = b[j++];
        }
    }
    while(i <= orta){
        a[k++] = b[i++];
    }
    
    
}

void divide(int bas, int son){
    
    if(bas < son){
        int orta = (bas + son) / 2;
        divide(bas, orta);   //Soldaki degerler icin calisir
        divide(orta+1, son);   //Sagdaki degerler icin calisir
        merge(bas, orta, son);
    }
}

int main(){
    
    divide(0,7);
    for(int i = 0; i<=7; i++){
        cout << a[i] << " ";
    }
    
    
    return 0;
}

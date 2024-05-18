#include <iostream>
using namespace std;

void selectionSort(int dizi[], int n){
    for(int i=0; i<n; i++){
        for(int k = 0; k < n-1; k++){
            
            int kucuk = dizi[i];
            int indis = i;
            
            for(int k = i; k < n; k++){
                if(kucuk > dizi[k]){   //Burada kucuk isimli degiskene kucuk degeri atıyoruz, değişim yok
                    kucuk = dizi[k];
                    indis = k;
                }
            }
            
            dizi[indis] = dizi[i];   //Degisim burada
            dizi[i] = kucuk;
        }
    }
}


int main(){
    int n;
    cout << "Kaç adet sayi girilecek: ";
    cin >> n;
    int dizi[n];
    
    int i = 0;
    while(i<n){
        cout << i+1 << ". sayı: "; cin >> dizi[i];
        i++;
    }
    
    selectionSort(dizi, n);
    cout << "Siralanmis hali: ";
    
    for(int i = 0; i < n; i++){
        cout << dizi[i] << " ";
    }
    
    
    
    return 0;
}

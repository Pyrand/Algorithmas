#include <iostream>
using namespace std;
//Bubble Sort / En buyuk sayiyi sona tasir

void bubbleSort(int dizi[], int n){
    for(int i = 0; i < n-1; i++){   //Ilk once kac sayi varsa onun bi eksigi kadar karsilastirma islemi yapilir
        
        for(int k = 0; k < n-i-1; k++){   //Sonra o sayilar icerisinde karsilastirma islemi yapilir, sonraki asamalarda sayi azalacagindan karsilastirma sayisi da azalacagi icin -i'de eklenir.
            
            if(dizi[k] > dizi[k+1]){   //Eger deger bir sonraki degerden buyuk ise yer degistirme islemi yapilir
                int temp = dizi[k];
                dizi[k] = dizi[k+1];
                dizi[k+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    cout << "Kac adet sayi girilsin: ";
    cin >> n;
    int dizi[n];
    
    int i = 0;
    while (i<n) {
        cout << i+1 << ". sayi: ";
        cin >> dizi[i];
        i++;
    }
    
    bubbleSort(dizi, n);
    cout << "Sıralama islemi: " << endl;
    
    for(int i=0; i<n; i++){
        cout << dizi[i] << " ";
    }
    
    return 0;
}

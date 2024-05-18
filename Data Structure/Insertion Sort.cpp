#include <iostream>
using namespace std;

//Insertion Sort / Kucuk sayiyi basa tasima

/*
 7 3 5 1 2
 
 [7 3] 5 1 2 -> [3 7] 5 1 2
 [3 7 5] 1 2 -> [3 5 7] 1 2
 [3 5 7 1] 2 -> [1 3 5 7] 2
 [1 3 5 7 2] -> [1 2 3 5 7]
 
 for(sayi-1)
    for(kendisinden önceki sayi adedi)
 
 
 */

void insertionSort(int dizi[], int n){
    
    for(int i = 1; i < n ; i++){   //Sondan karsilastima yapacagimiz icin indisi 1'den baslatiyoruz. Cunku 0. indisi karsilastima yapamayiz
        
        for(int k = i; k>=0; k--){   //Sayilar kendi aralarinda karsilastirma yapar. Kendinden sonraki sayilar kadar karsilastirma yapilacagi icin k'ya i'ti atadik
            
            if(dizi[k] < dizi[k-1]){   //Eger k. indis k-1. indisten kucukse yer degistirme yapilir. Örnegin [7 3] arasinda karsilastirma yapiliyorsa k = 3, k - 1 = 7'dir
                int temp = dizi[k];
                dizi[k] = dizi[k-1];
                dizi[k-1] = temp;
            }
        }
    }
}


int main(){
    int n;
    cout << "Kac adet sayi gireceksiniz: "; cin >> n;
    int dizi[n];
    
    int i = 0;
    while(i < n){
        cout << i+1 << ". sayi: ";
        cin >> dizi[i];
        i++;
    }
    
    insertionSort(dizi, n);
    cout << "Sıralama: " << endl;
    for(int i = 0; i < n; i++){
        cout << dizi[i] << " ";
    }
    
    
    return 0;
}

#include <iostream>
using namespace std;

void quickSort(int dizi[], int ilk, int son){
    int i, j, pivot, temp;
    i = ilk;
    j = son;
    pivot = dizi[(i+j) / 2];   //Sıralama yaparken sayilar pivot'la yani ortanca degerle karsilastirilir
    
    do{
        
        while(dizi[i] < pivot){   //Bu dongu soldaki degerleri pivotla karsilastirir. Eger pivot soldaki ilk degerden buyuk ise islem yapilmaz, i arttirilir
            i++;
        }
        
        while (dizi[j] > pivot) {   //Bu dongu sagdaki degerleri pivotla karsilastirir. Eger sagdaki deger pivottan buyuk ise islem yapilmaz, j azaltilir.
            j--;
        }
        
        if(i<=j){   //Yer degistirme islemi burada yapilir
            temp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = temp;
            
            i++;
            j--;
        }
    } while (i<j);
    
    if(i < son){
        quickSort(dizi, i, son);
    }
    if(ilk < j){
        quickSort(dizi, ilk, j);
    }
    
}

int main(){
    int n;
    cout << "Kac sayi girilsin: "; cin >> n;
    int dizi[n];
    
    int i = 0;
    while (i<n) {
        cout << i+1 << ". sayi: "; cin >> dizi[i];
        i++;
    }
    
    quickSort(dizi, 0, n-1);   //0 ilk indisi, n-1 ise son indisi gonderir
    cout << "Siralanmis sayilar: " << endl;
    for(int i = 0; i < n; i++){
        cout << dizi[i] << " ";
    }
    
    return 0;
}

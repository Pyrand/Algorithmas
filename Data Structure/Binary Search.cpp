#include <iostream>
using namespace std;

//Binary Search sirali dizilerde gecerlidir

bool binarySearch(int dizi[], int ilk, int son, int aranan){
    
    while (son >= ilk) {
        int orta = dizi[(ilk + son) / 2];   //Aranan sayi ortanca sayiyla karsilastirilir
        
        if(aranan == orta){
            return true;
        }
        
        if(aranan < orta){   //Ortadaki sayi aranan sayidan buyuk ise sağa kayar
            son--;
        }
        if(aranan > orta){   //Ortadaki sayi aranan sayidan kucuk ise sola kayar
            ilk++;
        }
    }
    
    return false;
    
}



int main(){
    
    int n;
    cout << "Sayi adedi giriniz: "; cin >> n;
    int dizi[n];
    
    int i = 0;
    while (i < n) {
        cout << i+1 << ". sayi: "; cin >> dizi[i];
        i++;
    }
    
    int aranan;
    cout << "Aranan sayi: "; cin >> aranan;
    
    bool sonuc = binarySearch(dizi, 0, n-1, aranan);
    
    if(sonuc){
        cout << aranan << " listededir" << endl;
    }
    else{
        cout << "Aranan sayi listede yoktur" << endl;
    }
    
    return 0;
}

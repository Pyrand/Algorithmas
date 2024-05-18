#include <iostream>
using namespace std;

int linearSearch(int dizi[], int n, int aranan){
    
    for(int i = 0; i<n; i++){
        if(dizi[i] == aranan){
            return i;
        }
    }
    return -1;
}


int main(){
    
    int n;
    cout << "Dizi boyutunu giriniz: ";
    cin >> n;
    int dizi[n];
    
    int i = 0;
    while (i < n) {
        cout << i+1 << ". sayi: ";
        cin >> dizi[i];
        i++;
    }
    
    int aranan;
    cout << "Aranan sayi: "; cin >> aranan;
    
    
    int sonuc = linearSearch(dizi, n, aranan);
    
    if(sonuc == -1){
        cout << "Aranan sayi yok" << endl;
    }
    else{
        cout << "Aranan sayi " << sonuc << ". indistedir" << endl;
    }
    
    return 0;
}

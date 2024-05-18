#include <iostream>
using namespace std;

void quickSort(int dizi[], int ilk, int son){
    
    int i, j, pivot, temp;
    i = ilk;
    j = son;
    pivot = dizi[(ilk + son) /2];
    
    do{
        
        while (dizi[i] < pivot) {
            i++;
        }
        while (dizi[j] > pivot) {
            j--;
        }
        
        if(i <= j){
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
    if(j > ilk){
        quickSort(dizi, ilk, j);
    }
}

bool binarySearch(int dizi[], int ilk, int son, int aranan){
    
    while(son >= ilk){
        int orta = dizi[(ilk + son) / 2];
        
        if(orta == aranan){
            return true;
        }
        
        if(orta > aranan){
            son--;
        }
        if(orta < aranan){
            ilk++;
        }
    }
    return false;
}


int main(){
    int n;
    cout << "Dizi boyutu: "; cin >> n;
    int dizi[n];
    
    int i = 0;
    while (i < n) {
        cout << i+1 << ". sayi: "; cin >> dizi[i];
        i++;
    }
    
    int aranan;
    cout << "Aranan sayi: "; cin >> aranan;
    
    quickSort(dizi, 0, n-1);
    bool sonuc = binarySearch(dizi, 0, n-1, aranan);
    
    cout << "Liste: ";
    for(int i = 0; i < n; i++){
        cout << dizi[i] << " ";
    }
    
    cout << endl;
    
    if(sonuc){
        cout << aranan << " listede vardir" << endl;
    }
    else{
        cout << "Aranan listede yoktur" << endl;
    }
    
    return 0;
}

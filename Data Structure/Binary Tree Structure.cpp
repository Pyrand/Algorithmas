#include <iostream>
using namespace std;

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * kokDugum(int data){
    struct node * root = new node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    
    return root;
}

struct node * dugumEkle(struct node * root, int data){
    
    if(root == NULL){   //Root bos ise burada ilk dugum olusturmak için kokDugum fonksiyonuna gidilir
        root = kokDugum(data);
    }
    else{
        if(data < root->data){   //Girilen veri root->data'dan küçükse veri sola; büyükse sağa eklenir
            root->left = dugumEkle(root->left, data);
        }
        else{
            root->right = dugumEkle(root->right, data);
        }
    }
    
    return root;
}

void preOrder(struct node * root){   //Ilk once bas root sonra sol ve sag root okunur
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node * root){   //Ilk önce sol, sonra bas en sonda da sag root okunur
    if(root != NULL){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(struct node * root){   //Ilk once sol ve sag, en sonda da bas root okunur
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int dugumSayisi(struct node * root){   //Burada Tree'nin kac dugumden olustugunu buluyoruz
    if(root == NULL){
        return 0;
    }
    else{
        return dugumSayisi(root->left) + dugumSayisi(root->right) + 1;   //+1 deme sebebimiz ilk katmani 1 olarak saymamiz
    }
}

int yukseklik(struct node * root){   //Alttaki dugumden usttekine kadar yukseklik kac bunu buluyoruz
    if(root == NULL){
        return 0;
    }
    else{
        int sol, sag;
        
        sol = yukseklik(root->left);
        sag = yukseklik(root->right);
        
        if(sol>sag){   //+1 deme sebebimiz ilk katmani 1 olarak saymamiz
            return sol + 1;
        }
        else{
            return sag + 1;
        }
    }
}

void yerDegis(struct node * root){   //Sol ve sag Tree'yi yer degistiriyoruz
    struct node * temp = NULL;
    
    if(root != NULL){
        yerDegis(root->left);
        yerDegis(root->right);
        
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int main(){
    struct node * root =   NULL;
    int sayi, i=0;
    
    while (i < 7) {   //Buradan sayilari giriyoruz
        cout << i+1 << ". sayiyi giriniz: ";
        cin >> sayi;
        root = dugumEkle(root, sayi);
        i++;
    }
    
    //Bu kisimda da yazdirma islemelerini yapiyoruz
    cout << "preOrder: "; preOrder(root);
    cout << endl;
    cout << "inOrder: "; inOrder(root);
    cout << endl;
    cout << "postOrder: "; postOrder(root);
    cout << endl;
    cout << "Eklenen dugum sayisi: " << dugumSayisi(root) << endl;
    cout << "Tree'nin yuksekligi: " << yukseklik(root) << endl;
    cout << "Sol ve sag Tree'nin yer degistirmis hali: "; yerDegis(root);
    inOrder(root);
    cout << endl;
    
    return 0;
}

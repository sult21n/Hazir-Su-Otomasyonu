#include <iostream>
#include <string>

using namespace std;

// Ürün bilgilerini tutan yapý
struct SuUrunu {
    int id;
    string marka;
    int stokAdedi;
    double fiyat;
};

// Global deðiþkenler (Maksimum 100 ürün kapasitesi)
SuUrunu stokDizisi[100];
int toplamUrun = 0;

// Fonksiyonlar
void urunEkle() {
    if (toplamUrun < 100) {
        cout << "Urun ID: "; cin >> stokDizisi[toplamUrun].id;
        cout << "Marka: "; cin >> stokDizisi[toplamUrun].marka;
        cout << "Stok Adedi: "; cin >> stokDizisi[toplamUrun].stokAdedi;
        cout << "Fiyat: "; cin >> stokDizisi[toplamUrun].fiyat;
        toplamUrun++;
        cout << "Urun basariyla eklendi!\n";
    } else {
        cout << "Stok kapasitesi dolu!\n";
    }
}

void urunListele() {
    cout << "\n--- MEVCUT STOK LISTESI ---\n";
    for (int i = 0; i < toplamUrun; i++) {
        cout << "ID: " << stokDizisi[i].id << " | Marka: " << stokDizisi[i].marka 
             << " | Stok: " << stokDizisi[i].stokAdedi << " | Fiyat: " << stokDizisi[i].fiyat << " TL" << endl;
    }
}

void urunAra() {
    int arananID;
    cout << "Aranacak Urun ID: "; cin >> arananID;
    for (int i = 0; i < toplamUrun; i++) {
        if (stokDizisi[i].id == arananID) {
            cout << "Urun Bulundu: " << stokDizisi[i].marka << " - Stok: " << stokDizisi[i].stokAdedi << endl;
            return;
        }
    }
    cout << "Urun bulunamadi.\n";
}

void urunSil() {
    int silinecekID;
    cout << "Silinecek Urun ID: "; cin >> silinecekID;
    for (int i = 0; i < toplamUrun; i++) {
        if (stokDizisi[i].id == silinecekID) {
            for (int j = i; j < toplamUrun - 1; j++) {
                stokDizisi[j] = stokDizisi[j + 1];
            }
            toplamUrun--;
            cout << "Urun silindi.\n";
            return;
        }
    }
    cout << "Silinecek ID bulunamadi.\n";
}

int main() {
    int secim;
    do {
        cout << "\n1. Ekle\n2. Listele\n3. Ara\n4. Sil\n0. Cikis\nSecim: ";
        cin >> secim;
        if (secim == 1) urunEkle();
        else if (secim == 2) urunListele();
        else if (secim == 3) urunAra();
        else if (secim == 4) urunSil();
    } while (secim != 0);
    return 0;
}

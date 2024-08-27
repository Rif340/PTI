#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Deklarasi array untuk menyimpan data
    string posisi[] = {"Manager", "Office Boy", "Staf", "Lainnya"};
    int tunjangan[] = {100000, 200000, 100000, 100000};
    int bonus[] = {250000, 0, 300000, 100000};
    int gaji[] = {5000000, 3000000, 4000000, 2000000};

    // Menampilkan header tabel
    cout << left << setw(15) << "Posisi"
         << left << setw(15) << "Tunjangan"
         << left << setw(15) << "Bonus"
         << left << setw(15) << "Gaji" << endl;

    // Looping untuk menampilkan setiap data dari tabel
    for (int i = 0; i < 4; i++) {
        cout << left << setw(15) << posisi[i]
             << left << setw(15) << tunjangan[i]
             << left << setw(15) << bonus[i]
             << left << setw(15) << gaji[i] << endl;
    }

    return 0;
}

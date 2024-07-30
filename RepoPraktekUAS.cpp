#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Struct untuk menyimpan data barang di gudang
struct Gudang
{
    string nama_barang;
    int stok;
    string satuan; // Menambahkan satuan pada struct Gudang
};

// Fungsi untuk menambah stok barang
void tambahStok(Gudang &barang, int jumlah)
{
    barang.stok += jumlah;
    cout << "Stok " << barang.nama_barang << " bertambah sebanyak " << jumlah << " " << barang.satuan << ". Stok saat ini: " << barang.stok << " " << barang.satuan << endl;
}

// Fungsi untuk mengurangi stok barang
void kurangiStok(Gudang &barang, int jumlah)
{
    if (barang.stok >= jumlah)
    {
        barang.stok -= jumlah;
        cout << "Stok " << barang.nama_barang << " berkurang sebanyak " << jumlah << " " << barang.satuan << ". Stok saat ini: " << barang.stok << " " << barang.satuan << endl;
    }
    else
    {
        cout << "Stok " << barang.nama_barang << " tidak mencukupi untuk pengurangan sebanyak " << jumlah << " " << barang.satuan << ". Stok saat ini: " << barang.stok << " " << barang.satuan << endl;
    }
}

// Fungsi untuk menampilkan sisa stok barang
void cekStok(Gudang &barang)
{
    cout << "Stok " << barang.nama_barang << " di gudang adalah " << barang.stok << " " << barang.satuan << endl;
}

// Fungsi untuk menambah barang baru
void tambahBarang(vector<Gudang> &gudang)
{
    Gudang barangBaru;
    cout << "Masukkan nama barang baru: ";
    cin.ignore(); // Mengabaikan karakter newline dari input sebelumnya
    getline(cin, barangBaru.nama_barang);
    cout << "Masukkan jumlah stok awal: ";
    cin >> barangBaru.stok;
    cin.ignore(); // Mengabaikan karakter newline setelah input integer
    cout << "Masukkan satuan (misalnya: box, buah, biji): ";
    getline(cin, barangBaru.satuan);
    gudang.push_back(barangBaru);
    cout << "Barang baru berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan daftar barang
void daftarBarang(const vector<Gudang> &gudang)
{
    cout << "Daftar Barang di Gudang:\n";
    for (size_t i = 0; i < gudang.size(); ++i)
    {
        cout << i + 1 << ". " << gudang[i].nama_barang << " | Stok yang ada di gudang: " << gudang[i].stok << " " << gudang[i].satuan << endl;
    }
}

int main()
{
    vector<Gudang> gudang;
    int pilihan;

    do
    {
        // Menampilkan menu
        cout << "\nPilih Menu:";
        cout << "\n1. Tambah Barang Baru";
        cout << "\n2. Tambah Stok";
        cout << "\n3. Kurangi Stok";
        cout << "\n4. Cek Stok";
        cout << "\n5. Daftar Barang";
        cout << "\n6. Keluar";
        cout << "\nPilih menu (1-6): ";

        // Memeriksa apakah input adalah angka
        while (!(cin >> pilihan))
        {
            cin.clear();                                         // Menghapus flag kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang salah
            cout << "Pilihan tidak valid. Silakan pilih menu (1-6): ";
        }

        // Percabangan untuk memproses pilihan menu
        switch (pilihan)
        {
        case 1:
            tambahBarang(gudang);
            break;
        case 2:
        {
            int index, tambah;
            daftarBarang(gudang);
            cout << "Pilih nomor barang yang ingin ditambah stoknya: ";
            cin >> index;
            if (index >= 1 && index <= static_cast<int>(gudang.size()))
            {
                cout << "Masukkan jumlah barang yang masuk: ";
                cin >> tambah;
                tambahStok(gudang[index - 1], tambah);
            }
            else
            {
                cout << "Nomor barang tidak valid.\n";
            }
            break;
        }
        case 3:
        {
            int index, kurang;
            daftarBarang(gudang);
            cout << "Pilih nomor barang yang ingin dikurangi stoknya: ";
            cin >> index;
            if (index >= 1 && index <= static_cast<int>(gudang.size()))
            {
                cout << "Masukkan jumlah barang yang keluar: ";
                cin >> kurang;
                kurangiStok(gudang[index - 1], kurang);
            }
            else
            {
                cout << "Nomor barang tidak valid.\n";
            }
            break;
        }
        case 4:
        {
            int index;
            daftarBarang(gudang);
            cout << "Pilih nomor barang yang ingin dicek stoknya: ";
            cin >> index;
            if (index >= 1 && index <= static_cast<int>(gudang.size()))
            {
                cekStok(gudang[index - 1]);
            }
            else
            {
                cout << "Nomor barang tidak valid.\n";
            }
            break;
        }
        case 5:
            daftarBarang(gudang);
            break;
        case 6:
            cout << "Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih menu (1-6).\n";
            break;
        }

    } while (pilihan != 6);

    return 0;
}
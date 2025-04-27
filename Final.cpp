#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 8;

struct MobilNode
{
    string nama;
    MobilNode *next;
};

class HashTable
{
private:
    MobilNode *table[TABLE_SIZE];

    int hashFunction(const string &key)
    {
        int hash = 0;
        for (char c : key)
            hash += c;
        return hash % TABLE_SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    void tambah(const string &nama)
    {
        int index = hashFunction(nama);
        MobilNode *newNode = new MobilNode{nama, nullptr};
        newNode->next = table[index];
        table[index] = newNode;
    }

    void tampilkan()
    {
        cout << "Daftar Mobil di HashTable:" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            MobilNode *current = table[i];
            while (current != nullptr)
            {
                cout << "- " << current->nama << endl;
                current = current->next;
            }
        }
    }
};

struct Part
{
    string name;
    string affordance;
};

class Mesin
{
public:
    void nyalakan() { cout << "Mesin dinyalakan." << endl; }
    void matikan() { cout << "Mesin dimatikan." << endl; }
};

class Ban
{
public:
    void berputar() { cout << "Ban berputar." << endl; }
};

class Rem
{
public:
    void gunakan() { cout << "Rem digunakan." << endl; }
};

class Mobil
{
private:
    Mesin mesin;
    Ban ban;
    Rem rem;
    HashTable daftarMobil;
    vector<Part> bagianMobil;

public:
    Mobil()
    {
        bagianMobil = {
            {"Roda", "Bergerak maju/mundur/belok"},
            {"Rem", "Menghentikan mobil"},
            {"Setir", "Mengarahkan mobil"},
            {"Mesin", "Menggerakkan mobil"},
            {"Lampu", "Menerangi jalan / Memberi sinyal"},
            {"Spion", "Melihat area belakang/samping"},
            {"Klakson", "Memberi peringatan suara"},
            {"Pintu", "Akses keluar/masuk mobil"},
            {"Kaca", "Memberi pandangan keluar"}};
    }

    void tambahMobil(const string &nama)
    {
        daftarMobil.tambah(nama);
    }

    void tampilkanMobil()
    {
        daftarMobil.tampilkan();
    }

    void jalan()
    {
        mesin.nyalakan();
        ban.berputar();
        cout << "Mobil berjalan." << endl;
    }

    void berhenti()
    {
        rem.gunakan();
        mesin.matikan();
        cout << "Mobil berhenti." << endl;
    }

    void tampilkanAffordance()
    {
        cout << "Affordance Analysis Bagian Mobil:" << endl;
        for (const auto &part : bagianMobil)
        {
            cout << "- " << part.name << ": " << part.affordance << endl;
        }
    }
};

int main()
{
    Mobil mobilAbid;

    mobilAbid.tambahMobil("HONDA");
    mobilAbid.tambahMobil("SUZUKI");
    mobilAbid.tambahMobil("TESLA");

    mobilAbid.tampilkanMobil();
    cout << endl;

    mobilAbid.jalan();
    mobilAbid.berhenti();
    cout << endl;

    mobilAbid.tampilkanAffordance();

    return 0;
}

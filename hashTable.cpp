#include <iostream>
using namespace std;

const int TABLE_SIZE = 8;

struct Mobil
{
    string nama;
    Mobil *next;
};

class HashTable
{
private:
    Mobil *table[TABLE_SIZE];

    int hashFunction(const string &key)
    {
        int hash = 0;
        for (char c : key)
        {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            table[i] = nullptr;
        }
    }

    void tambah(const string &nama)
    {
        int index = hashFunction(nama);
        Mobil *newMobil = new Mobil{nama, nullptr};

        if (table[index] == nullptr)
        {
            table[index] = newMobil;
        }
        else
        {
            newMobil->next = table[index];
            table[index] = newMobil;
        }
    }

    void tampilkan()
    {
        cout << "Isi Hash Table Mobil:" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != nullptr)
            {
                cout << "Rak " << i << ":" << endl;
                Mobil *current = table[i];
                while (current != nullptr)
                {
                    cout << " - " << current->nama << endl;
                    current = current->next;
                }
            }
        }
    }

    void cari(const string &nama)
    {
        int index = hashFunction(nama);
        Mobil *current = table[index];
        while (current != nullptr)
        {
            if (current->nama == nama)
            {
                cout << "Mobil " << nama << " ada." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Mobil " << nama << " tidak ada." << endl;
    }
};

int main()
{
    HashTable mobil;

    mobil.tambah("HONDA");
    mobil.tambah("SUZUKI");
    mobil.tambah("TESLA");
    mobil.tambah("KIA");
    mobil.tambah("MAZDA");

    mobil.tampilkan();

    cout << endl;

    mobil.cari("TESLA");
    mobil.cari("KIA");
    mobil.cari("HONDA");
    mobil.cari("BMW");
}
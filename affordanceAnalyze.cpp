#include <iostream>
#include <vector>
using namespace std;

struct Part
{
    string name;
    string affordance;
};

int main()
{
    vector<Part> Bagianmobil = {
        {"Roda", "Bergerak maju/mundur/belok"},
        {"Rem", "Menghentikan mobil"},
        {"Setir", "Mengarahkan mobil"},
        {"Mesin", "Menggerakkan mobil"},
        {"Lampu", "Menerangi jalan / Memberi sinyal"},
        {"Spion", "Melihat area belakang/samping"},
        {"Klakson", "Memberi peringatan suara"},
        {"Pintu", "Akses keluar/masuk mobil"},
        {"Kaca", "Memberi pandangan keluar"}};

    cout << "Affordance Analysis Bagian Mobil:" << endl;
    for (const auto &part : Bagianmobil)
    {
        cout << "- " << part.name << ": " << part.affordance << endl;
    }

    return 0;
}
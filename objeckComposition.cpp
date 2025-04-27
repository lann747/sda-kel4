#include <iostream>
using namespace std;

class Mesin
{
public:
    void nyalakan()
    {
        cout << "Mesin dinyalakan." << endl;
    }
    void matikan()
    {
        cout << "Mesin dimatikan." << endl;
    }
};

class Ban
{
public:
    void berputar()
    {
        cout << "Ban berputar." << endl;
    }
};

class Rem
{
public:
    void gunakan()
    {
        cout << "Rem digunakan." << endl;
    }
};

class Mobil
{
private:
    Mesin mesin;
    Ban ban;
    Rem rem;

public:
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
};

int main()
{
    Mobil mobilAbid;
    mobilAbid.jalan();
    mobilAbid.berhenti();

    return 0;
}

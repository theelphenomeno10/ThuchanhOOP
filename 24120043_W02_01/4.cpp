#include <iostream>
#include <cstring>

using namespace std;

class SoNguyenLon
{
private:
    char *snl = nullptr;

public:
    SoNguyenLon();
    SoNguyenLon(const char *s);
    SoNguyenLon(const int &so, const int &lanLap);

    SoNguyenLon Tru(const SoNguyenLon &snl);

    void In(ostream &os);
};

SoNguyenLon::SoNguyenLon()
{
    snl = new char[2];
    strcpy_s(snl, 2, "0");
}

SoNguyenLon::SoNguyenLon(const char *s)
{
    int doDai = strlen(s);
    snl = new char[doDai + 1];
    strcpy_s(snl, doDai + 1, s);
}

SoNguyenLon::SoNguyenLon(const int &so, const int &lanLap)
{
    snl = new char[lanLap + 1];
    for (int i = 0; i < lanLap; i++)
    {
        snl[i] = '0' + so;
    }
    snl[lanLap] = '\0';
}

SoNguyenLon SoNguyenLon::Tru(const SoNguyenLon &snl)
{
    int soBiTru = 0, soTru = 0;
}

void SoNguyenLon::In(ostream &os)
{
    os << snl;
}

int main()
{
    SoNguyenLon snl1;
    SoNguyenLon snl2("1234567");
    SoNguyenLon snl3(3, 14);
    SoNguyenLon snl4(9, 20);
    snl1.In(cout);
    cout << endl;
    snl2.In(cout);
    cout << endl;
    snl3.In(cout);
    cout << endl;
    snl4.In(cout);
    cout << endl;
}
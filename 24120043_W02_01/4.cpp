#include <iostream>
#include <cstring>

using namespace std;

class SoNguyenLon
{
private:
    char *_snl = nullptr;

public:
    SoNguyenLon();
    SoNguyenLon(const char *s);
    SoNguyenLon(const int &so, const int &lanLap);

    SoNguyenLon Tru(const SoNguyenLon &snl);

    void In(ostream &os);
};

SoNguyenLon::SoNguyenLon()
{
    _snl = new char[2];
    strcpy_s(_snl, 2, "0");
}

SoNguyenLon::SoNguyenLon(const char *s)
{
    int doDai = strlen(s);
    _snl = new char[doDai + 1];
    strcpy_s(_snl, doDai + 1, s);
}

SoNguyenLon::SoNguyenLon(const int &so, const int &lanLap)
{
    _snl = new char[lanLap + 1];
    for (int i = 0; i < lanLap; i++)
    {
        _snl[i] = '0' + so;
    }
    _snl[lanLap] = '\0';
}

SoNguyenLon SoNguyenLon::Tru(const SoNguyenLon &s)
{
    char *soBiTru;
    char *soTru;

    int doDai1 = 0, doDai2 = 0;
    bool isNegative = strcmp(s._snl, _snl) == -1;
    if (isNegative)
    {
        doDai1 = strlen(s._snl);
        doDai2 = strlen(_snl);

        soBiTru = new char[doDai1 + 1];
        soTru = new char[doDai2 + 1];

        strcpy_s(soBiTru, doDai1 + 1, s._snl);
        strcpy_s(soTru, doDai2 + 1, _snl);
    }
    else
    {
        doDai1 = strlen(_snl);
        doDai2 = strlen(s._snl);

        soBiTru = new char[doDai1 + 1];
        soBiTru = new char[doDai2 + 1];

        strcpy_s(soBiTru, doDai1 + 1, _snl);
        strcpy_s(soTru, doDai2 + 1, s._snl);
    }

    int i1 = doDai1, i2 = doDai2;
    int carry = 0, a, b, k = 0;
    char *res = new char[doDai1 + 2];
    while (carry > 0 || i1 > 0 || i2 > 0)
    {
        a = soBiTru[i1] - '0';
        b = i2 < 0 ? 0 : soTru[i2] - '0';
    }
}

void SoNguyenLon::In(ostream &os)
{
    os << _snl;
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
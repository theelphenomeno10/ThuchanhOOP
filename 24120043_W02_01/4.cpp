#include <iostream>
#include <cstring>

using namespace std;

class SoNguyenLon
{
private:
    char *_snl = nullptr;
    static SoNguyenLon snlNhat;

public:
    SoNguyenLon();
    SoNguyenLon(const long long& ll);
    SoNguyenLon(const char *s);
    SoNguyenLon(const int &so, const int &lanLap);

    SoNguyenLon Tru(const SoNguyenLon &snl);
    int SoSanh(const SoNguyenLon& b);
    SoNguyenLon Cong(const long long &snl);

    static SoNguyenLon HieuVoiHangSo(const int& s, const SoNguyenLon& snl);
    static SoNguyenLon SNLMax();

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

    if (SoSanh(snlNhat) > 0){
        snlNhat = *this;
    }
}

SoNguyenLon::SoNguyenLon(const int &so, const int &lanLap)
{
    _snl = new char[lanLap + 1];
    for (int i = 0; i < lanLap; i++)
    {
        _snl[i] = '0' + so;
    }
    _snl[lanLap] = '\0';

    if (SoSanh(snlNhat) > 0){
        snlNhat = *this;
    }
}

int SoNguyenLon::SoSanh(const SoNguyenLon &b){
    if (strlen(_snl) != strlen(b._snl)){
        if (strlen(_snl) > strlen(b._snl)){
            return 1;
        } else {
            return -1;
        }
    }

    return strcmp(_snl, b._snl);
}

SoNguyenLon SoNguyenLon::Tru(const SoNguyenLon &s)
{
    const char *soBiTru;
    const char *soTru;

    bool isNegative = SoSanh(s) < 0;
    if (isNegative)
    {
        SoNguyenLon a("0");
        return a;
    }
    else
    {
        soBiTru = _snl;
        soTru = s._snl;
    }

    int i1 = strlen(soBiTru) - 1, i2 = strlen(soTru) - 1;
    int muon = 0, a, b, k = 0;
    char *res = new char[i1 + 2];
    while (i1 >= 0 || i2 >= 0)
    {
        a = i1 < 0 ? 0 : soBiTru[i1] - '0';
        b = i2 < 0 ? 0 : soTru[i2] - '0';

        a -= muon;
        if (a < b){
            a += 10;
            muon = 1;
        } else {
            muon = 0;
        }

        res[k++] = (a - b) + '0';
        i1--;
        i2--;
    }

    while (k > 1 && res[k - 1] == '0')
    {
        k--;
    }

    res[k] = '\0';

    for (int i = 0; i < k / 2; i++)
    {
        swap(res[i], res[k - i - 1]);
    }

    SoNguyenLon result(res);
    delete[] res;

    if (SoSanh(snlNhat) > 0){
        snlNhat = result;
    }

    return result;
}

SoNguyenLon SoNguyenLon::Cong(const long long &ll)
{
    char* s = new char[31];
    sprintf(s, "%lld", ll);

    char* res = new char[max(strlen(_snl), strlen(s)) + 1];

    int i1 = strlen(_snl) - 1, i2 = strlen(s) - 1, du = 0, k = 0;

    while (i1 >= 0 || i2 >= 0){
        int a = i1 < 0 ? 0 : _snl[i1] - '0';
        int b = i2 < 0 ? 0 : s[i2] - '0';

        res[k++] = (a + b + du) % 10 + '0';
        du = (a + b + du) / 10;

        i1--;
        i2--;
    }

    if (du > 0){
        res[k++] = '1';
    }

    res[k] = '\0';

    for (int i = 0; i < k / 2; i++){
        swap(res[i], res[k - i - 1]);
    }

    SoNguyenLon result(res);
    delete[] s;
    delete[] res;

    if (SoSanh(snlNhat) > 0){
        snlNhat = result;
    }

    return result;
}

SoNguyenLon SoNguyenLon::HieuVoiHangSo(const int& x, const SoNguyenLon& snl)
{
    int n = x;
    char *s = new char [31];
    sprintf(s, "%d", n);

    SoNguyenLon a(s);
    delete[] s;
    return a.Tru(snl);
}

SoNguyenLon SoNguyenLon::SNLMax(){
    return snlNhat;
}

SoNguyenLon snl;
SoNguyenLon SoNguyenLon::snlNhat = snl;

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
    SoNguyenLon snl5 = snl3.Tru(snl2);
    SoNguyenLon snl6 = SoNguyenLon::HieuVoiHangSo(45678910, snl2);
    SoNguyenLon snl7 = snl4.Tru(snl3).Cong(123456789);
    snl1.In(cout);
    cout << endl;
    snl2.In(cout);
    cout << endl;
    snl3.In(cout);
    cout << endl;
    snl4.In(cout);
    cout << endl;
    snl5.In(cout);
    cout << endl;
    snl6.In(cout);
    cout << endl;
    snl7.In(cout);
    cout << endl;

    cout << "SoNguyenLon Max:" << endl;
    SoNguyenLon::SNLMax().In(cout);
    cout << endl;
    system("pause");

    return 0;
}
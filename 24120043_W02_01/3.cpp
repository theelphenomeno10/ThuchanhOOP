#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class HocSinh
{
private:
    static int _dem;
    static HocSinh hsDiemTBCaoNhat;
    char *_hoTen;
    char *_mssv;
    float _diem[3];

public:
    HocSinh();
    HocSinh(const char *s, const int &diem1, const int &diem2, const int &diem3);

    static HocSinh HSDiemTBCaoNhat();

    void ChuanHoaDiem();
    void DatHoTen(const char *s);
    void GanDiem(const int &diem1, const int &diem2, const int &diem3);
    void In(ostream &os);
};

HocSinh::HocSinh()
{
    _hoTen = nullptr;

    _dem++;
    int mssv = 23120000 + _dem;
    _mssv = new char[8];
    sprintf(_mssv, "%d", mssv);

    for (int i = 0; i < 3; i++)
    {
        _diem[i] = 0;
    }
}

HocSinh::HocSinh(const char *s, const int &diem1, const int &diem2, const int &diem3)
{
    int doDai = strlen(s);
    _hoTen = new char[doDai + 1];
    strcpy_s(_hoTen, doDai + 1, s);

    _dem++;
    int mssv = 23120000 + _dem;
    _mssv = new char[8];
    sprintf(_mssv, "%d", mssv);

    _diem[0] = diem1;
    _diem[1] = diem2;
    _diem[2] = diem3;

    ChuanHoaDiem();

    if ((_diem[0] + _diem[1] + _diem[2]) / 3 >
        (hsDiemTBCaoNhat._diem[0] + hsDiemTBCaoNhat._diem[1] + hsDiemTBCaoNhat._diem[2]) / 3)
    {
        hsDiemTBCaoNhat = *this;
    }
}

void HocSinh::ChuanHoaDiem()
{
    for (int i = 0; i < 3; i++)
    {
        _diem[i] = abs(_diem[i]);
        if (_diem[i] > 10)
        {
            _diem[i] = 10;
        }
    }
}

void HocSinh::DatHoTen(const char *s)
{
    int doDai = strlen(s);
    _hoTen = new char[doDai + 1];
    strcpy_s(_hoTen, doDai + 1, s);
}

void HocSinh::GanDiem(const int &diem1, const int &diem2, const int &diem3)
{
    _diem[0] = diem1;
    _diem[1] = diem2;
    _diem[2] = diem3;

    ChuanHoaDiem();

    if ((_diem[0] + _diem[1] + _diem[2]) / 3 >
        (hsDiemTBCaoNhat._diem[0] + hsDiemTBCaoNhat._diem[1] + hsDiemTBCaoNhat._diem[2]) / 3)
    {
        hsDiemTBCaoNhat = *this;
    }
}

void HocSinh::In(ostream &os)
{
    float dtb = 0;
    for (int i = 0; i < 3; i++)
    {
        dtb += _diem[i];
    }
    dtb /= 3;

    os << fixed << setprecision(2) << "HS: " << _hoTen << ", MS: " << _mssv << ", DTB: " << dtb;
}

HocSinh HocSinh::HSDiemTBCaoNhat()
{
    return hsDiemTBCaoNhat;
}

int HocSinh::_dem = 0;
HocSinh hs;
HocSinh HocSinh::hsDiemTBCaoNhat = hs;

int main()
{
    HocSinh hs1;
    hs1.DatHoTen("Nguyen Van A");
    hs1.GanDiem(7, 8, 10);
    HocSinh hs2("Tran Thi B", 5, 8, 4.5);
    HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
    HocSinh hs4("Le Van D", 7.5, 9, -10);
    hs1.In(cout);
    cout << endl;
    hs2.In(cout);
    cout << endl;
    hs3.In(cout);
    cout << endl;
    hs4.In(cout);
    cout << endl;
    cout << "Hoc sinh co diem TB cao nhat:" << endl;
    HocSinh::HSDiemTBCaoNhat().In(cout);
    cout << endl;

    system("pause");
    return 0;
}
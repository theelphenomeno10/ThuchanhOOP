#include "SLList.hpp"
#include <algorithm>

using namespace std;

class SoNguyenLon
{
private:
    SLList<unsigned char> lCS;
    void Pow10(const int &n);

public:
    SoNguyenLon(void);
    SoNguyenLon(const int &cs, const int &scs);
    SoNguyenLon(const unsigned long &n);
    SoNguyenLon(const char *s);
    ~SoNguyenLon(void);

    int SoCS();
    SoNguyenLon operator+(SoNguyenLon snl);
    SoNguyenLon operator-(SoNguyenLon snl);
    SoNguyenLon operator*(SoNguyenLon snl);
    bool operator>(SoNguyenLon &snl);
    const SoNguyenLon &operator=(const SoNguyenLon &snl);
    SoNguyenLon &operator+=(SoNguyenLon snl);
    friend SoNguyenLon operator+(const unsigned int &n, const SoNguyenLon &snl);
    friend SoNguyenLon operator-(const unsigned int &n, const SoNguyenLon &snl);
    friend ostream &operator<<(ostream &os, const SoNguyenLon &snl);
};

void SoNguyenLon::Pow10(const int &n)
{
    for (int i = 0; i < n; ++i)
    {
        lCS.insert(lCS.begin(), 0);
    }
}

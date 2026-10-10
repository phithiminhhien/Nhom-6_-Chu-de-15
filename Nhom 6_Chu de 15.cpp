#include <iostream>
#include <string>
using namespace std;

class Ngay
{
private:
    int ngay, thang, nam;

public:
    void nhap();
    void xuat();
    bool nhoHon(Ngay x);
};

void Ngay::nhap()
{
    char dau;
    cout << "Nhap ngay (dd/mm/yyyy): ";
    cin >> ngay >> dau >> thang >> dau >> nam;
}

void Ngay::xuat()
{
    if (ngay < 10) cout << "0";
    cout << ngay << "/";

    if (thang < 10) cout << "0";
    cout << thang << "/" << nam;
}

bool Ngay::nhoHon(Ngay x)
{
    if (nam != x.nam)
        return nam < x.nam;

    if (thang != x.thang)
        return thang < x.thang;

    return ngay < x.ngay;
}

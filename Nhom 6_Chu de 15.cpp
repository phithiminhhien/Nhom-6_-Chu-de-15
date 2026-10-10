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

class HopDong
{
private:
    string maHD, hoTen, loaiHD;
    Ngay ngayKy, ngayHetHan;
    long long luongCoBan, phuCap;

public:
    void nhap();
    void xuat();
    void xuatDong(int stt);

    string getMaHD();
    bool hetHanTruoc(HopDong x);
};

void HopDong::nhap()
{
    cin.ignore();

    cout << "Nhap ma hop dong: ";
    getline(cin, maHD);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap loai hop dong: ";
    getline(cin, loaiHD);

    cout << "Nhap ngay ky:\n";
    ngayKy.nhap();

    cout << "Nhap ngay het han:\n";
    ngayHetHan.nhap();

    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;

    cout << "Nhap phu cap: ";
    cin >> phuCap;
}

void HopDong::xuat()
{
    cout << "Ma HD: " << maHD << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Loai HD: " << loaiHD << endl;

    cout << "Ngay ky: ";
    ngayKy.xuat();

    cout << "\nNgay het han: ";
    ngayHetHan.xuat();

    cout << "\nLuong co ban: " << luongCoBan;
    cout << "\nPhu cap: " << phuCap << endl;
}

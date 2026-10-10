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

string HopDong::getMaHD()
{
    return maHD;
}

bool HopDong::hetHanTruoc(HopDong x)
{
    return ngayHetHan.nhoHon(x.ngayHetHan);
}

void trai(string s, int rong)
{
    if (s.length() > rong)
    {
        cout << s.substr(0, rong - 3) << "...";
    }
    else
    {
        cout << s;

        for (int i = s.length(); i < rong; i++)
            cout << " ";
    }
}

void phai(long long x, int rong)
{
    string s = to_string(x);

    for (int i = s.length(); i < rong; i++)
        cout << " ";

    cout << s;
}

void HopDong::xuatDong(int stt)
{
    cout << "| ";
    phai(stt, 3);

    cout << " | ";
    trai(maHD, 7);

    cout << " | ";
    trai(hoTen, 16);

    cout << " | ";
    trai(loaiHD, 10);

    cout << " | ";
    ngayKy.xuat();

    cout << " | ";
    ngayHetHan.xuat();

    cout << " | ";
    phai(luongCoBan, 11);

    cout << " | ";
    phai(phuCap, 9);

    cout << " |\n";
}

void xuatBang(HopDong ds[], int n)
{
    cout << "\n=====================================================================================================\n";

    cout << "| ";
    trai("STT", 3);
    cout << " | ";
    trai("MA HD", 7);
    cout << " | ";
    trai("HO TEN", 16);
    cout << " | ";
    trai("LOAI HD", 10);
    cout << " | ";
    trai("NGAY KY", 10);
    cout << " | ";
    trai("NGAY HET", 10);
    cout << " | ";
    trai("LUONG CB", 11);
    cout << " | ";
    trai("PHU CAP", 9);
    cout << " |\n";

    cout << "=====================================================================================================\n";

    for (int i = 0; i < n; i++)
        ds[i].xuatDong(i + 1);

    cout << "=====================================================================================================\n";
}

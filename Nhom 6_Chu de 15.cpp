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

void boSung(HopDong ds[], int &n)
{
    int viTri;

    if (n >= 199)
    {
        cout << "Danh sach da day!\n";
        return;
    }

    cout << "Nhap vi tri can bo sung (1 -> " << n + 1 << "): ";
    cin >> viTri;

    if (viTri < 1 || viTri > n + 1)
    {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    for (int i = n; i >= viTri; i--)
        ds[i] = ds[i - 1];

    cout << "\nNhap hop dong moi:\n";
    ds[viTri - 1].nhap();

    n++;

    cout << "\nBo sung thanh cong!\n";
}

void xoa(HopDong ds[], int &n)
{
    int viTri;

    if (n == 0)
    {
        cout << "Danh sach rong!\n";
        return;
    }

    cout << "Nhap vi tri can xoa (1 -> " << n << "): ";
    cin >> viTri;

    if (viTri < 1 || viTri > n)
    {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    for (int i = viTri - 1; i < n - 1; i++)
        ds[i] = ds[i + 1];

    n--;

    cout << "\nXoa thanh cong!\n";
}

int main()
{
    HopDong ds[200];
    int n = 0;
    int chon;

    do
    {
        cout << "\n\n==================== MENU ====================\n";
        cout << "1. Nhap danh sach hop dong\n";
        cout << "2. In danh sach hop dong\n";
        cout << "3. Sap xep theo ngay het han tang dan\n";
        cout << "4. Tim kiem theo ma hop dong\n";
        cout << "5. Bo sung hop dong\n";
        cout << "6. Xoa hop dong\n";
        cout << "0. Thoat\n";
        cout << "===============================================\n";

        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon)
        {
        case 1:
            nhapDanhSach(ds, n);
            break;

        case 2:
            xuatBang(ds, n);
            break;

        case 3:
            sapXep(ds, n);
            break;

        case 4:
            timKiem(ds, n);
            break;

        case 5:
            boSung(ds, n);
            break;

        case 6:
            xoa(ds, n);
            break;

        case 0:
            cout << "\nKet thuc chuong trinh!\n";
            break;

        default:
            cout << "\nLua chon khong hop le!\n";
        }

    }
    while (chon != 0);

    return 0;
}

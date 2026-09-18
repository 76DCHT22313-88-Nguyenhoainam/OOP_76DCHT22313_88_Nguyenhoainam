#include<iostream>
#include<string>
using namespace std;

//CAU 1: KHAI BAO LOP
class nguoi {
    protected: 
        string hoten;
        int nsinh;
    public:
        void nhap();
        void xuat();
};
class SinhVien: public nguoi {
    private: 
        string msv;
        float dtb;
    public:
        void nhap();
        void xuat();
        string getMsv();
        string getHoTen();
};

//CAU 2: XAY DUNG PHUONG THUC
void nguoi::nhap() {
    cout << "Nhap hoten: "; getline(cin, hoten);
    cout << "Nhap nsinh: "; cin >> nsinh;
    cin.ignore(); 
}

void nguoi::xuat() {
    cout << "Ho ten: " << hoten << " | Nam sinh: " << nsinh;
}

void SinhVien::nhap() {
    nguoi::nhap(); 
    cout << "Nhap msv: "; getline(cin, msv);
    cout << "Nhap dtb: "; cin >> dtb;
}

void SinhVien::xuat() {
    nguoi::xuat(); 
    cout << " | Ma SV: " << msv << " | Diem TB: " << dtb << endl;
}

string SinhVien::getMsv() {
    return msv;
}

string SinhVien::getHoTen() {
    return hoten;
}
int main()
{
    // Tao thu 1 doi tuong
    cout << "--- TEST NHAP XUAT 1 SINH VIEN ---" << endl;
    SinhVien sv;
    
    sv.nhap();
    
    cout << "\n--- KET QUA ---" << endl;
    sv.xuat();

    return 0;
}

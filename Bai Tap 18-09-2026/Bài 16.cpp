#include<iostream>
#include<string>
using namespace std;

//CAU 1: KHAI BAO LOP
class MonHoc {
    protected: 
        string tenMon;
        float diemCC, diemKT, diemThi;
    public:
        void nhap();
        void xuat();
};

class SinhVien : public MonHoc {
    private: 
        string hoTen, lop, msv;
    public:
        void nhap();
        void xuat();
        float tinhDiemHP(); 
        float getDiemCC();
        float getDiemKT();
};

//CAU 2: XAY DUNG PHUONG THUC
void MonHoc::nhap() {
    cout << "Nhap ten mon hoc: "; getline(cin, tenMon);
    cout << "Nhap diem chuyen can (CC): "; cin >> diemCC;
    cout << "Nhap diem kiem tra (KT): "; cin >> diemKT;
    cout << "Nhap diem thi (DT): "; cin >> diemThi;
    cin.ignore(); // Xoa ki tu Enter sau khi nhap diem
}

void MonHoc::xuat() {
    cout << "Mon: " << tenMon << " | Diem CC: " << diemCC << " | Diem KT: " << diemKT << " | Diem Thi: " << diemThi;
}

void SinhVien::nhap() {
    cout << "Nhap ho ten sinh vien: "; getline(cin, hoTen);
    cout << "Nhap lop: "; getline(cin, lop);
    cout << "Nhap ma sinh vien: "; getline(cin, msv);
    MonHoc::nhap(); // Goi ham nhap thong tin diem cua lop cha
}

void SinhVien::xuat() {
    cout << "SV: " << hoTen << " - " << msv << " - Lop: " << lop << " | ";
    MonHoc::xuat(); // In thong tin diem cua lop cha
    cout << " | Diem HP: " << tinhDiemHP() << endl;
}

float SinhVien::tinhDiemHP() {
    // Gia su cong thuc la: 20% CC + 30% KT + 50% Thi
   
    return diemCC * 0.2 + diemKT * 0.3 + diemThi * 0.5;
}

float SinhVien::getDiemCC() {
    return diemCC;
}

float SinhVien::getDiemKT() {
    return diemKT;
}
int main()
{
    // Chay thu
    cout << "--- TEST NHAP XUAT 1 SINH VIEN ---" << endl;
    SinhVien sv;
    sv.nhap();
    
    cout << "\n--- THONG TIN VUA NHAP ---" << endl;
    sv.xuat();

    return 0;
}

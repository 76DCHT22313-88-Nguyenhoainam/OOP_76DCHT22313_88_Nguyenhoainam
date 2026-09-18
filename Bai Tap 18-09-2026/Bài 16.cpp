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
    cin.ignore(); 
}

void MonHoc::xuat() {
    cout << "Mon: " << tenMon << " | Diem CC: " << diemCC << " | Diem KT: " << diemKT << " | Diem Thi: " << diemThi;
}

void SinhVien::nhap() {
    cout << "Nhap ho ten sinh vien: "; getline(cin, hoTen);
    cout << "Nhap lop: "; getline(cin, lop);
    cout << "Nhap ma sinh vien: "; getline(cin, msv);
    MonHoc::nhap(); 
}

void SinhVien::xuat() {
    cout << "SV: " << hoTen << " - " << msv << " - Lop: " << lop << "\n   -> ";
    MonHoc::xuat(); 
    cout << " | Diem HP: " << tinhDiemHP() << endl;
}

float SinhVien::tinhDiemHP() {
    return diemCC * 0.2 + diemKT * 0.3 + diemThi * 0.5;
}

float SinhVien::getDiemCC() {
    return diemCC;
}

float SinhVien::getDiemKT() {
    return diemKT;
}

//CAU 3: MAIN (DANH SACH CAM THI)
int main()
{
    int n;
    SinhVien ds[100];
    
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore(); 

    // 1. Nhap thong tin n sinh vien
    for(int i = 0; i < n; i++){
        cout << "\n--- Nhap thong tin sinh vien thu " << i+1 << " ---" << endl;
        ds[i].nhap();
    }

    cout << "\n================ DANH SACH SINH VIEN BI CAM THI ================" << endl;
    cout << "(Dieu kien: Diem chuyen can duoi 5 hoac diem kiem tra bang 0)" << endl;
    
    bool coNguoiCamThi = false; // Bien dung de kiem tra xem co sinh vien nao bi cam khong

    for(int i = 0; i < n; i++){
        // Xet dieu kien cam thi dua theo bai toan
        if(ds[i].getDiemCC() < 5 || ds[i].getDiemKT() == 0){
            ds[i].xuat();
            coNguoiCamThi = true;
        }
    }

    if(coNguoiCamThi == false){
        cout << "Tot qua! Khong co sinh vien nao bi cam thi trong danh sach." << endl;
    }

    return 0;
}

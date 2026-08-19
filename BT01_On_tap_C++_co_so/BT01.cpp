#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    float luongCoBan;
    float heSo;
};

void nhapThongTin(NhanVien &nv) {
    cout << "Nhap ma NV: ";
    cin >> nv.maNV;
    cin.ignore(); 
    cout << "Nhap ten NV: ";
    getline(cin, nv.tenNV);
    cout << "Nhap luong co ban: ";
    cin >> nv.luongCoBan;
    cout << "Nhap he so: ";
    cin >> nv.heSo;
}

void nhapDanhSach(NhanVien ds[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "\n--- Nhan vien " << i+1 << " ---\n";
        nhapThongTin(ds[i]);
    }
}

void xuatThongTin(NhanVien nv) {
    cout << "Ma NV: " << nv.maNV << " | Ten NV: " << nv.tenNV 
         << " | Luong: " << nv.luongCoBan << " | He so: " << nv.heSo << endl;
}

void xuatDanhSach(NhanVien ds[], int n) {
    cout << "\n--- DANH SACH ---\n";
    for(int i = 0; i < n; i++) {
        xuatThongTin(ds[i]);
    }
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    NhanVien dsNV[100]; 
    
    nhapDanhSach(dsNV, n);
    xuatDanhSach(dsNV, n);
    
    return 0;
}
// Hoan thanh bai tap

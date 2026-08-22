#include <iostream>
#include <string>
using namespace std;

class NhanVien {
public:
    string manv;
    string hoten;
    string ngaysinh;
    string diachi;

    void nhap() {
        cout << "Nhap ma nhan vien: ";
        getline(cin, manv);
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngaysinh);
        cout << "Nhap dia chi: ";
        getline(cin, diachi);
    }

    void xuat() {
        cout << "- " << manv << " | " << hoten << " | " << ngaysinh << " | " << diachi << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien ban muon them: ";
    cin >> n;
    
    cin.ignore(); 

    NhanVien dsnv[100]; 

    for(int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN CHO NHAN VIEN THU " << i + 1 << " ===" << endl;
        dsnv[i].nhap();
    }

    cout << "\n=== DANH SACH NHAN VIEN CUA CONG TY ===" << endl;
    for(int i = 0; i < n; i++) {
        dsnv[i].xuat();
    }

    return 0;
}
// Hoan thanh

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class NhanVien {
public:
    string manv, hoten, ngaysinh, diachi;

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
    cout << "[CACH 3 - VECTOR] Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore(); 

    vector<NhanVien> dsnv; 

    for(int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN CHO NHAN VIEN THU " << i + 1 << " ===" << endl;
        
        NhanVien nv_tam;  
        nv_tam.nhap();   
        
        dsnv.push_back(nv_tam);
    }

    cout << "\n=== DANH SACH NHAN VIEN CUA CONG TY ===" << endl;
    for(int i = 0; i < dsnv.size(); i++) {
        dsnv[i].xuat();
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

class NhanVien {
public:
    string manv, hoten, ngaysinh, diachi;

    NhanVien() {
        manv = "";
        hoten = "";
        ngaysinh = "";
        diachi = "";
    }

    NhanVien(string ma, string ten, string ngay, string dc) {
        manv = ma;
        hoten = ten;
        ngaysinh = ngay;
        diachi = dc;
    }

    void xuatTheoCot() {
        cout << left << setw(15) << manv 
             << setw(25) << hoten 
             << setw(15) << ngaysinh 
             << setw(20) << diachi << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore(); 

    vector<NhanVien> dsnv;

    for(int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN CHO NHAN VIEN THU " << i + 1 << " ===" << endl;
        
        string ma_tam, ten_tam, ngay_tam, dc_tam;

        cout << "Nhap ma nhan vien: ";
        getline(cin, ma_tam);
        cout << "Nhap ho ten: ";
        getline(cin, ten_tam);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngay_tam);
        cout << "Nhap dia chi: ";
        getline(cin, dc_tam);

        NhanVien nv(ma_tam, ten_tam, ngay_tam, dc_tam);
        
        dsnv.push_back(nv);
    }

    cout << "\n\n========================= DANH SACH NHAN VIEN =========================" << endl;
    
    cout << left << setw(15) << "MA NV" 
         << setw(25) << "HO TEN" 
         << setw(15) << "NGAY SINH" 
         << setw(20) << "DIA CHI" << endl;
         
    cout << setfill('-') << setw(75) << "-" << endl; 
    cout << setfill(' '); 

    for(int i = 0; i < dsnv.size(); i++) {
        dsnv[i].xuatTheoCot();
    }

    return 0;
}

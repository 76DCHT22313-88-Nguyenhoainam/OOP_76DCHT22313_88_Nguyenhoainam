#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5]; 

public:
    void nhap() {
        cin.ignore(); 
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        
        cout << "Nhap diem 5 mon hoc:" << endl;
        for(int i = 0; i < 5; i++) {
            cout << " - Diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    float tinhDTB() {
        float tong = 0;
        for(int i = 0; i < 5; i++) {
            tong = tong + diem[i];
        }
        return tong / 5.0; 
    }

    void xuat() {
        cout << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << tinhDTB() << endl;
    }

    // Cau 3: Phuong thuc kiem tra va in thong tin mon thi lai (< 5)
    void inThongTinThiLai() {
        bool phaiThiLai = false;
        
        for(int i = 0; i < 5; i++) {
            if(diem[i] < 5.0) {
                phaiThiLai = true;
                break; 
            }
        }
        
        if(phaiThiLai == true) {
            cout << "\n* Sinh vien: " << hoTen << " (Nam sinh: " << namSinh << ")" << endl;
            cout << "  Cac mon phai thi lai:" << endl;
            for(int i = 0; i < 5; i++) {
                if(diem[i] < 5.0) {
                    cout << "  - Mon " << i + 1 << ": " << diem[i] << " diem" << endl;
                }
            }
        }
    }
}; 

// Cau 3: Nhap n sinh vien va in thong tin thi lai
int main() {
    int n;
    SinhVien ds[100]; 

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN SINH VIEN THU " << i + 1 << " ===" << endl;
        ds[i].nhap();
    }

    cout << "\n================ DANH SACH SINH VIEN PHAI THI LAI ================" << endl;
    for(int i = 0; i < n; i++) {
        ds[i].inThongTinThiLai();
    }

    return 0;
}

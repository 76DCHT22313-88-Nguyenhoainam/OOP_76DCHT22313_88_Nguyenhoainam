#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5];

public:
    // Cau 2: Phuong thuc nhap
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

    // Cau 2: Phuong thuc tinh diem trung binh
    float tinhDTB() {
        float tong = 0;
        for(int i = 0; i < 5; i++) {
            tong = tong + diem[i];
        }
        return tong / 5.0; 
    }

    // Cau 2: Phuong thuc xuat
    void xuat() {
        cout << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << tinhDTB() << endl;
    }
};

int main() {
    SinhVien sv;
    cout << "--- TEST NHAP 1 SINH VIEN ---" << endl;
    sv.nhap();
    cout << "\n--- THONG TIN VUA NHAP ---" << endl;
    sv.xuat();
    return 0;
}

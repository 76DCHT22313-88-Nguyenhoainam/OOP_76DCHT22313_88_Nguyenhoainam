#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    // Cau 2: Phuong thuc nhap
    void nhap() {
        cin.ignore(); 
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        
        cout << "Nhap diem 4 mon hoc:" << endl;
        // Vong lap chi chay 4 lan
        for(int i = 0; i < 4; i++) {
            cout << " - Diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    // Cau 2: Phuong thuc tinh diem trung binh
    float tinhDTB() {
        float tong = 0;
        for(int i = 0; i < 4; i++) {
            tong = tong + diem[i];
        }
        return tong / 4.0; // Chia 4 vi chi co 4 mon
    }

    // Cau 2: Phuong thuc xuat
    void xuat() {
        cout << "- " << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << tinhDTB() << endl;
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

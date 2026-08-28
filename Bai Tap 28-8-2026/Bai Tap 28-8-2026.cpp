#include <iostream>
using namespace std;

class MaTran {
private:
    int soHang;
    int soCot;
    int pt[50][50];

public:
    // Cau 2: Phuong thuc nhap
    void nhap() {
        cout << "Nhap so hang: "; cin >> soHang;
        cout << "Nhap so cot: "; cin >> soCot;
        for(int i = 0; i < soHang; i++) {
            for(int j = 0; j < soCot; j++) {
                cout << "Phan tu [" << i << "][" << j << "] = ";
                cin >> pt[i][j];
            }
        }
    }

    // Cau 2: Phuong thuc xuat
    void xuat() {
        for(int i = 0; i < soHang; i++) {
            for(int j = 0; j < soCot; j++) {
                cout << pt[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    
    MaTran mt;
    cout << "--- NHAP MA TRAN ---" << endl;
    mt.nhap();
    cout << "--- MA TRAN VUA NHAP ---" << endl;
    mt.xuat();
    return 0;
}

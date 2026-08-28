#include <iostream>
using namespace std;

// Khai bao lop ma tran
class MaTran {
private:
    int soHang;
    int soCot;
    int pt[50][50]; // Mang 2 chieu toi da 50x50 phan tu

public:
    // Phuong thuc nhap
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

    // Phuong thuc xuat
    void xuat() {
        for(int i = 0; i < soHang; i++) {
            for(int j = 0; j < soCot; j++) {
                cout << pt[i][j] << "\t";
            }
            cout << endl; // Xuong dong khi het 1 hang
        }
    }

    // KHAI BAO HAM BAN (FRIEND)
    friend MaTran congMaTran(MaTran a, MaTran b);
};

// DINH NGHIA HAM BAN 
MaTran congMaTran(MaTran a, MaTran b) {
    MaTran kq; // Tao ma tran ket qua
    
    // Hai ma tran dong cap nen so hang va cot cua ma tran ket qua bang ma tran a
    kq.soHang = a.soHang;
    kq.soCot = a.soCot;
    
    // Cong cac phan tu tuong ung voi nhau
    for(int i = 0; i < a.soHang; i++) {
        for(int j = 0; j < a.soCot; j++) {
            kq.pt[i][j] = a.pt[i][j] + b.pt[i][j];
        }
    }
    return kq; // Tra ve ma tran tong
}

int main() {
    MaTran mt1, mt2, mtTong;

    cout << "--- NHAP MA TRAN THU 1 ---" << endl;
    mt1.nhap();

    cout << "\n--- NHAP MA TRAN THU 2 (Luu y: Nhap cung kich thuoc) ---" << endl;
    mt2.nhap();

    // Goi ham ban de cong 2 ma tran
    mtTong = congMaTran(mt1, mt2);

    cout << "\n================ KET QUA ================" << endl;
    cout << "\nMa tran 1:" << endl;
    mt1.xuat();

    cout << "\nMa tran 2:" << endl;
    mt2.xuat();

    cout << "\nMa tran TONG:" << endl;
    mtTong.xuat();

    return 0;
}

#include <iostream>
#include <cmath> 
using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    PhanSo() { tuSo = 0; mauSo = 1; }
    PhanSo(int t, int m) { tuSo = t; mauSo = m; }
    ~PhanSo() {}

    int timUCLN(int a, int b) {
        a = abs(a); b = abs(b);
        while (a * b != 0) {
            if (a > b) a = a % b;
            else b = b % a;
        }
        return a + b;
    }

    void nhap() {
        cout << "Nhap tu so: "; cin >> tuSo;
        do {
            cout << "Nhap mau so (khac 0): "; cin >> mauSo;
        } while (mauSo == 0);
    }

    void xuat() {
        if (tuSo == 0) cout << 0;
        else if (mauSo == 1) cout << tuSo;
        else cout << tuSo << "/" << mauSo;
    }

    void rutGon() {
        int ucln = timUCLN(tuSo, mauSo);
        tuSo = tuSo / ucln;
        mauSo = mauSo / ucln;
        if (mauSo < 0) { tuSo = -tuSo; mauSo = -mauSo; }
    }

    PhanSo cong(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.mauSo + mauSo * ps2.tuSo;
        kq.mauSo = mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo tru(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.mauSo - mauSo * ps2.tuSo;
        kq.mauSo = mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo nhan(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.tuSo;
        kq.mauSo = mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo chia(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.mauSo;
        kq.mauSo = mauSo * ps2.tuSo;
        kq.rutGon();
        return kq;
    }
};

// Cau 3: Thuc hien tinh toan va in ket qua
int main() {
    PhanSo ps1, ps2, kq;

    cout << "--- NHAP PHAN SO 1 ---" << endl;
    ps1.nhap();
    cout << "\n--- NHAP PHAN SO 2 ---" << endl;
    ps2.nhap();

    cout << "\n================ KET QUA ================" << endl;
    
    kq = ps1.cong(ps2);
    cout << "Phep Cong: "; kq.xuat(); cout << endl;

    kq = ps1.tru(ps2);
    cout << "Phep Tru: "; kq.xuat(); cout << endl;

    kq = ps1.nhan(ps2);
    cout << "Phep Nhan: "; kq.xuat(); cout << endl;

    kq = ps1.chia(ps2);
    cout << "Phep Chia: "; kq.xuat(); cout << endl;

    return 0;
}

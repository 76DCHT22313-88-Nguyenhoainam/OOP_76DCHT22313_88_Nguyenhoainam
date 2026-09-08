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

    void rutGon() {
        int ucln = timUCLN(tuSo, mauSo);
        tuSo = tuSo / ucln;
        mauSo = mauSo / ucln;
        if (mauSo < 0) { tuSo = -tuSo; mauSo = -mauSo; }
    }

    friend istream& operator>>(istream& is, PhanSo& ps) {
        cout << "Nhap tu so: "; is >> ps.tuSo;
        do {
            cout << "Nhap mau so (khac 0): "; is >> ps.mauSo;
        } while (ps.mauSo == 0);
        return is;
    }

    friend ostream& operator<<(ostream& os, PhanSo ps) {
        if (ps.tuSo == 0) os << 0;
        else if (ps.mauSo == 1) os << ps.tuSo;
        else os << ps.tuSo << "/" << ps.mauSo;
        return os;
    }

    // Cau 3: Nap chong cac toan tu +, -, *, /
    PhanSo operator+(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.mauSo + mauSo * ps2.tuSo;
        kq.mauSo = mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo operator-(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.mauSo - mauSo * ps2.tuSo;
        kq.mauSo = mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo operator*(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.tuSo;
        kq.mauSo = mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo operator/(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.mauSo;
        kq.mauSo = mauSo * ps2.tuSo;
        kq.rutGon();
        return kq;
    }
};

// Cau 3: Thuc hien tinh toan va in ra man hinh
int main() {
    PhanSo ps1, ps2;

    cout << "--- NHAP PHAN SO 1 ---" << endl;
    cin >> ps1; 
    
    cout << "\n--- NHAP PHAN SO 2 ---" << endl;
    cin >> ps2;

    cout << "\n================ KET QUA ================" << endl;
    
    cout << "Phep Cong: " << ps1 + ps2 << endl;
    cout << "Phep Tru: " << ps1 - ps2 << endl;
    cout << "Phep Nhan: " << ps1 * ps2 << endl;
    cout << "Phep Chia: " << ps1 / ps2 << endl;

    return 0;
}

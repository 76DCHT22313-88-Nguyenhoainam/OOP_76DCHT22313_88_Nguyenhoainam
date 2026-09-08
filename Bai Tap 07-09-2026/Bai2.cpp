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

    // Cau 2: Phuong thuc rut gon
    void rutGon() {
        int ucln = timUCLN(tuSo, mauSo);
        tuSo = tuSo / ucln;
        mauSo = mauSo / ucln;
        if (mauSo < 0) { tuSo = -tuSo; mauSo = -mauSo; }
    }

    // Cau 2: Nap chong toan tu Nhap (>>) va Xuat (<<)
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
};

int main() {
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

// Cau 1: Khai bao lop PhanSo
class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Cau 1: Ham tao va ham huy
    PhanSo() { tuSo = 0; mauSo = 1; }
    PhanSo(int t, int m) { tuSo = t; mauSo = m; }
    ~PhanSo() {}
};

int main() {
    return 0;
}

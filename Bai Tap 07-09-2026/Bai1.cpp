#include <iostream>
#include <cmath> 
using namespace std;

// Cau 1: Khai bao lop PhanSo
class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Cau 1: Ham tao khong doi (Mac dinh la 0/1)
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    // Cau 1: Ham tao co doi
    PhanSo(int t, int m) {
        tuSo = t;
        mauSo = m;
    }

    // Cau 1: Ham huy
    ~PhanSo() {
    }
};

int main() {
    return 0;
}

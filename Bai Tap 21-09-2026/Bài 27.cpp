#include<iostream>
#include<cmath>
using namespace std;

// ================= CAU 1: KHAI BAO LOP PS1 =================
class PS1 {
    protected: 
        int tuSo;
        int mauSo;
    public:
        void nhap();
        void in();
        void toiGian();
};

// ================= CAU 2: KHAI BAO LOP PS2 =================
class PS2 : public PS1 {
    public:
        PS2& operator=(const PS2& p);
        bool operator>(PS2 p);
};

// ================= XAY DUNG PHUONG THUC =================

// Ham tim Uoc chung lon nhat (UCLN) de phuc vu viec toi gian
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) return a + b;
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

void PS1::nhap() {
    cout << "Nhap tu so: "; 
    cin >> tuSo;
    
    // Yeu cau mau so khac 0
    do {
        cout << "Nhap mau so (khac 0): "; 
        cin >> mauSo;
        if (mauSo == 0) {
            cout << "Loi! Mau so phai khac 0. Vui long nhap lai.\n";
        }
    } while (mauSo == 0);
}

void PS1::toiGian() {
    int ucln = timUCLN(tuSo, mauSo);
    tuSo = tuSo / ucln;
    mauSo = mauSo / ucln;
    
    // Xu ly truong hop mau so am (VD: 1/-2 -> -1/2)
    if (mauSo < 0) {
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}

void PS1::in() {
    toiGian(); // Goi ham toi gian truoc khi in
    // Neu mau so la 1 thi chi can in tu so (VD: 5/1 -> 5)
    if (mauSo == 1) {
        cout << tuSo;
    } else {
        cout << tuSo << "/" << mauSo;
    }
}

// Nap chong toan tu gan (=)
PS2& PS2::operator=(const PS2& p) {
    this->tuSo = p.tuSo;
    this->mauSo = p.mauSo;
    return *this;
}

// Nap chong toan tu lon hon (>)
bool PS2::operator>(PS2 p) {
    // Ep kieu ve float de chia va so sanh cho nhanh, chinh xac
    float giaTri1 = (float)this->tuSo / this->mauSo;
    float giaTri2 = (float)p.tuSo / p.mauSo;
    return giaTri1 > giaTri2;
}

// ================= CHUONG TRINH CHINH =================
int main()
{
    // Chay thu phan so
    cout << "--- TEST NHAP XUAT 1 PHAN SO ---" << endl;
    PS2 psTest;
    psTest.nhap();
    cout << "Phan so vua nhap (da toi gian): ";
    psTest.in();
    cout << endl;
    return 0;
}

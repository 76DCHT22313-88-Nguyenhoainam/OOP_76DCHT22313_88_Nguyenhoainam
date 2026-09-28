#include<iostream>
#include<cmath> 
using namespace std;

class SP1 {
    protected: 
        float thuc;
        float ao;
    public:
        SP1(); 
        void nhap();
        void in();
        float tinhModule();
};

class SP2 : public SP1 {
    public:
        SP2& operator=(const SP2& sp);
        bool operator>(SP2 sp);
};

SP1::SP1() {
    thuc = 0;
    ao = 0;
}

void SP1::nhap() {
    cout << "Nhap phan thuc: "; cin >> thuc;
    cout << "Nhap phan ao: "; cin >> ao;
}

void SP1::in() {
    if (ao >= 0) {
        cout << thuc << " + " << ao << "i";
    } else {
        cout << thuc << " - " << abs(ao) << "i";
    }
}

float SP1::tinhModule() {
    return sqrt(thuc * thuc + ao * ao);
}

SP2& SP2::operator=(const SP2& sp) {
    this->thuc = sp.thuc;
    this->ao = sp.ao;
    return *this; 
}

bool SP2::operator>(SP2 sp) {
    return this->tinhModule() > sp.tinhModule();
}

// ================= CHUONG TRINH CHINH =================
int main()
{
    // Chay thu phuong thuc nhap xuat cho 1 doi tuong
    cout << "--- TEST NHAP XUAT 1 SO PHUC ---" << endl;
    SP2 testSP;
    testSP.nhap();
    cout << "So phuc vua nhap: ";
    testSP.in();
    cout << "\nModule: " << testSP.tinhModule() << endl;

    return 0;
}

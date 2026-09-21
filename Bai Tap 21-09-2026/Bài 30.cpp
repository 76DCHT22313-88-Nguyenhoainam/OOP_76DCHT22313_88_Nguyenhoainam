#include<iostream>
#include<cmath>
using namespace std;

// ================= CAU 1: KHAI BAO LOP SP1 =================
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

// ================= CAU 2: KHAI BAO LOP SP2 =================
class SP2 : public SP1 {
    public:
        SP2& operator=(const SP2& sp);
        bool operator>(SP2 sp);
};

// ================= XAY DUNG PHUONG THUC =================
// Dinh nghia ham tao: Gan gia tri mac dinh bang 0
SP1::SP1() {
    thuc = 0;
    ao = 0;
}

void SP1::nhap() {
    cout << "Nhap phan thuc: "; cin >> thuc;
    cout << "Nhap phan ao: "; cin >> ao;
}

void SP1::in() {
    // In dep mat theo dang (thuc + aoi) hoac (thuc - aoi)
    if (ao >= 0) {
        cout << thuc << " + " << ao << "i";
    } else {
        cout << thuc << " - " << abs(ao) << "i";
    }
}

float SP1::tinhModule() {
    // Cong thuc module so phuc: Can bac 2 cua (thuc^2 + ao^2)
    return sqrt(thuc * thuc + ao * ao);
}

// Nap chong toan tu gan (=)
SP2& SP2::operator=(const SP2& sp) {
    this->thuc = sp.thuc;
    this->ao = sp.ao;
    return *this;
}

// Nap chong toan tu lon hon (>): So sanh theo module
bool SP2::operator>(SP2 sp) {
    return this->tinhModule() > sp.tinhModule();
}

// ================= CHUONG TRINH CHINH =================
int main()
{
    cout << "--- TEST 1 SO PHUC ---" << endl;
    SP2 testSP;
    testSP.nhap();
    cout << "So phuc vua nhap: "; 
    testSP.in();
    cout << "\nModule = " << testSP.tinhModule() << endl;
    
    return 0;
}

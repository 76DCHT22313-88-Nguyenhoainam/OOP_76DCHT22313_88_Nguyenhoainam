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

// ================= XAY DUNG CHI TIET PHUONG THUC =================
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

// ================= CAU 3: MAIN (NHAP DANH SACH & SAP XEP) =================
int main()
{
    int n;
    SP2 ds[10]; 
    
    do {
        cout << "Nhap so luong so phuc (tu 1 den 10): ";
        cin >> n;
        if (n <= 0 || n > 10) cout << "So luong khong hop le! Vui long nhap lai.\n";
    } while (n <= 0 || n > 10);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap so phuc thu " << i+1 << " ---" << endl;
        ds[i].nhap();
    }

    // Sap xep giam dan bang thuat toan noi bot 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j] > ds[i]) { 
                SP2 temp = ds[i]; 
                ds[i] = ds[j];    
                ds[j] = temp;     
            }
        }
    }

    // In danh sach
    cout << "\n================ DS SO PHUC GIAM DAN THEO MODULE ================" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].in();
        cout << "  (Module = " << ds[i].tinhModule() << ")" << endl;
    }

    return 0;
}

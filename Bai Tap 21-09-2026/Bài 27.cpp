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
    do {
        cout << "Nhap mau so (khac 0): "; 
        cin >> mauSo;
        if (mauSo == 0) cout << "Loi! Mau so phai khac 0. Vui long nhap lai.\n";
    } while (mauSo == 0);
}

void PS1::toiGian() {
    int ucln = timUCLN(tuSo, mauSo);
    tuSo = tuSo / ucln;
    mauSo = mauSo / ucln;
    if (mauSo < 0) {
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}

void PS1::in() {
    toiGian(); 
    if (mauSo == 1) cout << tuSo;
    else cout << tuSo << "/" << mauSo;
}

PS2& PS2::operator=(const PS2& p) {
    this->tuSo = p.tuSo;
    this->mauSo = p.mauSo;
    return *this;
}

bool PS2::operator>(PS2 p) {
    float giaTri1 = (float)this->tuSo / this->mauSo;
    float giaTri2 = (float)p.tuSo / p.mauSo;
    return giaTri1 > giaTri2;
}

// ================= CAU 3: MAIN (NHAP DS & SAP XEP) =================
int main()
{
    int n;
    PS2 ds[10]; // Toi da 10 phan tu
    
    // Kiem soat viec nhap n (1 <= n <= 10)
    do {
        cout << "Nhap so luong phan so (1 toi da 10): ";
        cin >> n;
        if (n <= 0 || n > 10) {
            cout << "So luong khong hop le! Vui long nhap tu 1 den 10.\n";
        }
    } while (n <= 0 || n > 10);

    // Nhap mang phan so
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap phan so thu " << i+1 << " ---" << endl;
        ds[i].nhap();
    }

    // Sap xep giam dan bang thuat toan noi bot 
    // Su dung toan tu > va = da duoc nap chong o Cau 2
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j] > ds[i]) { 
                PS2 temp = ds[i]; // Goi toan tu =
                ds[i] = ds[j];    // Goi toan tu =
                ds[j] = temp;     // Goi toan tu =
            }
        }
    }

    // In danh sach sau khi sap xep
    cout << "\n================ DANH SACH PHAN SO GIAM DAN ================" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].in();
        if (i < n - 1) cout << "  ;  "; // In dau cham phay giua cac phan so cho dep
    }
    cout << endl;

    return 0;
}

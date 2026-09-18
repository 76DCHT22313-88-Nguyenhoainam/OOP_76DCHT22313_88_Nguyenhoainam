#include<iostream>
#include<string>
using namespace std;

//CAU 1: KHAI BAO LOP
class nguoi {
    protected: 
        string hoten;
        int nsinh;
    public:
        void nhap();
        void xuat();
};

class SinhVien: public nguoi {
    private: 
        string msv;
        float dtb;
    public:
        void nhap();
        void xuat();
        string getMsv();
        string getHoTen();
};

//CAU 2: XAY DUNG PHUONG THUC
void nguoi::nhap() {
    cout << "Nhap hoten: "; getline(cin, hoten);
    cout << "Nhap nsinh: "; cin >> nsinh;
    cin.ignore(); 
}

void nguoi::xuat() {
    cout << "Ho ten: " << hoten << " | Nam sinh: " << nsinh;
}

void SinhVien::nhap() {
    nguoi::nhap(); 
    cout << "Nhap msv: "; getline(cin, msv);
    cout << "Nhap dtb: "; cin >> dtb;
}

void SinhVien::xuat() {
    nguoi::xuat(); 
    cout << " | Ma SV: " << msv << " | Diem TB: " << dtb << endl;
}

string SinhVien::getMsv() {
    return msv;
}

string SinhVien::getHoTen() {
    return hoten;
}

//CAU 3: MAIN (NHAP XUAT & TIM KIEM)
int main()
{
    int n;
    SinhVien ds[100]; 
    
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore(); 

    for(int i = 0; i < n; i++){
        cout << "\n--- Nhap thong tin sinh vien thu " << i+1 << " ---" << endl;
        ds[i].nhap();
        cin.ignore(); 
    }

    string tuKhoa;
    cout << "\nTIM KIEM" << endl;
    cout << "Nhap ten hoac ma sinh vien can tim: ";
    getline(cin, tuKhoa); 

    bool timThay = false; 
    
    cout << "\nKET QUA TIM KIEM:" << endl;
    for(int i = 0; i < n; i++){
        if(ds[i].getMsv() == tuKhoa || ds[i].getHoTen() == tuKhoa){
            ds[i].xuat();
            timThay = true; 
        }
    }

    if(timThay == false){
        cout << "Khong tim thay sinh vien nao hop le voi thong tin da nhap!" << endl;
    }

    return 0;
}

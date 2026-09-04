#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    void nhap() {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        
        cout << "Nhap diem 4 mon hoc:" << endl;
        for(int i = 0; i < 4; i++) {
            cout << " - Diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    float tinhDTB() {
        float tong = 0;
        for(int i = 0; i < 4; i++) {
            tong = tong + diem[i];
        }
        return tong / 4.0;
    }

    void xuat() {
        cout << "- " << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << tinhDTB() << endl;
    }

    // Cau 3: Kiem tra tieu chuan thi tot nghiep
    void kiemTraTotNghiep() {
        float dtb = tinhDTB();
        bool khongMonNaoDuoi5 = true; 
        
        // Quet 4 mon, neu co mon < 5 thi doi co hieu thanh false
        for(int i = 0; i < 4; i++) {
            if(diem[i] < 5.0) {
                khongMonNaoDuoi5 = false;
                break;
            }
        }
        
        // Tieu chuan: DTB < 7 va khong co mon nao duoi 5
        if(dtb < 7.0 && khongMonNaoDuoi5 == true) {
            xuat(); 
        }
    }
};

int main() {
    int n;
    SinhVien ds[100]; 

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN SINH VIEN THU " << i + 1 << " ===" << endl;
        ds[i].nhap();
    }

    cout << "\n========== DANH SACH SINH VIEN PHAI THI TOT NGHIEP ==========" << endl;
    for(int i = 0; i < n; i++) {
        ds[i].kiemTraTotNghiep();
    }

    return 0;
}#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    void nhap() {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        
        cout << "Nhap diem 4 mon hoc:" << endl;
        for(int i = 0; i < 4; i++) {
            cout << " - Diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    float tinhDTB() {
        float tong = 0;
        for(int i = 0; i < 4; i++) {
            tong = tong + diem[i];
        }
        return tong / 4.0;
    }

    void xuat() {
        cout << "- " << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << tinhDTB() << endl;
    }

    // Cau 3: Kiem tra tieu chuan thi tot nghiep
    void kiemTraTotNghiep() {
        float dtb = tinhDTB();
        bool khongMonNaoDuoi5 = true; 
        
        // Quet 4 mon, neu co mon < 5 thi doi co hieu thanh false
        for(int i = 0; i < 4; i++) {
            if(diem[i] < 5.0) {
                khongMonNaoDuoi5 = false;
                break;
            }
        }
        
        // Tieu chuan: DTB < 7 va khong co mon nao duoi 5
        if(dtb < 7.0 && khongMonNaoDuoi5 == true) {
            xuat(); 
        }
    }
};

int main() {
    int n;
    SinhVien ds[100]; 

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN SINH VIEN THU " << i + 1 << " ===" << endl;
        ds[i].nhap();
    }

    cout << "\n========== DANH SACH SINH VIEN PHAI THI TOT NGHIEP ==========" << endl;
    for(int i = 0; i < n; i++) {
        ds[i].kiemTraTotNghiep();
    }

    return 0;
}#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    void nhap() {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        
        cout << "Nhap diem 4 mon hoc:" << endl;
        for(int i = 0; i < 4; i++) {
            cout << " - Diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    float tinhDTB() {
        float tong = 0;
        for(int i = 0; i < 4; i++) {
            tong = tong + diem[i];
        }
        return tong / 4.0;
    }

    void xuat() {
        cout << "- " << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << tinhDTB() << endl;
    }

    // Cau 3: Kiem tra tieu chuan thi tot nghiep
    void kiemTraTotNghiep() {
        float dtb = tinhDTB();
        bool khongMonNaoDuoi5 = true; 
        
        // Quet 4 mon, neu co mon < 5 thi doi co hieu thanh false
        for(int i = 0; i < 4; i++) {
            if(diem[i] < 5.0) {
                khongMonNaoDuoi5 = false;
                break;
            }
        }
        
        // Tieu chuan: DTB < 7 va khong co mon nao duoi 5
        if(dtb < 7.0 && khongMonNaoDuoi5 == true) {
            xuat(); 
        }
    }
};

int main() {
    int n;
    SinhVien ds[100]; 

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN SINH VIEN THU " << i + 1 << " ===" << endl;
        ds[i].nhap();
    }

    cout << "\n========== DANH SACH SINH VIEN PHAI THI TOT NGHIEP ==========" << endl;
    for(int i = 0; i < n; i++) {
        ds[i].kiemTraTotNghiep();
    }

    return 0;
}#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    void nhap() {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        
        cout << "Nhap diem 4 mon hoc:" << endl;
        for(int i = 0; i < 4; i++) {
            cout << " - Diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    float tinhDTB() {
        float tong = 0;
        for(int i = 0; i < 4; i++) {
            tong = tong + diem[i];
        }
        return tong / 4.0;
    }

    void xuat() {
        cout << "- " << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << tinhDTB() << endl;
    }

    // Cau 3: Kiem tra tieu chuan thi tot nghiep
    void kiemTraTotNghiep() {
        float dtb = tinhDTB();
        bool khongMonNaoDuoi5 = true; 
        
        // Quet 4 mon, neu co mon < 5 thi doi co hieu thanh false
        for(int i = 0; i < 4; i++) {
            if(diem[i] < 5.0) {
                khongMonNaoDuoi5 = false;
                break;
            }
        }
        
        // Tieu chuan: DTB < 7 va khong co mon nao duoi 5
        if(dtb < 7.0 && khongMonNaoDuoi5 == true) {
            xuat(); 
        }
    }
};

int main() {
    int n;
    SinhVien ds[100]; 

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN SINH VIEN THU " << i + 1 << " ===" << endl;
        ds[i].nhap();
    }

    cout << "\n========== DANH SACH SINH VIEN PHAI THI TOT NGHIEP ==========" << endl;
    for(int i = 0; i < n; i++) {
        ds[i].kiemTraTotNghiep();
    }

    return 0;
}#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    void nhap() {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        
        cout << "Nhap diem 4 mon hoc:" << endl;
        for(int i = 0; i < 4; i++) {
            cout << " - Diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    float tinhDTB() {
        float tong = 0;
        for(int i = 0; i < 4; i++) {
            tong = tong + diem[i];
        }
        return tong / 4.0;
    }

    void xuat() {
        cout << "- " << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << tinhDTB() << endl;
    }

    // Cau 3: Kiem tra tieu chuan thi tot nghiep
    void kiemTraTotNghiep() {
        float dtb = tinhDTB();
        bool khongMonNaoDuoi5 = true; 
        
        // Quet 4 mon, neu co mon < 5 thi doi co hieu thanh false
        for(int i = 0; i < 4; i++) {
            if(diem[i] < 5.0) {
                khongMonNaoDuoi5 = false;
                break;
            }
        }
        
        // Tieu chuan: DTB < 7 va khong co mon nao duoi 5
        if(dtb < 7.0 && khongMonNaoDuoi5 == true) {
            xuat(); 
        }
    }
};

int main() {
    int n;
    SinhVien ds[100]; 

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN SINH VIEN THU " << i + 1 << " ===" << endl;
        ds[i].nhap();
    }

    cout << "\n========== DANH SACH SINH VIEN PHAI THI TOT NGHIEP ==========" << endl;
    for(int i = 0; i < n; i++) {
        ds[i].kiemTraTotNghiep();
    }

    return 0;
}

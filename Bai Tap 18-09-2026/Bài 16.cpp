#include<iostream>
#include<string>
using namespace std;

//CAU 1: KHAI BAO LOP
// Khai bao lop mon hoc (Lop cha)
class MonHoc {
    protected: 
        string tenMon;
        float diemCC, diemKT, diemThi;
    public:
        void nhap();
        void xuat();
};

// Khai bao lop sinh vien ke thua tu mon hoc
class SinhVien : public MonHoc {
    private: 
        string hoTen, lop, msv;
    public:
        void nhap();
        void xuat();
        float tinhDiemHP(); // Tinh diem hoc phan
        
        // Ham lay diem de xet dieu kien cam thi o Cau 3
        float getDiemCC();
        float getDiemKT();
};

int main()
{
    return 0;
}

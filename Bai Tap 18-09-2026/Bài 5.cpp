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

int main()
{
    return 0;
}

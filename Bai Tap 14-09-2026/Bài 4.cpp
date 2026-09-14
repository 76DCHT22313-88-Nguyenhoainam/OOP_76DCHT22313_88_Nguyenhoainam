#include<iostream>
#include<string>
using namespace std;

class nguoi{
    protected:
        string hoten;
        int nsinh;
    public:
        //yeu cau them: tao ham tao
        //ham tao khong doi
        nguoi()
        { hoten="",nsinh=0;}
        //ham tao co doi
        nguoi(string hoten, int nsinh)
        {
            this->hoten =hoten;
            this->nsinh =nsinh;
        }
        void nhap(){
            cout<<"Nhap hoten: ";getline(cin,hoten);
            cout<<"Nhap nsinh: ";cin>>nsinh;
            cin.ignore();
        }
        // BO SUNG: Ham xuat thong tin nguoi
        void xuat(){
            cout << "Ho ten: " << hoten << " | Nam sinh: " << nsinh;
        }
};

class SinhVien: public nguoi{
    private:
        string msv;
        float dtb;
    public:
        //Lop con sinh vien khong duoc ke thua ham tao ma phai goi lai
        //goi lai ham tao ko doi cua nguoi
        SinhVien ():nguoi(){
        }
        //goi lai ham tao co doi cua nguoi
        SinhVien(string hoten, int nsinh, string msv, float dtb): nguoi(hoten, nsinh){
            this->msv=msv;
            this->dtb=dtb;
        }
        void nhap(){
            nguoi::nhap() ;//goi nhap cua lop nguoi, sinhvien duoc ke thua nguoi
            cout<<"Nhap msv: ";getline(cin,msv);
            cout<<"Nhap dtb: ";cin>>dtb;
        }
        // BO SUNG: Ham xuat cua sinh vien
        void xuat(){
            nguoi::xuat();
            cout << " | Ma SV: " << msv << " | Diem TB: " << dtb << endl;
        }
        // BO SUNG: Ham lay diem tb de phuc vu sap xep y3
        float getDtb(){
            return dtb;
        }
};

int main()
{
    return 0;
}

#include<iostream>
#include<string>
using namespace std;

class nguoi{
    protected:
        string hoten;
        int nsinh;
    public:
        nguoi()
        { hoten="",nsinh=0;}
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
        void xuat(){
            cout << "Ho ten: " << hoten << " | Nam sinh: " << nsinh;
        }
};

class SinhVien: public nguoi{
    private:
        string msv;
        float dtb;
    public:
        SinhVien ():nguoi(){
        }
        SinhVien(string hoten, int nsinh, string msv, float dtb): nguoi(hoten, nsinh){
            this->msv=msv;
            this->dtb=dtb;
        }
        void nhap(){
            nguoi::nhap() ;
            cout<<"Nhap msv: ";getline(cin,msv);
            cout<<"Nhap dtb: ";cin>>dtb;
        }
        void xuat(){
            nguoi::xuat();
            cout << " | Ma SV: " << msv << " | Diem TB: " << dtb << endl;
        }
        float getDtb(){
            return dtb;
        }
};

int main()
{
    SinhVien dinh("Dinh",2000,"mn01",8);
    cout << "--- THONG TIN BAN DINH ---" << endl;
    dinh.xuat();
    
    return 0;
}

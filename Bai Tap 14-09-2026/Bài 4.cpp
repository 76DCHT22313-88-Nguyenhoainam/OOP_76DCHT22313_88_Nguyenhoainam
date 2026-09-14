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
            nguoi::nhap() ;//goi nhap cua lop nguoi, sinhvien duoc ke thua nguoi
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
    cout << "--- THONG TIN SINH VIEN TEST ---" << endl;
    dinh.xuat();
    
    int n;
    SinhVien ds[100];
    
    cout << "\n--- YEU CAU 3: NHAP DANH SACH SINH VIEN ---" << endl;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore(); // Xoa dau Enter truoc khi vao vong lap

    for(int i = 0; i < n; i++){
        cout << "\nNhap sinh vien thu " << i+1 << ":" << endl;
        ds[i].nhap();
        cin.ignore(); // Xoa dau Enter do ham nhap SinhVien de lai sau khi nhap dtb
    }

    // Sap xep giam dan
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ds[i].getDtb() < ds[j].getDtb()){
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << "\n=== DANH SACH SINH VIEN GIAM DAN THEO DTB ===" << endl;
    for(int i = 0; i < n; i++){
        ds[i].xuat();
    }

    return 0;
}

#include<iostream>
#include<string>
using namespace std;

// Cau 1: Khai bao lop nguoi
class nguoi{
    protected: 
        string hoten;
        int nsinh;
        
    public:
        //yeu cau them: tao ham tao
        //ham tao khong doi
        nguoi()
        { 
            hoten="";
            nsinh=0;
        }
        
        //ham tao co doi
        nguoi(string hoten, int nsinh)
        {
            this->hoten = hoten;
            this->nsinh = nsinh;
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

// Cau 1: Khai bao lop sinh vien ke thua
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
            this->msv = msv;
            this->dtb = dtb;
        }
        
        void nhap(){
            nguoi::nhap(); //goi nhap cua lop nguoi, sinhvien duoc ke thua nguoi
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
    // Cau 2
    SinhVien dinh("Dinh",2000,"mn01",8);
    //xay dung method xuat va xuat cho ca thong tin tren
    cout << "--- THONG TIN SINH VIEN TEST ---" << endl;
    dinh.xuat(); 
    
    // Cau 3
    int n;
    SinhVien ds[100]; 
    
    cout << "\nNhap so luong sinh vien: ";
    cin >> n;
    cin.ignore(); 

    for(int i = 0; i < n; i++){
        cout << "\nNhap thong tin sinh vien thu " << i+1 << ":" << endl;
        ds[i].nhap();
        cin.ignore(); 
    }

    // Sap xep giam dan theo dtb
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ds[i].getDtb() < ds[j].getDtb()){ 
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // In danh sach
    cout << "\n=== DANH SACH SINH VIEN GIAM DAN THEO DTB ===" << endl;
    for(int i = 0; i < n; i++){
        ds[i].xuat();
    }

    return 0;
}

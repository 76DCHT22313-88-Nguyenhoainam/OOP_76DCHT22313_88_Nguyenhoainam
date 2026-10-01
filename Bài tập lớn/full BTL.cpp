#include <iostream>  // Thu vien nhap/xuat chuan (cin, cout)
#include <string>    // Thu vien xu ly chuoi ky tu (string, getline)
#include <iomanip>   // Thu vien dinh dang in an (setprecision)

using namespace std; // Dung khong gian ten chuan de khong phai viet std::cout

// ==========================================
// 1. LOP NGUOI (Lop cha cao nhat)
// ==========================================
class Nguoi
{
protected: // Dung protected de lop con ke thua co the dung truc tiep
    string HoTen; // Bien luu ho ten
    int NamSinh;  // Bien luu nam sinh

public:
    // Ham tao co tham so mac dinh (tu gan gia tri rong/0 neu khong truyen)
    Nguoi(string HoTen = "", int NamSinh = 0);
    
    // Ham ao (virtual) cho phep lop con ghi de lai phuong thuc nay
    virtual void xuat();
    
    // Ham huy ao giup don dep sach bo nho cua lop con khi dung da hinh
    virtual ~Nguoi();
};

// Cai dat ham tao: Gan gia tri tham so vao thuoc tinh cua lop
Nguoi::Nguoi(string HoTen, int NamSinh)
{
    this->HoTen = HoTen;     // Con tro this tro toi thuoc tinh cua doi tuong
    this->NamSinh = NamSinh;
}

// Cai dat ham xuat: In thong tin co ban
void Nguoi::xuat()
{
    cout << "Ho ten: " << HoTen << endl;
    cout << "Nam sinh: " << NamSinh << endl;
}

Nguoi::~Nguoi() {} // Ham huy trong vi chua cap phat dong o lop nay


// ==========================================
// 2. LOP NHAN VIEN (Lop truu tuong)
// ==========================================
// Ke thua ao (virtual public) de chong tao 2 ban sao cua Nguoi o lop da ke thua sau nay
class NhanVien : virtual public Nguoi
{
protected:
    string MaNV;       // Ma nhan vien
    double LuongCoBan; // Luong co ban

public:
    NhanVien(string HoTen = "", int NamSinh = 0, string MaNV = "", double LuongCoBan = 0);
    
    // Ham thuan ao (= 0) bien day thanh Lop truu tuong, bat buoc lop con phai viet lai
    virtual double TinhLuong() = 0; 
    
    virtual void xuat(); // Ghi de ham xuat
    virtual ~NhanVien();
};

// Cai dat ham tao: Goi moi ham tao cua cha Nguoi() de khoi tao ho ten, nam sinh
NhanVien::NhanVien(string HoTen, int NamSinh, string MaNV, double LuongCoBan)
    : Nguoi(HoTen, NamSinh)
{
    this->MaNV = MaNV;
    this->LuongCoBan = LuongCoBan;
}

void NhanVien::xuat()
{
    Nguoi::xuat(); // Tai su dung code: goi ham in ho ten, nam sinh cua cha
    cout << "Ma nhan vien: " << MaNV << endl;
    cout << fixed << setprecision(0); // Tat che do in so thuc dang e (mu khoa hoc)
    cout << "Luong co ban: " << LuongCoBan << endl;
}

NhanVien::~NhanVien() {}


// ==========================================
// 3. LOP QUAN LY
// ==========================================
// Ke thua ao tu Nguoi tuong tu nhu NhanVien
class QuanLy : virtual public Nguoi
{
protected:
    double PhuCapQuanLy; // Thuoc tinh rieng cua quan ly

public:
    QuanLy(string HoTen = "", int NamSinh = 0, double PhuCapQuanLy = 0);
    virtual void xuat();
    virtual ~QuanLy();
};

// Khoi tao giong nhan vien
QuanLy::QuanLy(string HoTen, int NamSinh, double PhuCapQuanLy)
    : Nguoi(HoTen, NamSinh)
{
    this->PhuCapQuanLy = PhuCapQuanLy;
}

void QuanLy::xuat()
{
    Nguoi::xuat(); // Goi ham in thong tin nguoi
    cout << "Phu cap quan ly: " << PhuCapQuanLy << endl;
}

QuanLy::~QuanLy() {}


// ==========================================
// 4. LOP NHAN VIEN VAN PHONG
// ==========================================
// Ke thua binh thuong tu NhanVien
class NhanVienVanPhong : public NhanVien
{
private:
    int SoNgayLamViec; // So ngay lam viec

public:
    NhanVienVanPhong(string HoTen = "", int NamSinh = 0, string MaNV = "", double LuongCoBan = 0, int SoNgayLamViec = 0);
    
    double TinhLuong(); // Cai dat thuc te ham tinh luong (xoa so tinh truu tuong)
    void xuat();        // Cai dat thuc te ham xuat
};

// Goi ham tao cua cha (NhanVien) de xu ly cac du lieu dung chung
NhanVienVanPhong::NhanVienVanPhong(string HoTen, int NamSinh, string MaNV, double LuongCoBan, int SoNgayLamViec)
    : Nguoi(HoTen, NamSinh), NhanVien(HoTen, NamSinh, MaNV, LuongCoBan)
{
    this->SoNgayLamViec = SoNgayLamViec;
}

// Tinh luong theo cong thuc rieng cua nhan vien van phong
double NhanVienVanPhong::TinhLuong()
{
    return LuongCoBan + SoNgayLamViec * 200000;
}

void NhanVienVanPhong::xuat()
{
    NhanVien::xuat(); // Goi in thong tin nhan vien chung
    cout << "So ngay lam viec: " << SoNgayLamViec << endl;
    cout << fixed << setprecision(0);
    cout << "Luong: " << TinhLuong() << endl; // Goi ham tinh luong o tren
}


// ==========================================
// 5. LOP NHAN VIEN KINH DOANH
// ==========================================
class NhanVienKinhDoanh : public NhanVien
{
private:
    double DoanhSo; // Thuoc tinh dac thu kinh doanh

public:
    NhanVienKinhDoanh(string HoTen = "", int NamSinh = 0, string MaNV = "", double LuongCoBan = 0, double DoanhSo = 0);
    double TinhLuong();
    void xuat();
};

NhanVienKinhDoanh::NhanVienKinhDoanh(string HoTen, int NamSinh, string MaNV, double LuongCoBan, double DoanhSo)
    : Nguoi(HoTen, NamSinh), NhanVien(HoTen, NamSinh, MaNV, LuongCoBan)
{
    this->DoanhSo = DoanhSo;
}

// Luong bang luong co ban cong them 10% doanh so
double NhanVienKinhDoanh::TinhLuong()
{
    return LuongCoBan + DoanhSo * 0.1;
}

void NhanVienKinhDoanh::xuat()
{
    NhanVien::xuat();
    cout << "Doanh so: " << DoanhSo << endl;
    cout << fixed << setprecision(0);
    cout << "Luong: " << TinhLuong() << endl;
}


// ==========================================
// 6. LOP TRUONG PHONG (Da ke thua kim cuong)
// ==========================================
// Ke thua ca NhanVien va QuanLy. Nho 2 chu virtual o tren, se chi ton tai 1 bo (HoTen, NamSinh)
class TruongPhong : virtual public NhanVien, virtual public QuanLy
{
private:
    int SoNamKinhNghiem;

public:
    TruongPhong(string HoTen = "", int NamSinh = 0, string MaNV = "", double LuongCoBan = 0, double PhuCapQuanLy = 0, int SoNamKinhNghiem = 0);
    double TinhLuong();
    void xuat();
};

// TruongPhong phai TU GOI ham tao cua lop goc (Nguoi) do tinh chat ke thua ao
TruongPhong::TruongPhong(string HoTen, int NamSinh, string MaNV, double LuongCoBan, double PhuCapQuanLy, int SoNamKinhNghiem)
    : Nguoi(HoTen, NamSinh), NhanVien(HoTen, NamSinh, MaNV, LuongCoBan), QuanLy(HoTen, NamSinh, PhuCapQuanLy)
{
    this->SoNamKinhNghiem = SoNamKinhNghiem;
}

// Cong thuc luong gom ca tu NhanVien (luong CB) va QuanLy (phu cap)
double TruongPhong::TinhLuong()
{
    return LuongCoBan + PhuCapQuanLy + SoNamKinhNghiem * 500000;
}

void TruongPhong::xuat()
{
    // Co tinh tu in tung dong (khong goi ham cha) de tranh trung lap thong tin in ra man hinh
    cout << "Ho ten: " << HoTen << endl;
    cout << "Nam sinh: " << NamSinh << endl;
    cout << "Ma nhan vien: " << MaNV << endl;
    cout << "Luong co ban: " << LuongCoBan << endl;
    cout << "Phu cap quan ly: " << PhuCapQuanLy << endl;
    cout << "So nam kinh nghiem: " << SoNamKinhNghiem << endl;
    cout << fixed << setprecision(0);
    cout << "Luong: " << TinhLuong() << endl;
}


// ==========================================
// 7. HAM MAIN
// ==========================================
int main()
{
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n; // Nhap n tu ban phim

    // Cap phat mang chua 'n' con tro lop cha (NhanVien*). Day la cot loi cua Da hinh.
    NhanVien** ds = new NhanVien*[n]; 

    for (int i = 0; i < n; i++)
    {
        int loai;
        cout << "\nNhan vien thu " << i + 1 << endl;
        cout << "1. Nhan vien van phong\n2. Nhan vien kinh doanh\n3. Truong phong\nChon: ";
        cin >> loai;

        string HoTen, MaNV;
        int NamSinh;
        double LuongCoBan;

        // Xoa phim Enter thua bi ket lai trong bo dem sau lenh cin >> loai
        cin.ignore(); 
        
        cout << "Ho ten: ";
        getline(cin, HoTen); // Dung getline de nhap chuoi dai co chua dau cach
        cout << "Nam sinh: ";
        cin >> NamSinh;
        cout << "Ma nhan vien: ";
        cin >> MaNV;
        cout << "Luong co ban: ";
        cin >> LuongCoBan;

        // Tuy theo loai, tao doi tuong LOP CON tuong ung va ep gan vao con tro LOP CHA
        if (loai == 1)
        {
            int SoNgayLamViec;
            cout << "So ngay lam viec: ";
            cin >> SoNgayLamViec;
            ds[i] = new NhanVienVanPhong(HoTen, NamSinh, MaNV, LuongCoBan, SoNgayLamViec);
        }
        else if (loai == 2)
        {
            double DoanhSo;
            cout << "Doanh so: ";
            cin >> DoanhSo;
            ds[i] = new NhanVienKinhDoanh(HoTen, NamSinh, MaNV, LuongCoBan, DoanhSo);
        }
        else
        {
            double PhuCapQuanLy;
            int SoNamKinhNghiem;
            cout << "Phu cap quan ly: ";
            cin >> PhuCapQuanLy;
            cout << "So nam kinh nghiem: ";
            cin >> SoNamKinhNghiem;
            ds[i] = new TruongPhong(HoTen, NamSinh, MaNV, LuongCoBan, PhuCapQuanLy, SoNamKinhNghiem);
        }
    }

    cout << "\n========== DANH SACH ==========\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n----- Nhan vien " << i + 1 << " -----\n";
        // C++ tu dong biet ds[i] la loai nao de goi dung ham xuat() cua loai do (Da hinh)
        ds[i]->xuat(); 
    }

    // Quy trinh don dep bo nho da cap phat dong bang lenh new o tren
    for (int i = 0; i < n; i++)
    {
        // Goi ham huy cua tung doi tuong con truoc
        delete ds[i]; 
    }
    // Cuoi cung giai phong chinh mang con tro
    delete[] ds; 

    return 0; // Ket thuc chuong trinh
}

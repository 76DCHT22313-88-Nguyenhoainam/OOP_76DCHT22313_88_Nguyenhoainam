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
        // Khai bao nap chong toan tu = (gan)
        PS2& operator=(const PS2& p);
        
        // Khai bao nap chong toan tu > (lon hon) de so sanh
        bool operator>(PS2 p);
};

int main()
{
    return 0;
}

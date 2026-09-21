#include<iostream>
#include<cmath> // Thu vien de dung ham can bac 2 (sqrt) tinh module
using namespace std;

// ================= CAU 1: KHAI BAO LOP SP1 =================
class SP1 {
    protected: 
        float thuc;
        float ao;
    public:
        SP1(); // Ham tao
        void nhap();
        void in();
        float tinhModule();
};

// ================= CAU 2: KHAI BAO LOP SP2 =================
class SP2 : public SP1 {
    public:
        // Khai bao nap chong toan tu
        SP2& operator=(const SP2& sp);
        bool operator>(SP2 sp);
};

int main()
{
    return 0;
}

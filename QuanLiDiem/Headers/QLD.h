#pragma once
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class QLD
{
private:
    string mssv;
    string hoTen;
    int buoiVang;
    float DiemTH;
    float DiemGK;

public:
    string getMSSV();
    string getHoTen();
    int getBuoiVang();
    float getDiemTH();
    float getDiemGK();
    void nhap();
	void docFile(ifstream& file);
	void ghiFile(ofstream& file);
    void xuat(int n,float diemQT);
    void DiemQT(int n);
    void DSSV_duDieuKienDuThi();
    void DSSV_hoNguyen();
    void DSSV_cungTen(vector<string> ds);
};
#include "QLD.cpp"
// Xây dựng phần mềm quản lý điểm quá trình và xét điều kiện dự thi cho sinh viên. Yêu cầu như sau:

// 1.     Thông tin quản lý cho từng sinh viên:

// a.     Mã số SV: string

// b.     Họ tên: string

// c.     Số buổi vắng: int

// d.     Điểm thực hành: float (DiemTH)

// e.     Điểm giữa kỳ: float (DiemGK)


// 2.     Cho phép nhập/xuất danh sách từ bàn phím/màn hình và từ file

// 3.     Tính điểm quá trình (DiemQT) theo công thức

// DiemQT = (10 – số buổi vắng*2)*0.2 +DiemTH*0.3 + DiemGK*0.5

// nếu số buổi vắng <=5

// ngược lại, DiemQT = 0

// 4.     In danh sách sinh viên đủ điều kiện dự thi (có DiemQT>=3)

// 5.     In danh sách các sinh viên có họ là “Nguyen”

// 6.     (*) In danh sách các sinh viên có cùng tên với một sinh viên khác
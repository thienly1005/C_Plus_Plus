#include "TTN.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string CauhoiTN::getNoiDung()
{
    return _noiDung;
}

string CauhoiTN::getDapAnA()
{
    return _dapAnA;
}

string CauhoiTN::getDapAnB()
{
    return _dapAnB;
}
char CauhoiTN::getDapAnDung()
{
    return _dapAnDung;
}

// Nhap noi dung cau hoi va dap an
void CauhoiTN::nhap()
{
    cout << "\nNhap noi dung cau hoi: \n> ";
    getline(cin, _noiDung);
    cout << "Nhap dap an A: \n> ";
    getline(cin, _dapAnA);
    cout << "Nhap dap an B: \n> ";
    getline(cin, _dapAnB);
    cout << "Nhap dap an dung (A/B): \n> ";
    cin >> _dapAnDung;
    cin.ignore();
}

// Doc noi dung cau hoi va dap an tu file
void CauhoiTN::docFile(ifstream &file)
{
    getline(file, _noiDung);
    getline(file, _dapAnA);
    getline(file, _dapAnB);
    file >> _dapAnDung;
    file.ignore(); // xoa dau Enter con thua và chuyen qua cau hoi ke tiep tranh gap loi
}

// Ghi cau hoi va dap an vao file
void CauhoiTN::ghiFile(ofstream &file)
{
    CauhoiTN cauHoi;
    file << _noiDung << endl;
    file << _dapAnA << endl;
    file << _dapAnB << endl;
    file << _dapAnDung << endl;
    // if(cauHoi.giongNhau(_noiDung, _dapAnA, _dapAnB, _dapAnDung)) cout << "Cau hoi va dap an da co trong de thi!\n";
}

// Hien thi cau hoi cho nguoi kiem tra
bool CauhoiTN::kiemTra()
{
    cout << "Cau hoi: " << _noiDung << endl;
    cout << "A. " << _dapAnA << endl;
    cout << "B. " << _dapAnB << endl;
    char dapAn;
    cout << "Nhap dap an cua ban (A/B): \n> ";
    cin >> dapAn;
    cin.ignore();

    return (toupper(dapAn) == _dapAnDung); // Ham toupper de dam bao dap an nhap vao se duoc chuyen sang chu hoa
}

// Xuat cau hoi va dap an ra man hinh
void CauhoiTN::xuat()
{
    cout << "Cau hoi: " << _noiDung << endl;
    cout << "A. " << _dapAnA << endl;
    cout << "B. " << _dapAnB << endl;
    cout << "Dap an dung: " << _dapAnDung << endl;
}

// Kiem tra xem hai cau hoi co trung nhau khong
bool giongNhau(ifstream &file, string _noiDung, string _dapAnA, string _dapAnB, char _dapAnDung)
{
    CauhoiTN cauhoi;
    while (!file.eof())
    {
        cauhoi.docFile(file);
        if (cauhoi.getNoiDung().empty())
            continue;
        if(cauhoi.getNoiDung() == _noiDung && cauhoi.getDapAnA() == _dapAnA
        && cauhoi.getDapAnB() == _dapAnB && cauhoi.getDapAnDung() == _dapAnDung) return true;
    }
    return false;
}
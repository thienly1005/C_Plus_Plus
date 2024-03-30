#include "TTN.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
    do{
        getline(cin, _noiDung);
        if(_noiDung == "") cout << "Noi dung khong the de trong!!!\n";
    }while(_noiDung == "");
    
    cout << "Nhap dap an A: \n> ";
    do{
        getline(cin, _dapAnA);
        if(_dapAnA == "") cout << "Dap an khong the de trong!!!\n";
    }while(_dapAnA == "");
    
    cout << "Nhap dap an B: \n> ";
    do{
        getline(cin, _dapAnB);
        if(_dapAnB == "") cout << "Dap an khong the de trong!!!\n";
    }while(_dapAnB == "");
    
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
bool giongNhau(ifstream &file, string _noiDung, string _dapAnA, string _dapAnB, char _dapAnDung, vector<string> kt)
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
    vector<string> kt1 = kt;
    int count = 0;
    for(int i=0; i<kt1.size(); i+=4){
        if(kt1[i] == _noiDung && kt1[i+1] == _dapAnA && kt1[i+2] == _dapAnB && kt1[i+3] == to_string(_dapAnDung)) count++;
    }
    if(count>1) return true;
    return false;
}
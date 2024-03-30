#include "QLD.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void xoa(string &s, int vt)
{
    int n = s.size();
    for (int i = vt; i < n; i++)
        s[i] = s[i + 1];
}
void xoakt(string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 32 && s[i + 1] == 32)
        {
            xoa(s, i);
            i--;
        }
    if (isspace(s[0]))
        xoa(s, 0);
    if (isspace(s[s.size()] - 1))
        xoa(s, s.size() - 1);
}

string QLD::getMSSV()
{
    return mssv;
}
string QLD::getHoTen()
{
    return hoTen;
}
int QLD::getBuoiVang()
{
    return buoiVang;
}
float QLD::getDiemTH()
{
    return DiemTH;
}
float QLD::getDiemGK()
{
    return DiemGK;
}
void QLD::nhap()
{
    char r;
    while (true)
    {
        cout << "\nNhap vao MSSV: ";
        getline(cin, mssv);
        cout << "\nNhap vao ho va ten: ";
        getline(cin, hoTen);
        cout << "\nNhap vao so buoi vang: ";
        cin >> buoiVang;
        cin.ignore();
        cout << "\nNhap vao diem thuc hanh: ";
        cin >> DiemTH;
        cin.ignore();
        cout << "\nNhap vao diem giua ky: ";
        cin >> DiemGK;
        cin.ignore();
        cout << "Nhap \"r\" de sua lai thong tin da nhap! - \"Enter\" de tiep tuc!";
        r = cin.get();
        if (r == 'r')
        {
            cin.ignore();
            continue;
        }
        break;
    }
}
void QLD::ghiFile(ofstream &file)
{
    file << mssv << endl;
    file << hoTen << endl;
    file << buoiVang << endl;
    file << DiemTH << endl;
    file << DiemGK << endl;
}
void QLD::docFile(ifstream &file)
{
    getline(file, mssv);
    getline(file, hoTen);
    file >> buoiVang;
    file.ignore();
    file >> DiemTH;
    file.ignore();
    file >> DiemGK;
    file.ignore();
}
void QLD::xuat(int n, float diemQT)
{
    // cout << "MSSV" << "\t\tHo va ten" << "\t\tSo buoi vang" << "\t\tDiem TH" << "\t\tDiemGK\n";
    int _n = n;
    float _diemQT = diemQT;
    int size = mssv.size();
    for (int i = 0; i < 12 - 5 - size; i++)
    {
        mssv = " " + mssv;
    }
    while (mssv.size() != 12)
    {
        mssv += " ";
    }
    if (_diemQT == 0 && (_n == 2 || _n == 4 || _n == 5 || _n == 6))
    {
        cout << getMSSV() << "\t      "
             << getHoTen() << "\t\t     "
             << getBuoiVang() << "\t\t\t "
             << getDiemTH() << "\t\t "
             << getDiemGK() << endl;
    }
    else
    {
        cout << getMSSV() << "\t      "
             << getHoTen() << "\t\t     "
             << getBuoiVang() << "\t\t\t "
             << getDiemTH() << "\t\t "
             << getDiemGK() << "\t\t "
             << diemQT << endl;
    }
}
void QLD::DiemQT(int n)
{
    int _n = n;
    float diemQT;
    if (getBuoiVang() <= 5)
        diemQT = (10 - getBuoiVang() * 2) * 0.2 + getDiemTH() * 0.3 + getDiemGK() * 0.5;
    else
        diemQT = 0;
    int size = mssv.size();
    for (int i = 0; i < 12 - 5 - size; i++)
    {
        mssv = " " + mssv;
    }
    while (mssv.size() != 12)
    {
        mssv += " ";
    }
    if (_n == 0)
        xuat(3, diemQT);
    else if (n == 4 && diemQT >= 3)
        xuat(4, diemQT);
}
void QLD::DSSV_duDieuKienDuThi()
{
    DiemQT(4);
}
void QLD::DSSV_hoNguyen()
{
    string hoVaTen = getHoTen();
    xoakt(hoVaTen);
    string copyFirstName = "";
    for (int i = 0; i < 6; i++)
    {
        copyFirstName += hoVaTen[i];
    }
    if (copyFirstName == "Nguyen")
        xuat(5, 0);
}
void QLD::DSSV_cungTen(vector<string> ds)
{
    QLD qld1;
    string name = "";
    vector<string> names = ds;
    bool flag = true;
    if (names.empty())
    {
        cout << "\t\t\t!!!!!!Loi--Danh sach khong co sinh vien!!!!!!\n";
        flag = false;
    }

    if (flag)
    {
        sort(names.begin(), names.end());
        bool flag1 = false;
        for (int i = 0; i < names.size() - 1; i++)
        {
            for (int j = i + 1; j < names.size(); j++)
            {
                if (names[i] == names[j])
                {
                    flag1 = true;
                    break;
                }
            }
        }
        if (flag1 == false)
            names = {};
        if (flag1)
        {
            for (int i = 0; i < names.size() - 1; i++)
            {
                if (names[i] != names[i + 1])
                {
                    names.erase(names.begin() + (i));
                    i--;
                }
            }
            for (int i = 0; i < names.size() - 1; i++)
            {
                if (names[i] == names[i + 1])
                {
                    names.erase(names.begin() + (i));
                    i--;
                }
            }
        }
    

    if (!names.empty())
    {
        // ifstream file1("data.QLD");
        for (string list : names)
        {
            name = list;
            // int count = 0;
            ifstream file1("data.QLD");
            cout << "\nDanh sach sinh vien co cung ten \"" << name << "\" la:\n";
            cout << "\n\t\t\t\t--------Danh sach sinh vien--------\n";
            cout << "    MSSV"
                 << "\t\tHo va ten"
                 << "\t\tSo buoi vang"
                 << "\t\tDiemTH"
                 << "\t\tDiemGK\n";
            while (!file1.eof())
            {
                
                qld1.docFile(file1);

                if (qld1.getMSSV().empty())
                    continue;
                string ho_ten1 = qld1.getHoTen();
                xoakt(ho_ten1);
                string ten1 = "";
                for (int i = ho_ten1.size() - 1; i >= 0; i--)
                {
                    if (ho_ten1[i] == 32)
                        break;
                    else
                        ten1 = ho_ten1[i] + ten1;
                }

                if (name == ten1)
                {
                    qld1.xuat(6, 0);
                }
                
            }
            file1.close();
        }
        
    }
    else
        cout << "\t\t--------------Danh sach khong co sinh vien trung ten--------------\n";
    }
}

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdio>

#include "Headers/TTN.h"

// Dung de xoa man hinh
#ifdef _WIN32
constexpr auto CLEAR_COMMAND = "cls";
#else
constexpr auto CLEAR_COMMAND = "clear";
#endif

using namespace std;

static void inMenu()
{
    system(CLEAR_COMMAND);
    cout << "MSSV: 079205031041 - Ho ten: Ly Chi Thien\n";
    cout << "\t\t\tChuong trinh thi trac nghiem\t\t\t\n";
    cout << "1. Tao de thi trac nghiem.\n";
    cout << "2. Thi trac nghiem.\n";
    cout << "3. Kiem tra khoang trang thua cua de thi da co va sua loi.\n";
    cout << "4. Thoat chuong trinh.\n\n";
}

static void enterToContinue()
{
    cout << "Nhan Enter de tiep tuc...";
    cin.get();
}

void xoa(string &s, int vt);
void xoakt(string &s);

int main()
{
    CauhoiTN cauHoi;
    string name;
    string fileName = ".TTN";
    bool running = true;
    char xn;
    while (true)
    {
        cout << "MSSV: 079205031041 - Ho ten: Ly Chi Thien\n";
        cout << "\t\t\tChuong trinh thi trac nghiem\t\t\t\n";
        cout << "Nhap vao ten file - duoi file mac dinh la (.TTN)\n";
        cout << "Nhap ten: ";
        cin >> name;
        cin.ignore();
        fileName = name + fileName;
        ifstream kiemTraFile(fileName);
        if (kiemTraFile.is_open())
        {
            cout << "File da ton tai!!!\n";
            cout << "Ban co muon tiep tuc tren file nay?\n";
            do
            {
                cout << "Nhap \"y\" de tiep tuc - \"n\" de tao lai file: ";
                cin >> xn;
                cin.ignore();
                if (xn != 'y' && xn != 'n')
                    cout << "Chi duoc nhap \"y\" hoac \"n\"!!!\n";
            } while (xn != 'y' && xn != 'n');
            if (xn == 'n')
            {
                fileName = ".TTN";
                system(CLEAR_COMMAND);
                continue;
            }
        }
        kiemTraFile.close();
        break;
    }

    cout << "Tao file de thi thanh cong!\n";
    ofstream taoFile(fileName, ios_base::app);
    taoFile.close();
    enterToContinue();
    int count = 0;
    while (running)
    {
        if (running == false)
            break;

        // TODO: lam sao de khong hardcode doan options
        vector<int> options = {1, 2, 3, 4};
        int option;
        bool valid = false; // Flag de danh dau lua chon phu hop
        inMenu();
        do
        {
            cout << "Chon tuy chon: \n> ";
            cin >> option;
            cin.ignore();
            for (int validOption : options)
                if (option == validOption)
                    valid = true;
        } while (!valid);

        switch (option)
        {
        case 1: // Tao de thi
        {
            char xacNhan;
            if (xn == 'y' || count > 1)
            {
                cout << "Ban co muon ghi tiep cau hoi dua tren cau hoi truoc do khong?\n";
                do
                {
                    cout << "Nhap Y(Yes)/N(No):";
                    cin >> xacNhan;
                    cin.ignore();
                    if (xacNhan != 'y' && xacNhan != 'n')
                        cout << "Chi duoc nhap \"y\" hoac \"n\"!!!\n";
                } while (xacNhan != 'y' && xacNhan != 'n');
                // if(xacNhan == 'n') count = 0;
                if (toupper(xacNhan) == 'Y')
                {
                    ofstream file(fileName, ios_base::app);
                    ifstream file1(fileName);
                    int n;
                    cout << "Nhap so luong cau hoi: \n> ";
                    cin >> n;
                    cin.ignore();
                    vector<string> kt;
                    for (int i = 0; i < n; i++)
                    {
                        system(CLEAR_COMMAND);
                        cauHoi.nhap();
                        

                        string dapAnDung = to_string(cauHoi.getDapAnDung());

                        kt.push_back(cauHoi.getNoiDung());
                        kt.push_back(cauHoi.getDapAnA());
                        kt.push_back(cauHoi.getDapAnB());
                        kt.push_back(dapAnDung);
                        if (giongNhau(file1, cauHoi.getNoiDung(), cauHoi.getDapAnA(), cauHoi.getDapAnB(), cauHoi.getDapAnDung(), kt))
                        {
                            char xn;
                            cout << "Cau hoi va dap an da co trong de thi!\n";
                            cout << "Nhap \'Y\' de them hoac \'N\' de huy bo: ";
                            cin >> xn;
                            cin.ignore();
                            if (toupper(xn) == 'Y')
                                cauHoi.ghiFile(file);
                            else
                                n++;
                        }
                        else
                            cauHoi.ghiFile(file);
                    }
                    // for(string t : kt)
                    file.close();
                    cout << "Tao de thi thanh cong!\n\n";
                    enterToContinue();
                    break;
                }
            }

            if (count == 0)
            {
                ofstream file(fileName);
                ifstream file1(fileName);
                int n;
                cout << "Nhap so luong cau hoi: \n> ";
                cin >> n;
                cin.ignore();
                vector<string> kt;
                for (int i = 0; i < n; i++)
                {
                    system(CLEAR_COMMAND);
                    cauHoi.nhap();
                    

                    string dapAnDung = to_string(cauHoi.getDapAnDung());

                    kt.push_back(cauHoi.getNoiDung());
                    kt.push_back(cauHoi.getDapAnA());
                    kt.push_back(cauHoi.getDapAnB());
                    kt.push_back(dapAnDung);
                    if (giongNhau(file1, cauHoi.getNoiDung(), cauHoi.getDapAnA(), cauHoi.getDapAnB(), cauHoi.getDapAnDung(), kt))
                    {
                            char xn;
                            cout << "Cau hoi va dap an da co trong de thi!\n";
                            cout << "Nhap \'Y\' de them hoac \'N\' de huy bo: ";
                            cin >> xn;
                            cin.ignore();
                            if (toupper(xn) == 'Y')
                                cauHoi.ghiFile(file);
                            else
                                n++;
                        }
                        else
                            cauHoi.ghiFile(file);
                }
                file.close();
                cout << "Tao de thi thanh cong!\n\n";
                count++;
                enterToContinue();
                break;
            }
        }
        case 2: // Tien hanh thi trac nghiem
        {
            system(CLEAR_COMMAND);
            char xacNhan;
            ifstream file(fileName);
            if (!file.is_open())
            {
                cout << "Loi: De thi khong ton tai!\n\n";
                enterToContinue();
                break;
            }
            int diem = 0, soCauHoi = 0;

            cout << "Bat dau thi: \n";
            while (!file.eof())
            {
                cout << endl;
                cauHoi.docFile(file);
                // Vi luc nhap cau hoi, ki tu cuoi cung la ki tu xuong dong
                // Nen phai loai bo cau hoi cuoi cung - cau hoi trong
                if (cauHoi.getNoiDung().empty())
                    continue;
                if (cauHoi.kiemTra())
                    diem++;
                soCauHoi++;
            }

            cout << "Ban tra loi dung " << diem << "/" << soCauHoi << " cau hoi.\n\n";
            cout << "Ban co muon xem cau hoi va dap an khong?\n";
            cout << "Nhap Y/N(nhap thuong cung duoc): ";
            cin >> xacNhan;
            cin.ignore();
            if (toupper(xacNhan) == 'Y')
            {
                ifstream file1(fileName);
                while (!file1.eof())
                {
                    cauHoi.docFile(file1);
                    if (cauHoi.getNoiDung().empty())
                        continue;
                    cauHoi.xuat();
                }
            }

            file.close();
            enterToContinue();
            break;
        }
        case 3: // Kiem tra khoang trang thua va xoa chung
        {
            ifstream fileIn(fileName);
            if (!fileIn.is_open())
            {
                cout << "Loi: De thi khong ton tai!\n\n";
                enterToContinue();
                break;
            }
            string line, result = "";
            while (getline(fileIn, line))
            {

                xoakt(line);
                cout << line << endl;
                result += line;
                result += "\n";
            }

            ofstream fileOut(fileName);
            fileOut << result;
            fileOut.close();

            cout << "Da xoa cac khoang trang khong can thiet va ghi lai de bai.\n\n";
            enterToContinue();
            break;
        }
        case 4: // Thoat chuong trinh
        {
            char xacNhan;
            cout << "Ban co muon giu file nay khong?\n";
            do
            {
                cout << "Nhap y/n: ";
                cin >> xacNhan;
                cin.ignore();
                if (xacNhan != 'y' && xacNhan != 'n')
                    cout << "Chi duoc nhap y/n!!!\n";
            } while (xacNhan != 'y' && xacNhan != 'n');
            cout << xacNhan << endl;
            if (xacNhan == 'n')
            {
                const char *fileCanXoa = fileName.c_str();
                remove(fileCanXoa);
            }
            running = false;
            break;
        }
        }
    }
}

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
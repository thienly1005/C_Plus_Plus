#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Headers/QLD.h"

// Dung de xoa man hinh
#ifdef _WIN32
constexpr auto CLEAR_COMMAND = "cls";
#else
constexpr auto CLEAR_COMMAND = "clear";
#endif

using namespace std;

void enterToContinue() // tranh viec thoat dot ngot khi dang tuong tac
{
    cout << "Nhan Enter de tiep tuc...";
    cin.get(); // nhan vao mot ki tu bat kì
}

int main()
{
    QLD qld;
    bool running = true;
    
    while (running)
    {
        if (running == false)
            break;
        system(CLEAR_COMMAND); // xoa man hinh console hien tai
        cout << "MSSV: 079205031041 - Ho ten: Ly Chi Thien.\n";
        cout << "Chuong trinh quan li diem qua trinh va xet dieu kien du thi cho sinh vien.\n";
        cout << "1. Nhap thong tin sinh vien.\n";
        cout << "2. In danh sach sinh vien.\n";
        cout << "3. Tinh diem qua trinh.\n";
        cout << "4. In danh sach sinh vien du dieu kien du thi (co DiemQt >= 3).\n";
        cout << "5. In danh sach cac sinh vien co ho la \"Nguyen\".\n";
        cout << "6. In danh sach tat ca sinh co cung ten.\n";
        cout << "7. Thoat khoi chuong trinh.\n";
        vector<int> options = {1, 2, 3, 4, 5, 6, 7}; // su dung vector de tranh hardcode doan options hoac su dung array
        //  int options[7] = {1, 2, 3, 4, 5, 6, 7};
        int option;
        bool valid = false; // Flag de danh dau lua chon phu hop
        do
        {
            cout << "Chon: ";
            cin >> option;
            cin.ignore();
            for (int validOption : options)
            {
                if (option == validOption)
                {
                    valid = true;
                    break;
                }
            }

        } while (!valid);

        switch (option)
        {
        case 1:
        {
            char accept;
            cout << "Ban co muon nhap du lieu dua vao danh sach truoc do khong?\n";
            cout << "Nhap y/n: ";

            do
            {
                cin >> accept;
                if (accept != 'y' && accept != 'n')
                    cout << "Chi duoc nhap y/n: ";
            } while (accept != 'y' && accept != 'n');

            if (accept == 'y')
            {
                ofstream file("data.QLD", ios_base::app);
                int n;
                cout << "Nhap vao so luong sinh vien muon nhap: ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++)
                {
                    system(CLEAR_COMMAND);
                    qld.nhap();
                    qld.ghiFile(file);
                }
                file.close();
                // enterToContinue();
                break;
            }
            else if (accept == 'n')
            {
                ofstream file("data.QLD");
                int n;
                cout << "Nhap vao so luong sinh vien muon nhap: ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++)
                {
                    system(CLEAR_COMMAND);
                    qld.nhap();
                    qld.ghiFile(file);
                }
                file.close();
                // enterToContinue();
                break;
            }
        }
        case 2:
        {
            system(CLEAR_COMMAND);
            ifstream file("data.QLD");
            cout << "\n\t\t\t\t--------Danh sach sinh vien--------\n";
            cout << "    MSSV"
                 << "\t\tHo va ten"
                 << "\t\tSo buoi vang"
                 << "\t\tDiemTH"
                 << "\t\tDiemGK\n";
            while (!file.eof())
            {
                qld.docFile(file);
                if (qld.getMSSV().empty())
                    continue;
                qld.xuat(2, 0);
            }
            file.close();
            enterToContinue();
            break;
        }

        case 3:
        {
            system(CLEAR_COMMAND);
            ifstream file("data.QLD");
            cout << "\n\t\t\t\t--------Danh sach sinh vien sau khi tinh diem qua trinh--------\n";
            cout << "    MSSV"
                 << "\t\tHo va ten"
                 << "\t\tSo buoi vang"
                 << "\t\tDiemTH"
                 << "\t\tDiemGK"
                 << "\t\tDiemQT\n";
            while (!file.eof())
            {
                qld.docFile(file);
                if (qld.getMSSV().empty())
                    continue;
                qld.DiemQT(0);
            }
            file.close();
            enterToContinue();
            break;
        }
        case 4:
        {
            system(CLEAR_COMMAND);
            ifstream file("data.QLD");
            cout << "\n\t\t\t\t--------Danh sach sinh vien du dieu kien du thi--------\n";
            cout << "    MSSV"
                 << "\t\tHo va ten"
                 << "\t\tSo buoi vang"
                 << "\t\tDiemTH"
                 << "\t\tDiemGK"
                 << "\t\tDiemQT\n";
            while (!file.eof())
            {
                qld.docFile(file);
                if (qld.getMSSV().empty())
                    continue;
                qld.DSSV_duDieuKienDuThi();
            }
            file.close();
            enterToContinue();
            break;
        }
        case 5:
        {
            system(CLEAR_COMMAND);
            ifstream file("data.QLD");
            cout << "\n\t\t\t\t--------Danh sach sinh vien co ho \"Nguyen\"--------\n";
            cout << "    MSSV"
                 << "\t\tHo va ten"
                 << "\t\tSo buoi vang"
                 << "\t\tDiemTH"
                 << "\t\tDiemGK\n";
            while (!file.eof())
            {
                qld.docFile(file);
                if (qld.getMSSV().empty())
                    continue;
                qld.DSSV_hoNguyen();
            }
            file.close();
            enterToContinue();
            break;
        }
        case 6:
        {
            system(CLEAR_COMMAND);
            ifstream file("data.QLD");

            vector<string> danhSach;
            while (!file.eof())
            {
                qld.docFile(file);
                if (qld.getMSSV().empty())
                    continue;
                string ho_ten = qld.getHoTen();
                string ten = "";
                for (int i = ho_ten.size() - 1; i >= 0; i--)
                {
                    if (ho_ten[i] == 32)
                        break;
                    else
                        ten = ho_ten[i] + ten;
                }
                danhSach.push_back(ten);
            }
            qld.DSSV_cungTen(danhSach);
            file.close();
            enterToContinue();
            break;
        }
        case 7:
        {
            running = false;
            break;
        }
        }
    }

    return 0;
}

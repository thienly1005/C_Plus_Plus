#include <iostream>
#include <fstream>
#include <vector>

#include "Headers/TTN.cpp"

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
    cout << "==== MSSV: 079205031041 - Ho ten: Ly Chi Thien ====\n";
    cout << "= Chuong trinh thi trac nghiem =\n";
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

int main()
{
    CauhoiTN cauHoi;
    bool running = true;
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
            cout << "Ban co muon ghi tiep cau hoi dua tren cau hoi truoc do khong?\n";
            cout << "Nhap Y(Yes)/N(No):";
            cin >> xacNhan;
            if (toupper(xacNhan) == 'Y')
            {
                ofstream file("data.TTN", ios_base::app);
                ifstream file1("data.TTN");
                int n;
                cout << "Nhap so luong cau hoi: \n> ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++)
                {
                    system(CLEAR_COMMAND);
                    cauHoi.nhap();
                    if(giongNhau(file1, cauHoi.getNoiDung(), cauHoi.getDapAnA(), cauHoi.getDapAnB(), cauHoi.getDapAnDung())){
                        char xn;
                        cout << "Cau hoi va dap an da co trong de thi!\n";
                        cout << "Nhap \'Y\' de them hoac \'N\' de huy bo: "; cin >> xn;
                        cin.ignore();
                        if(toupper(xn)=='Y') cauHoi.ghiFile(file);
                        else n++;
                    }
                    else cauHoi.ghiFile(file);
                    
                }
                
                file.close();
                cout << "Tao de thi thanh cong!\n\n";
                enterToContinue();
                break;
            }
            else
            {
                ofstream file("data.TTN");
                ifstream file1("data.TTN");
                int n;
                cout << "Nhap so luong cau hoi: \n> ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++)
                {
                    system(CLEAR_COMMAND);
                    cauHoi.nhap();
                    if(giongNhau(file1, cauHoi.getNoiDung(), cauHoi.getDapAnA(), cauHoi.getDapAnB(), cauHoi.getDapAnDung()))
                    cout << "Cau hoi va dap an da co trong de thi!\n";
                    cauHoi.ghiFile(file);
                }
                file.close();
                cout << "Tao de thi thanh cong!\n\n";
                enterToContinue();
                break;
            }
        }
        case 2: // Tien hanh thi trac nghiem
        {
            char xacNhan;
            ifstream file("data.TTN");
            if (!file.is_open())
            {
                cout << "Loi: De thi khong ton tai!\n\n";
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
            cout << "Nhap Y/N(nhap thuong cung duoc): "; cin >> xacNhan;
            cin.ignore();
            if (toupper(xacNhan) == 'Y')
            {
                ifstream file1("data.TTN");
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
            ifstream fileIn("data.TTN");
            if (!fileIn.is_open())
            {
                cout << "Loi: De thi khong ton tai!\n\n";
                break;
            }
            string line, result = "";
            while (getline(fileIn, line))
            {
                bool lastCharIsSpace = true; // Flag de biet ki tu truoc co la khoang trang khong

                for (int i = 0; i < line.size(); i++)
                {
                    if (!isspace(line[i]) || (isspace(line[i]) && lastCharIsSpace == false))
                    {
                        result += line[i];
                        lastCharIsSpace = false;
                    }
                    else
                        lastCharIsSpace = true;
                }
                result += "\n";
            }

            ofstream fileOut("data.TTN");
            fileOut << result;
            fileOut.close();

            cout << "Da xoa cac khoang trang khong can thiet va ghi lai de bai.\n\n";
            enterToContinue();
            break;
        }
        case 4: // Thoat chuong trinh
        {
            running = false;
            break;
        }
        }
    }
}
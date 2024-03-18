#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int soDong=0;
    ofstream file("data.txt", ios_base::app); 

    if (!file.is_open()) { 
        cout << "Mo file khong thanh cong!" << endl;
        return 1; 
    }

    string line;

    cout << "Nhap cac chuoi (nhap 'exit' de ket thuc):\n";
    while (true) {
        getline(cin, line);
        if (line == "exit") {
            break;
        }
        file << line << endl;
    }

    file.close(); 

    ifstream readFile("data.txt");
    if (!readFile.is_open()) {
        cout << "Mo file khong thanh cong!" << endl;
        return 1;
    }

    cout << "\nDanh sach cac chuoi da nhap:\n";
    while (getline(readFile, line)) {
        soDong++;
        if(line.compare(0, 1, "-") == 0) cout << line << endl;
    }
	cout << "Co" << soDong << " trong file data.txt\n";
    return 0; 
}


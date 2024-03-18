// main.cpp
#include <bits/stdc++.h>
using namespace std;
class SinhVien{
	private:
		string id, hoTen, ngaySinh;
		double gpa;
		static int dem;
	public:
		string setID();
		string sethoTen();
		string setngaySinh();
		double setgpa();
		void getid();
//		void getHoten();
//		void getngaySinh();
//		void getgpq();
		SinhVien();
		~SinhVien();
		void nhap();
		void in();
		int getDem();
};

int SinhVien::dem = 0;

void SinhVien::nhap(){
	++dem;
	this->id = "SV" + string(3 - to_string(dem).length(), '0') + to_string(dem);
	
//	cout << "Nhap id: "; cin >> id;
//	cin.ignore();
	cout << "Nhap ten: "; cin >> hoTen;
//	cin.ignore();
	cout << "Nhap ns: "; cin >> ngaySinh;
//	cin.ignore();
	cout << "Nhap diem: "; cin >> gpa;
	this->in();
}

void SinhVien::in(){
	cout << id << " " << hoTen << " " << ngaySinh << " " << fixed << setprecision(2) << gpa << endl;
}
void SinhVien::getid(){
	cout << "dau:\n";
	cout << this->id << endl;
	cout << "cuoi\n";
}
SinhVien::SinhVien(){
	cout << "khoi tao doi tuong\n";
}
SinhVien::~SinhVien(){
	cout << "huy doi tuong\n";

}
int main(){
	string name, res = "";
	cout << "Nhap name: "; getline(cin, name);
	stringstream ss(name);
	string newName;
	cout << "Ten chua chinh sua: " << name << endl;
	while(ss >> newName){
		res += toupper(newName[0]);
		int i = 1;
		while(i<newName.length()){
			res += tolower(newName[i]);
			i++;
		}
		res += " ";
	}
	cout << "Ten da chinh sua: " << res << endl;
}

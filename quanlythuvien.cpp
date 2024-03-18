#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
struct sinhVien{
	string hoten = "NgUyen Van C";
		int msv = 2;
		double gpa = 10;
		string quequan= "Hai Phong";
	sinhVien(){
		hoten = "NgUyen Van B";
		msv = 2;
		gpa = 10;
		quequan= "Hai Phong";
	};
	sinhVien(string name, int ma, double diem, string qq){
		hoten = name;
		msv = ma;
		gpa = diem;
		quequan = qq;
	};
	void in(){
		cout << hoten << endl << msv << endl << fixed << setprecision(2) << gpa << endl << quequan << endl;
	}
	void nhap(){
		cout << "Nhap ho ten sv X: "; getline(cin,hoten);
		cout << "Nhap msv cua X: "; cin >> msv;
		cout << "Nhap gpa cua X: "; cin >> gpa;
		cin.ignore();
		cout << "Nhap que quan cua X: "; getline(cin,quequan);
	}
};
struct sophuc{
	int a; int b;
};
int main(){
	sophuc a = {1, 2}; sophuc b = {3, 4};
	sophuc c = a + b;
	return 0;
}
	

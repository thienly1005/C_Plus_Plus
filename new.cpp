#include <iostream>
#include <cmath>
//#include <stdafx.h>
#include <conio.h>
using namespace std;
	struct CongNhan{
		char ten[50];
		int namsinh;
		int giolam;
	};
void XuatCN(CongNhan *p, int n);
void NhapCN(int &n, CongNhan *p);

int main(){
	struct CongNhan *p;
	CongNhan A[1000];
	int N;
	p=A;
	NhapCN(N, p);
	XuatCN(p, N);
}
void NhapCN(int &n, CongNhan *p){
	do{
		cout << "Cho biet so cong nhan: ";
		cin >> n;
	}while(n<=0);
	for(int i=0; i<n; i++){
		cout << "Thong tin cong nhan thu " << i+1 << " la:";
		cout << "\nTen la:";
		cin.ignore();
		cin.getline((p+i)->ten,100);
		cout << "Nam Sinh:";
		cin >> (p+i)->namsinh ;
		cout << "Gio lam:";
		cin >> (p+i)->giolam ;
	}
}
void XuatCN(CongNhan *p, int n){
	for(int i=0; i<n; i++){
		cout << "\n================================";
		cout << "\nThong tin cong nhan thu " << i+1 << " la:";
		cout << "\nTen la: " << (p+i)->ten;
		cout << "\nNam Sinh la: " << (p+i)->namsinh;
		cout << "\nGio lam: " << (p+i)->giolam;
	}
}

#include <iostream>
using namespace std;

struct LopHoc{
	int maso;
	char hoten[30];
	char phai[4];
	float diemHK1;
	float diemHK2;
}ds[50];
void NhapDsLop(int n, LopHoc *p);
void XuatDsLop(int n, LopHoc *p);
int main(){
	struct LopHoc *p;
	int n;
	do{
		cout << "Nhap vao so luong hoc sinh: ";
		cin >> n;
	}while(n<=0 || n>50);
	NhapDsLop(n, p);
	XuatDsLop(n, p);
}
void NhapDsLop(int n, LopHoc *p){
	for(int i=0; i<n; i++){
		cout << "Nhap vao ma so sinh vien thu " << i+1 << ": ";
		cin >> ds[i].maso;
		cout << "Nhap vao ho ten hoc sinh thu " << i+1 << ": ";
		cin.ignore();
		cin.getline(ds[i].hoten, 30);
		cin.getline(ds[i].phai, 4);
		cin >> ds[i].diemHK1;
		cin >> ds[i].diemHK2;
	}
}
void XuatDsLop(int n, LopHoc *p){
	for(int i=0; i<n; i++){
	 	cout << "Ma so sinh vien thu " << i+1 << ": " << ds[i].maso;
		 cout << "Ho ten sinh vien thu " << i+1 << ": "<< ds[i].hoten;
	}	
}	
	

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//int main() {
//    // Thi?t l?p seed cho hàm random b?ng th?i gian hi?n t?i
//    std::srand(std::time(0));
//
//    // T?o s? ng?u nhiên trong kho?ng t? 1 d?n 100
//    int randomNumber = std::rand() % 100 + 1;
//
//    // Hi?n th? s? ng?u nhiên
//    std::cout << "Random Number: " << randomNumber << std::endl;
//
//    return 0;
//}
# define MAXSIZE 10
typedef int  Int;
void taoMang1C(int a[], int &n){
	do{
		cout << "Nhap vao so ptu trong mang: "; cin >> n;
	}while(n<=0);
	srand((unsigned)time(NULL));
	for(int i = 0 ; i<n ;i++){
		a[i] = (rand()%199)-99; // -99 -> 99
	}
}
void xuatMang1C(int a[], int n){
	cout << "[";
	for(int i=0 ; i<n ; i++){
		if (i!=n-1) cout << a[i] << ", ";
		else cout << a[i];
	}
	cout << "]";
}
void themPTu(int a[], int &n, int x, int vt){
	for(int i=n ; i>vt ; i--){
		a[i] = a[i-1];
	}
	a[vt] = x;
	n++;
	xuatMang1C(a, n);
}
int timPTu(int a[],int n,int x){
	for(int i=0 ; i<n ; i++){
		if(a[i] == x) return i; 
	}
	return -1;
}
void xoaPTu(int a[], int n, int x){
	int vt = timPTu(a, n, x);
	if(x==-1) cout << "Xoa ptu ko hop le.";
	else{
		for(int i=vt ; i<=n-2 ; i++){
			a[i] = a[i+1];
		}
		n--;
		cout << "da xoa phan tu " << x << " tai vi tri " << vt << endl;
		cout << "mang sau khi xoa : {";
		for(int i=0 ; i<n ; i++){
			if(i!=n-1) cout << a[i] << ", ";
			else cout << a[i] << "}";
		}
	}
}
void swap(int &a, int &b){
	int t=a; a=b ; b=t;
}
void sapXepTang(int a[], int n){
	for(int i=0 ; i<n-1 ; i++){
		for(int j=i+1 ; j<n ; j++){
			if(a[i]>a[j]) swap(a[i], a[j]);
		}
	}
	xuatMang1C(a, n);
}
void kiemTraSoChinhPhuong(int a[], int n){
	for(int i=0 ; i<n ; i++){
		int temp = sqrt(a[i]);
		if(temp*temp == a[i]) cout << "Phan tu "<< a[i] << " tai vi tri " << i << " la so chinh phuong.\n";
	}
}
int giaTriChan(int a[], int n){
	for(int i = 0 ; i<n ; i++){
		if(a[i] % 2 == 0) return i;
	}
	return -1;
}
void daoViTri(int a[], int n){
	int j=n-1;
	for(int i=0 ; i<n ; i++){
		if(i>=j) break;
		swap(a[i], a[j]);
		j--;
		
	}
	xuatMang1C(a, n);
}
int main(){
	int n, x, vt;
	int a[6] = {14, 9, 65, 47, 31, 1};
	cout << "Nhap vao so ptu trong mang: "; cin >> n;
//	kiemTraSoChinhPhuong(a, n);
	daoViTri(a, n);
	return 0;
}

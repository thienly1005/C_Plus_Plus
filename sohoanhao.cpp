#include <iostream>
using namespace std;
bool soHoanHao(int n){
	int kt=0;
	for(int i=1; i<n; i++){
		kt += i;
		if(kt==n) return true;
	}
	return false;
}
int main(){
	int n;
	cout << "Nhap vao so n: "; cin >> n;
	if(soHoanHao(n)) cout << n << " la so hoan hao.\n";
	else cout << n << " khong phai la so hoan hao.\n";
}
	

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b); // USCLN 
}
ll lcm(ll a, ll b){
	return a / gcd(a, b) * b; // BSCNN
class PhanSo{
	private:
		ll tu, mau;
	public:
		PhanSo(ll tu, ll mau);
		friend ostream& operator << (ostream& , PhanSo);
		friend istream& operator >> (istream& , PhanSo&);
		void RutGon();
		friend PhanSo operator + (PhanSo, PhanSo);
};
PhanSo::PhanSo(ll tu, ll mau){
	this->tu = tu;
	this->mau = mau;
}
ostream& operator << (ostream& out, PhanSo a){
	out << a.tu << "/" << a.mau << endl;
	return out;
}
istream& operator >> (istream& in, PhanSo &a){
	in >> a.tu >> a.mau;
	return in;
}
void PhanSo::RutGon(){
	ll g = gcd(tu, mau);
	tu /= g;
	mau /= g;
}
Phan
int main(){
	PhanSo p(1, 1);
	cin >> p;
	p.RutGon();
	cout << p;

	return 0;
	
}


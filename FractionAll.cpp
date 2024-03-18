#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int _numerator, int _denominator);
    void input();
    Fraction add(Fraction ps);
    void print();
    void RutGon();
    int gcd(int a, int b) const;
};
Fraction::Fraction() {
        numerator= 0;
        denominator = 1;
    }
Fraction::Fraction(int _numerator, int _denominator) {
        numerator= _numerator;
        denominator = _denominator;
    }
void Fraction::input() {
    	cout << "Nhap tu so: ";
        cin >> numerator;
        do{
	        cout << "Nhap mau so: ";
	        cin >> denominator;
	        if(denominator==0) cout << "Loi! Nhap lai phan so khac 0";
		}while(denominator==0);
    }
Fraction Fraction::add(Fraction ps) {
        Fraction addFraction;

		if(denominator != ps.denominator){
			addFraction.numerator = numerator* ps.denominator + ps.numerator* denominator;
			addFraction.denominator = denominator * ps.denominator;
		}
		else{
			addFraction.numerator = numerator + ps.numerator;
			addFraction.denominator = denominator;
		}  
        return addFraction;
    }
void Fraction::print() {
    	if(denominator!=1) cout << numerator<< "/" << denominator << endl;
        else cout << numerator << endl;
    }
void Fraction::RutGon(){
	int g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
}
int Fraction::gcd(int a, int b) const{
		if(b == 0) return a;
		return gcd(b, a%b); 
	}
int main() {
    Fraction ps1, ps2, add;

    cout << "Nhap phan so thu nhat:\n";
    ps1.input();
    ps1.RutGon();

    cout << "Nhap phan so thu hai:\n";
    ps2.input();
    ps2.RutGon();

    add = ps1.add(ps2);
    add.RutGon();

    cout << "Tong cua hai phan so la: ";
    add.print();

    return 0;
}

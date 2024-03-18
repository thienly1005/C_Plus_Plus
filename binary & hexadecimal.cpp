#include <iostream>
#include <string>
using namespace std;
string binary(int decimal){
	if(decimal==0) return "0";
	string result = "";
	while(decimal > 0){
		result = to_string(decimal % 2) + result;
		decimal /= 2;
	}
	return result;
}
string hexadecimal(int decimal){
    if (decimal == 0)return "0"; 
    string result = ""; 
    while (decimal > 0) {
        int remainder = decimal % 16;
        char hexDigit = (remainder < 10) ? (char)(remainder + '0') : (char)(remainder - 10 + 'A');
        result = hexDigit + result;
        decimal /= 16;
    }
    return result;
}
string convert(int decimal, int heSo){
	if(heSo==2) return binary(decimal);
	else if(heSo==16) return hexadecimal(decimal);
	return 0;
}	
int main() {
    int decimal;int heSo;
    cout << "Nhap vao so thap phan: "; cin >> decimal;
    cout << "Nhap vao he so 2 hoac 16: "; cin >> heSo;
    cout << "So thap phan sau khi chuyen doi sang he " << heSo << " la: " << convert(decimal, heSo) << endl;
    return 0;
}

#include <iostream>
//#include <fstream> 
using namespace std;
int main(){
	int a[3] = {1, 2, 3};
	int b[3] = {4, 5, 6};
	int *ptr[2];
	ptr[0] = a;
	ptr[1] = b;
	//int c = ptr[0];
	cout << ptr[0][0] << endl;
	cout << ptr[1] << endl;
	
}

#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char S[101];
    cout << "Nhap vao chuoi S:";
    cin.getline(S, 100);
	while(S[0]==32 || S[0]==9){
		S[0] = S[1];
		for(int i=1 ; i<=strlen(S) ; i++){
			S[i] = S[i+1];
		}
	}
	int i=1;
	while(i!=strlen(S)){
		while((S[i]==32 || S[i]==9)){
			if(S[i+1]!=9 && S[i+1]!=32) break;
			S[i] = S[i+1];
			for(int j=i+1 ; j<=strlen(S) ; j++){
			S[j] = S[j+1];
			}	
		}
		i++;
	}
	cout << S ;
	return 0;
}

#include <iostream>
using namespace std;
void trungLap(int mang[], int n) {
	int dem=0;
	for(int i=0 ; i<n ; i++){
		for(int j=i+1 ; j<n ; j++){
			if(mang[i]==mang[j]) dem++;
		}
	}
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ) {
            if (mang[i] == mang[j]) {
                for (int k = j; k < n - 1; k++) {
                    mang[k] = mang[k + 1];
                }
                n--;
            } else {
                j++;
            }
        }
    }
    if(dem>=2){
		cout << "Mang co phan tu bi trung lap!\n";
		cout << "Mang sau khi xoa cac phan tu bi trung lap: ";
    	for(int i=0 ; i<n ; i++){
    		cout << mang[i] << " ";
    	}	
	}
    else{
    	cout << "Mang khong co phan tu nao bi trung lap!\n";
    	for(int i=0 ; i<n ; i++){
    		cout << mang[i] << " ";
    	}
    }
}
int main() {
    int mang[100], n;
    do{
    	cout << "Nhap vao so phan tu muon tao trong mang: "; cin >> n;
    	if(n<=0) cout << "So phan tu muon tao phai lon hon bang 1!\n";
	}while(n<=0);
	for(int i=0; i<n ; i++){
		cout << "Nhap vao phan tu thu " << i+1 << " cua mang: "; cin >> mang[i];
    }
    trungLap(mang, n);
    return 0;
}


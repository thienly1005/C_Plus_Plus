#include <iostream>

using namespace std;

int main(){
    for(int i=0 ; i<=15 ; i++){
        cout << "*  ";
        if(i==15){
            for(int i = 0 ; i<= 10; i++){
                
                if(i!=1 && i!=3 && i!=5){
                    cout << "\n*\t\t\t                     ";
                    cout << "*"; 
                }
                else if(i==1){
                    cout << "\r*  MSSV:.....................";
                }
                else if(i==3){
                    cout << "\r*  H? TÊN:......................";
                }
                else if(i==5){
                    cout << "\r*  TU?I:.........................";
                }
                

            }
        }
    }
    cout << endl;
    for (int i=0 ; i<=15 ; i++){
        cout << "*  ";
    }
    

}

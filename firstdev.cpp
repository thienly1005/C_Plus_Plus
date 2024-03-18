#include <iostream>
#include <conio.h>
using namespace std;
const int SIZE = 3;
void printBoard(int board[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                cout << "   ";
            } else {
                cout << board[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

// Hàm ki?m tra xem trò choi dã hoàn thành hay chua
//bool isGameComplete(int board[][SIZE]) {
//    int count = 1;
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            if (board[i][j] != count && !(i == SIZE - 1 && j == SIZE - 1 && board[i][j] == 0)) {
//                return false;
//            }
//            count++;
//        }
//    }
//    return true;
//}

// Hàm d?i ch? hai ô trên b?ng
void swapTiles(int& tile1, int& tile2) {
    int temp = tile1;
    tile1 = tile2;
    tile2 = temp;
}
void Move(char move, int board[][SIZE], int &a, int &b, int emptyRow, int emptyCol){
	switch (move) {
            case 'W':
            case 'w':
                
                    swapTiles(board[a][b], board[emptyRow][emptyCol]);
                
                break;
            case 'S':
            case 's':
                
                    swapTiles(board[a][b], board[emptyRow][emptyCol]);
                
                break;
            case 'A':
            case 'a':
                
                    swapTiles(board[a][b], board[emptyRow][emptyCol]);
                
                break;
            case 'D':
            case 'd':
                
                    swapTiles(board[a][b], board[emptyRow][emptyCol]);
                
                break;
            case 'Q':
            case 'q':
                cout << "Thoat chuong trinh." << endl;
            default:
                cout << "Phim khong hop le. Nhan Enter de nhap lai." << endl;
                getch(); // Ch? ngu?i choi nh?n Enter d? ti?p t?c
        }
}
bool check(int c, int d){
	if((c>=0&&c<SIZE)&&(d>=0&&d<SIZE)) return true;
	return false;
}
int main() {
    int board[SIZE][SIZE] = {{1, 3, 6}, {8, 0, 5}, {2, 4, 7}}; // Tr?ng thái kh?i d?u

    while (true) {
		system("cls"); // Xóa màn hình console
        printBoard(board);
		int emptyRow, emptyCol, n;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == 0) {
                    emptyRow = i;
                    emptyCol = j;
                    break;
                }
            }
        } 
		int EmptyRowLeft=emptyRow, EmptyColLeft=emptyCol-1;
        int EmptyRowRight=emptyRow, EmptyColRight=emptyCol+1;
        int EmptyRowTop=emptyRow-1, EmptyColTop=emptyCol;
        int EmptyRowBottom=emptyRow+1, EmptyColBottom=emptyCol;
        cout << "Chon o so di chuyen: ";
        if(check(EmptyRowLeft, EmptyColLeft)) cout << board[EmptyRowLeft][EmptyColLeft] << " ";
		if(check(EmptyRowRight, EmptyColRight)) cout << board[EmptyRowRight][EmptyColRight] << " ";
		if(check(EmptyRowTop, EmptyColTop)) cout << board[EmptyRowTop][EmptyColTop] << " ";
		if(check(EmptyRowBottom, EmptyColBottom)) cout << board[EmptyRowBottom][EmptyColBottom] << " ";
		cout << endl << "Chon o so: "; cin >> n;
        cout << "Nhan W (len), S (xuong), A (trai), D (phai), Q (thoat): ";
        char move = getch(); // Ð?c m?t phím t? bàn phím mà không c?n nh?n Enter
		if(n==board[EmptyRowLeft][EmptyColLeft]) Move(move, board, EmptyRowLeft, EmptyColLeft, emptyRow, emptyCol);
		if(n==board[EmptyRowRight][EmptyColRight]) Move(move, board, EmptyRowRight, EmptyColRight, emptyRow, emptyCol);
		if(n==board[EmptyRowTop][EmptyColTop]) Move(move, board, EmptyRowTop, EmptyColTop, emptyRow, emptyCol);
		if(n==board[EmptyRowBottom][EmptyColBottom]) Move(move, board, EmptyRowBottom, EmptyColBottom, emptyRow, emptyCol);
		
		
//        if (isGameComplete(board)) {
//            cout << "Chuc mung! Ban da hoan thanh tro choi." << endl;
//            break;
//        }
	}
    return 0;
}


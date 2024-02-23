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

bool isGameComplete(int board[][SIZE]) {
    int count = 1;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != count && !(i == SIZE - 1 && j == SIZE - 1 && board[i][j] == 0)) {
                return false;
            }
            count++;
        }
    }
    return true;
}

void swapTiles(int& tile1, int& tile2) {
    int temp = tile1;
    tile1 = tile2;
    tile2 = temp;
}

void Move(int board[][SIZE], int& emptyRow, int& emptyCol, int newRow, int newCol) {
    swapTiles(board[emptyRow][emptyCol], board[newRow][newCol]);
    emptyRow = newRow;
    emptyCol = newCol;
}

bool check(int c, int d) {
    return (c >= 0 && c < SIZE) && (d >= 0 && d < SIZE);
}

int main() {
    int board[SIZE][SIZE] = {{1, 3, 6}, {8, 5, 0}, {2, 4, 7}};
    int a, b, c, d;
    while (true) {
        system("cls"); // xoa man hinh console moi khi lap
        cout << "Bat dau tro choi Puzzle!\n";
        printBoard(board);

        if (isGameComplete(board)) {
            cout << "Chuc mung! Ban da hoan thanh tro choi." << endl;
            break;
        }

        int emptyRow, emptyCol;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == 0) {
                    emptyRow = i;
                    emptyCol = j;
                    break;
                }
            }
        }

        int EmptyRowLeft = emptyRow, EmptyColLeft = emptyCol - 1;
        int EmptyRowRight = emptyRow, EmptyColRight = emptyCol + 1;
        int EmptyRowTop = emptyRow - 1, EmptyColTop = emptyCol;
        int EmptyRowBottom = emptyRow + 1, EmptyColBottom = emptyCol;
		
        cout << "Chon o so de di chuyen: ";
        if (check(EmptyRowLeft, EmptyColLeft) && board[EmptyRowLeft][EmptyColLeft] != 0){
			a = board[EmptyRowLeft][EmptyColLeft];
			cout << a << " ";
		}
        if (check(EmptyRowRight, EmptyColRight) && board[EmptyRowRight][EmptyColRight] != 0){
			b = board[EmptyRowRight][EmptyColRight];
			cout << b << " ";
		}
        if (check(EmptyRowTop, EmptyColTop) && board[EmptyRowTop][EmptyColTop] != 0){
			c = board[EmptyRowTop][EmptyColTop];
			cout << c << " ";
		}
        if (check(EmptyRowBottom, EmptyColBottom) && board[EmptyRowBottom][EmptyColBottom] != 0){
			d = board[EmptyRowBottom][EmptyColBottom];
			cout << d << " ";
		}
        cout << "\nNhap o so(Nhap \'0\' hoac ki tu khac so nguyen de thoat): ";
		
		int n;
        do{
        	cin >> n;
        	if (n == 0) return 0;
        	if(n!=a && n!=b && n!=c && n!=d) cout << "Nhap sai so. Vui long nhap lai!!!\n" << "Nhap lai: ";
		}while(n!=a && n!=b && n!=c && n!=d);
        
        if (n == board[EmptyRowLeft][EmptyColLeft]) Move(board, emptyRow, emptyCol, EmptyRowLeft, EmptyColLeft);
        else if (n == board[EmptyRowRight][EmptyColRight]) Move(board, emptyRow, emptyCol, EmptyRowRight, EmptyColRight);
        else if (n == board[EmptyRowTop][EmptyColTop]) Move(board, emptyRow, emptyCol, EmptyRowTop, EmptyColTop);
        else if (n == board[EmptyRowBottom][EmptyColBottom]) Move(board, emptyRow, emptyCol, EmptyRowBottom, EmptyColBottom);
    }

    return 0;
}


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
void tuGiai(int board[][SIZE]){

		printBoard(board);
		for(int i=0 ; i<7 ; i++){
			for(int j=i+1 ; j<8 ; j++){
				for(int m=0 ; m<SIZE ; m++){
					for(int n=0 ; n<SIZE ; n++){
						if(board[m][n] > board[m][n+1]) swapTiles(board[m][n], board[m][n+1]);
					}
				}
			}
		}
		printBoard(board);
		
	}
bool check(int c, int d) {
    return (c >= 0 && c < SIZE) && (d >= 0 && d < SIZE);
}

int main() {
    int board[SIZE][SIZE] = {{1, 3, 0}, {5, 2, 6}, {4, 7, 8}};
	int esc;
    while (true) {
        system("cls");
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
        if (check(EmptyRowLeft, EmptyColLeft)) cout << board[EmptyRowLeft][EmptyColLeft] << " ";
        if (check(EmptyRowRight, EmptyColRight)) cout << board[EmptyRowRight][EmptyColRight] << " ";
        if (check(EmptyRowTop, EmptyColTop)) cout << board[EmptyRowTop][EmptyColTop] << " ";
        if (check(EmptyRowBottom, EmptyColBottom)) cout << board[EmptyRowBottom][EmptyColBottom] << " ";
        cout << "\nNhap o so(\'0\': thoat, \'10\': tu giai): ";

        int n;
		cin >> n;
		
		if(n==0) break;
		if(n==10) {tuGiai(board);break;}
        if (n == board[EmptyRowLeft][EmptyColLeft]) Move(board, emptyRow, emptyCol, EmptyRowLeft, EmptyColLeft);
        else if (n == board[EmptyRowRight][EmptyColRight]) Move(board, emptyRow, emptyCol, EmptyRowRight, EmptyColRight);
        else if (n == board[EmptyRowTop][EmptyColTop]) Move(board, emptyRow, emptyCol, EmptyRowTop, EmptyColTop);
        else if (n == board[EmptyRowBottom][EmptyColBottom]) Move(board, emptyRow, emptyCol, EmptyRowBottom, EmptyColBottom);
    }

    return 0;
}


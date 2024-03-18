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
    int board[SIZE][SIZE] = {{1, 3, 6}, {8, 0, 5}, {2, 4, 7}};

    while (true) {
        system("cls");
        printBoard(board);

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

        cout << "Chon o so di chuyen: ";
        if (check(EmptyRowLeft, EmptyColLeft)) cout << board[EmptyRowLeft][EmptyColLeft] << " ";
        if (check(EmptyRowRight, EmptyColRight)) cout << board[EmptyRowRight][EmptyColRight] << " ";
        if (check(EmptyRowTop, EmptyColTop)) cout << board[EmptyRowTop][EmptyColTop] << " ";
        if (check(EmptyRowBottom, EmptyColBottom)) cout << board[EmptyRowBottom][EmptyColBottom] << " ";
        cout << endl << "Chon o so: ";

        int n;
        cin >> n;

        if (n == board[EmptyRowLeft][EmptyColLeft]) Move(board, emptyRow, emptyCol, EmptyRowLeft, EmptyColLeft);
        else if (n == board[EmptyRowRight][EmptyColRight]) Move(board, emptyRow, emptyCol, EmptyRowRight, EmptyColRight);
        else if (n == board[EmptyRowTop][EmptyColTop]) Move(board, emptyRow, emptyCol, EmptyRowTop, EmptyColTop);
        else if (n == board[EmptyRowBottom][EmptyColBottom]) Move(board, emptyRow, emptyCol, EmptyRowBottom, EmptyColBottom);

        cout << "Nhan W (len), S (xuong), A (trai), D (phai), Q (thoat): ";
        char move = getch();

        switch (move) {
            case 'W':
            case 'w':
                if (check(emptyRow - 1, emptyCol))
                    Move(board, emptyRow, emptyCol, emptyRow - 1, emptyCol);
                break;
            case 'S':
            case 's':
                if (check(emptyRow + 1, emptyCol))
                    Move(board, emptyRow, emptyCol, emptyRow + 1, emptyCol);
                break;
            case 'A':
            case 'a':
                if (check(emptyRow, emptyCol - 1))
                    Move(board, emptyRow, emptyCol, emptyRow, emptyCol - 1);
                break;
            case 'D':
            case 'd':
                if (check(emptyRow, emptyCol + 1))
                    Move(board, emptyRow, emptyCol, emptyRow, emptyCol + 1);
                break;
            case 'Q':
            case 'q':
                cout << "Thoat chuong trinh." << endl;
                return 0;
            default:
                cout << "Phim khong hop le. Nhan Enter de nhap lai." << endl;
                getch();
        }
    }

    return 0;
}


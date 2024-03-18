#include <iostream>
#include <conio.h>

const int SIZE = 3; // K�ch thu?c c?a b?ng vu�ng (3x3)

// H�m in ra b?ng vu�ng
void printBoard(int board[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                std::cout << "   "; // In kho?ng tr?ng cho � tr?ng
            } else {
                std::cout << board[i][j] << "  ";
            }
        }
        std::cout << std::endl;
    }
}

// H�m ki?m tra xem tr� choi d� ho�n th�nh hay chua
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

// H�m d?i ch? hai � tr�n b?ng
void swapTiles(int& tile1, int& tile2) {
    int temp = tile1;
    tile1 = tile2;
    tile2 = temp;
}

int main() {
    int board[SIZE][SIZE] = {{1, 3, 6}, {8, 5, 0}, {2, 4, 7}}; // Tr?ng th�i kh?i d?u

    while (true) {
        system("cls"); // X�a m�n h�nh console
        printBoard(board);

        if (isGameComplete(board)) {
            std::cout << "Chuc mung! Ban da hoan thanh tro choi." << std::endl;
            break;
        }

        std::cout << "Nhan W (len), S (xuong), A (trai), D (phai), Q (thoat): ";
        char move = getch(); // �?c m?t ph�m t? b�n ph�m m� kh�ng c?n nh?n Enter

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

        switch (move) {
            case 'W':
            case 'w':
                if (emptyRow > 0) {
                    swapTiles(board[emptyRow][emptyCol], board[emptyRow - 1][emptyCol]);
                }
                break;
            case 'S':
            case 's':
                if (emptyRow < SIZE - 1) {
                    swapTiles(board[emptyRow][emptyCol], board[emptyRow + 1][emptyCol]);
                }
                break;
            case 'A':
            case 'a':
                if (emptyCol > 0) {
                    swapTiles(board[emptyRow][emptyCol], board[emptyRow][emptyCol - 1]);
                }
                break;
            case 'D':
            case 'd':
                if (emptyCol < SIZE - 1) {
                    swapTiles(board[emptyRow][emptyCol], board[emptyRow][emptyCol + 1]);
                }
                break;
            case 'Q':
            case 'q':
                std::cout << "Thoat chuong trinh." << std::endl;
                return 0;
            default:
                std::cout << "Phim khong hop le. Nhan Enter de nhap lai." << std::endl;
                getch(); // Ch? ngu?i choi nh?n Enter d? ti?p t?c
                
        }
    }

    return 0;
}


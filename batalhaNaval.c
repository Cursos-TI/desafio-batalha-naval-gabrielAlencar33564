#include <stdio.h>

// funcao que imprime o tabuleiro
void printBoard(int board[10][10])
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// funcao que coloca um navio na vertical
void shipVertical(int board[10][10], int startRow, int startCol, int size)
{
  for (int i = 0; i < size; i++)
  {
    board[startRow + i][startCol] = 3;
  }
}

// funcao que coloca um navio na horizontal
void shipHorizontal(int board[10][10], int startRow, int startCol, int size)
{
  for (int i = 0; i < size; i++)
  {
    board[startRow][startCol + i] = 3;
  }
}

int main()
{
  int board[10][10] = {0};

  shipVertical(board, 2, 3, 3);
  shipHorizontal(board, 5, 5, 3);

  printBoard(board);
}
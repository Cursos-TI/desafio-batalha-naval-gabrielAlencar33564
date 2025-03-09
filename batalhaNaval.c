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
  if (startRow + size > 9 || startCol > 9)
  {
    printf("Posicao invalida\n");
    return;
  }

  for (int i = 0; i < size; i++)
  {
    int row = startRow + i;

    if (board[row][startCol] != 0)
    {
      printf("Sobreposicao de navios\n");
      break;
    }

    board[row][startCol] = 3;
  }
}

// funcao que coloca um navio na horizontal
void shipHorizontal(int board[10][10], int startRow, int startCol, int size)
{
  if (startCol + size > 9 || startRow > 9)
  {
    printf("Posicao invalida\n");
    return;
  }

  for (int i = 0; i < size; i++)
  {
    int col = startCol + i;

    if (board[startRow][col] != 0)
    {
      printf("Sobreposicao de navios\n");
      break;
    }

    board[startRow][col] = 3;
  }
}

// funcao que coloca um navio na diagonal (direcao 0: diagonal esquerda, direcao 1: diagonal direita)
void shipDiagonal(int board[10][10], int startRow, int startCol, int size, int direction)
{
  if (startRow > 9 || startCol > 9)
  {
    printf("Posicao invalida\n");
    return;
  }

  for (int i = 0; i < size; i++)
  {
    int row = startRow + i;
    int col = direction == 0 ? startCol + i : startCol - i;

    if (board[row][col] != 0)
    {
      printf("Sobreposicao de navios\n");
      break;
    }

    board[row][col] = 3;
  }
}

int main()
{
  int board[10][10] = {0};

  shipVertical(board, 2, 3, 3);
  shipHorizontal(board, 5, 5, 3);
  shipDiagonal(board, 6, 3, 3, 0);
  shipDiagonal(board, 0, 9, 3, 1);

  printBoard(board);
}
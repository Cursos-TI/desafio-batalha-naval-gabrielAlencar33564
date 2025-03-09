#include <stdio.h>

// tamanho do tabuleiro e das habilidades
#define BOARD_SIZE 10
#define ABILITY_SIZE 5

// funcao que imprime o tabuleiro
void printBoard(int board[BOARD_SIZE][BOARD_SIZE])
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// funcao que coloca um navio na vertical
void shipVertical(
    int board[BOARD_SIZE][BOARD_SIZE],
    int startRow, int startCol, int size)
{
  if (startRow + size > BOARD_SIZE || startCol > BOARD_SIZE)
  {
    printf("Posicao vertical invalida\n");
    return;
  }

  // verifica se ha sobreposicao de navios
  for (int i = 0; i < size; i++)
  {
    if (board[startRow + i][startCol] != 0)
    {
      printf("Sobreposicao de navios\n");
      return;
    }
  }

  // coloca o navio no tabuleiro
  for (int i = 0; i < size; i++)
  {
    board[startRow + i][startCol] = 3;
  }
}

// funcao que coloca um navio na horizontal
void shipHorizontal(
    int board[BOARD_SIZE][BOARD_SIZE],
    int startRow, int startCol, int size)
{
  if (startCol + size > BOARD_SIZE || startRow > BOARD_SIZE)
  {
    printf("Posicao horizontal invalida\n");
    return;
  }

  // verifica se ha sobreposicao de navios
  for (int i = 0; i < size; i++)
  {
    if (board[startRow][startCol + i] != 0)
    {
      printf("Sobreposicao de navios\n");
      return;
    }
  }

  // coloca o navio no tabuleiro
  for (int i = 0; i < size; i++)
  {
    board[startRow][startCol + i] = 3;
  }
}

// funcao que coloca um navio na diagonal (direcao 0: diagonal esquerda, direcao 1: diagonal direita)
void shipDiagonal(
    int board[BOARD_SIZE][BOARD_SIZE],
    int startRow, int startCol,
    int size, int direction)
{
  for (int i = 0; i < size; i++)
  {
    int row = startRow + i;
    int col = direction == 0 ? startCol + i : startCol - i;

    board[row][col] = 3;
  }
}

// funcao que coloca uma habilidade no tabuleiro
void placeAbility(
    int board[BOARD_SIZE][BOARD_SIZE],
    int row, int col,
    int ability[ABILITY_SIZE][ABILITY_SIZE])
{
  for (int i = 0; i < ABILITY_SIZE; i++)
  {
    for (int j = 0; j < ABILITY_SIZE; j++)
    {
      int targetRow = row + i - 2;
      int targetCol = col + j - 2;

      if (
          targetRow >= 0 && targetRow < BOARD_SIZE &&
          targetCol >= 0 && targetCol < BOARD_SIZE)
      {
        if (ability[i][j] != 0)
        {
          board[targetRow][targetCol] = 5;
        }
      }
    }
  }
}

int main()
{
  int board[BOARD_SIZE][BOARD_SIZE] = {0};

  // adicionando navios
  shipVertical(board, 2, 3, 3);
  shipHorizontal(board, 5, 5, 3);
  shipDiagonal(board, 6, 3, 3, 0);
  shipDiagonal(board, 0, 9, 3, 1);

  // adicionando habilidade de cone
  int cone[ABILITY_SIZE][ABILITY_SIZE] = {
      {0, 0, 1, 0, 0},
      {0, 1, 1, 1, 0},
      {0, 1, 1, 1, 0},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1}};
  placeAbility(board, 2, 2, cone);

  // adicionando habilidade de cruz
  int cross[ABILITY_SIZE][ABILITY_SIZE] = {
      {0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0},
      {1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0}};
  placeAbility(board, 7, 6, cross);

  // adicionando habilidade de octaedro
  int octahedron[ABILITY_SIZE][ABILITY_SIZE] = {
      {0, 0, 1, 0, 0},
      {0, 1, 1, 1, 0},
      {1, 1, 1, 1, 1},
      {0, 1, 1, 1, 0},
      {0, 0, 1, 0, 0}};
  placeAbility(board, 3, 7, octahedron);

  // desenhando o tabuleiro
  printBoard(board);
}
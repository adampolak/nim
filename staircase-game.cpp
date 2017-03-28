#include "staircase-game.h"

#include <stdlib.h>

Board Staircase::Start(int seed) {
  srand(seed);
  Board board(4 + rand() % 5);
  for (size_t i = 0; i < board.size(); ++i)
    board[i] = rand() % 5;
  if (board[0] == 0)
    board[0] = 1 + rand() % 4;
  return board;
}

bool Staircase::Finished(Board board) {
  for (size_t i = 0; i < board.size(); ++i)
    if (board[i] > 0)
      return false;
  return true;
}

std::string Staircase::Valid(Board before, Board after) {
  if (before.size() != after.size())
    return "Niewlasciwa liczba schodow";
  size_t index = before.size();
  for (size_t i = 0; i < before.size(); ++i)
    if (after[i] < before[i])
      index = i;
  if (index == before.size())
    return "Z zadnego schodu nie zabrano kamieni";
  for (size_t i = 0; i < before.size(); ++i)
    if (i + 1 != index && i != index && before[i] != after[i])
      return "Za duzo zmian";
  if (after[index] < 0)
    return "Ujemna liczba kamieni";
  if (index != 0 && after[index - 1] + after[index] != before[index - 1] + before[index])
    return "Zmiany kamieni na sasiednich schodach nie odpowiadaja sobie";
  return "";
}

#include "nim-game.h"

#include <stdlib.h>

Board Nim::Start(int seed) {
  srand(seed);
  Board board(3 + rand() % 3);
  for (size_t i = 0; i < board.size(); ++i)
    board[i] = 1 + rand() % 10;
  return board;
}

bool Nim::Finished(Board board) {
  for (size_t i = 0; i < board.size(); ++i)
    if (board[i] > 0)
      return false;
  return true;
}

std::string Nim::Valid(Board before, Board after) {
  if (before.size() != after.size())
    return"Niewlasciwa liczba stosow";
  size_t changes = 0;
  for (size_t i = 0; i < before.size(); ++i) {
    if (after[i] > before[i])
      return "Zwiekszono liczbe kamieni";
    if (after[i] < 0)
      return "Ujemna liczba kamieni";
    if (after[i] < before[i])
      ++changes;
  }
  if (changes == 0)
    return "Nic sie nie zmienilo";
  if (changes > 1)
    return "Zabrano z wiecej niz jednego stosu";
  return "";
}

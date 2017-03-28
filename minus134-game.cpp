#include "minus134-game.h"

#include <stdlib.h>

Board Minus134::Start(int seed) {
  srand(seed);
  Board board(3 + rand() % 3);
  for (size_t i = 0; i < board.size(); ++i)
    board[i] = 1 + rand() % 10;
  return board;
}

bool Minus134::Finished(Board board) {
  for (size_t i = 0; i < board.size(); ++i)
    if (board[i] > 0)
      return false;
  return true;
}

std::string Minus134::Valid(Board before, Board after) {
  if (before.size() != after.size())
    return"Niewlasciwa liczba stosow";
  size_t changes = 0;
  for (size_t i = 0; i < before.size(); ++i) {
    if (after[i] > before[i])
      return "Zwiekszono liczbe kamieni";
    if (after[i] < 0)
      return "Ujemna liczba kamieni";
    if (after[i] < before[i]) {
      int diff = before[i] - after[i];
      if (diff != 1 && diff != 3 && diff != 4)
        return "Roznica inna niz 1, 3 i 4";
      ++changes;
    }
  }
  if (changes == 0)
    return "Nic sie nie zmienilo";
  if (changes > 1)
    return "Zabrano z wiecej niz jednego stosu";
  return "";
}

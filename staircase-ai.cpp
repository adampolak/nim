#include "staircase-ai.h"

#include <stdlib.h>

Board StaircaseAi(Board board) {
  int x = 0, seed = 0;
  for (size_t i = 0; i < board.size(); i+=2) {
    x ^= board[i];
    seed += board[i];
  }
  if (x > 0) {
    for (size_t i = 0; i < board.size(); i+=2) {
      int diff = board[i] - (board[i] ^ x);
      if (diff > 0) {
        board[i] -= diff;
        if (i > 0)
          board[i - 1] += diff;
        break;
      }
    }
  } else {
    srand(seed);
    size_t i;
    do { i = rand() % board.size(); } while (board[i] == 0);
    int diff = 1 + rand() % board[i];
    board[i] -= diff;
    if (i > 0)
      board[i - 1] += diff;
  }
  return board;
}

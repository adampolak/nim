#include "nim-ai.h"

#include <stdlib.h>

Board NimAi(Board board) {
  int x = 0, seed = 0;
  for (size_t i = 0; i < board.size(); ++i) {
    x ^= board[i];
    seed += board[i];
  }
  if (x > 0) {
    for (size_t i = 0; i < board.size(); ++i)
      if ((board[i] ^ x) < board[i]) {
        board[i] ^= x;
        break;
      }
  } else {
    srand(seed);
    size_t i;
    do { i = rand() % board.size(); } while (board[i] == 0);
    board[i] = rand() % board[i];
  }
  return board;
}

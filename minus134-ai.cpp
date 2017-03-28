#include "minus134-ai.h"

#include <assert.h>
#include <stdlib.h>

const int nimber[] = {0, 1, 0, 1, 2, 3, 2};

Board Minus134Ai(Board board) {
  int x = 0, seed = 0;
  for (size_t i = 0; i < board.size(); ++i) {
    x ^= nimber[board[i] % 7];
    seed += board[i];
  }
  if (x > 0) {
    for (size_t i = 0; i < board.size(); ++i)
      if ((nimber[board[i] % 7] ^ x) < nimber[board[i] % 7]) {
        int target = nimber[board[i] % 7] ^ x;
        if (nimber[(board[i] - 1) % 7] == target)
          board[i] -= 1;
        else if (nimber[(board[i] - 3) % 7] == target)
          board[i] -= 3;
        else if (nimber[(board[i] - 4) % 7] == target)
          board[i] -= 4;
        else
          assert(false);
        break;
      }
  } else {
    srand(seed);
    size_t i;
    do { i = rand() % board.size(); } while (board[i] == 0);
    --board[i];
  }
  return board;
}

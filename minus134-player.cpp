#include "minus134-ai.h"

#include <iostream>

Board Minus134Player(Board board) {
  std::cout << "Podaj stan planszy po Twoim ruchu: ";
  for (size_t i = 0; i < board.size(); ++i)
    std::cin >> board[i];
  return board;
}

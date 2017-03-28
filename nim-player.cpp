#include "nim-ai.h"

#include <iostream>

Board NimPlayer(Board board) {
  std::cout << "Podaj stan planszy po Twoim ruchu: ";
  for (size_t i = 0; i < board.size(); ++i)
    std::cin >> board[i];
  return board;
}

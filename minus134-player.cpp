#include "minus134-ai.h"

#include <iostream>
#include <sstream>
#include <string>

Board Minus134Player(Board board) {
  std::cout << "Podaj stan planszy po Twoim ruchu: ";
  std::string buf;
  std::getline(std::cin, buf);
  std::istringstream in(buf);
  for (size_t i = 0; i < board.size(); ++i)
    in >> board[i];
  return board;
}

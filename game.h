#pragma once

#include <string>
#include <vector>

typedef std::vector<int> Board;

class Game {
 public:
  virtual ~Game() = 0;
  virtual Board Start(int seed) = 0;
  virtual bool Finished(Board board) = 0;
  virtual std::string Valid(Board before, Board after) = 0;
};

inline Game::~Game(){}

#pragma once

#include "game.h"

class Staircase : public Game {
 public:
  Staircase() {}
  virtual ~Staircase() {}
  virtual Board Start(int seed);
  virtual bool Finished(Board board);
  virtual std::string Valid(Board before, Board after);
};

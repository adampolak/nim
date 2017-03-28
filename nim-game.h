#pragma once

#include "game.h"

class Nim : public Game {
 public:
  Nim() {}
  virtual ~Nim() {}
  virtual Board Start(int seed);
  virtual bool Finished(Board board);
  virtual std::string Valid(Board before, Board after);
};

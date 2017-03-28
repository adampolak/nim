#pragma once

#include "game.h"

class Minus134 : public Game {
 public:
  Minus134() {}
  virtual ~Minus134() {}
  virtual Board Start(int seed);
  virtual bool Finished(Board board);
  virtual std::string Valid(Board before, Board after);
};

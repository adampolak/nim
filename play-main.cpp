#include <stdlib.h>

#include <iostream>

#include "game.h"

#include "nim-game.h"
#include "nim-ai.h"
#include "nim-player.h"

#include "staircase-game.h"
#include "staircase-ai.h"
#include "staircase-player.h"

#include "minus134-game.h"
#include "minus134-ai.h"
#include "minus134-player.h"

void Play(Game* game, Board(*alice)(Board), Board(*bob)(Board), int seed) {
  Board(*players[2])(Board) = {alice, bob};
  Board board = game->Start(seed);
  for (size_t turn = 0;; ++turn) {
    std::cout << "Plansza w oczekiwaniu na ruch gracza " << "AB"[turn & 1] << ':';
    for (size_t i = 0; i < board.size(); ++i)
      std::cout << ' ' << board[i];
    std::cout << std::endl;
    if (game->Finished(board)) {
      std::cout << "Koniec gry: Wygrywa gracz " << "AB"[1 ^ turn & 1] << std::endl;
      return;
    }
    const int MAX_TRIES = 10;
    size_t num_tries = 0;
    while (true) {
      Board after = players[turn & 1](board);
      std::string error = game->Valid(board, after);
      if (error.empty()) {
        board = after;
        std::cout << "Gracz " << "AB"[turn & 1] << " wykonal ruch" << std::endl;
        break;
      }
      std::cout << "Niepoprawny ruch: " << error << std::endl;
      ++num_tries;
      if (num_tries < MAX_TRIES) {
        std::cout << "Sprobuj jeszcze raz" << std::endl;
        continue;
      } else {
        std::cout << "Przekroczono limit niepoprawnych ruchow" << std::endl;
        std::cout << "Koniec gry: wygrywa gracz " << "AB"[1 ^ turn & 1] << std::endl;
        return;
      }
    }
  }
}

void Usage() {
  std::cerr << "usage: ./play {nim | staircase | minus134 } [seed]" << std::endl;
  exit(1);
}

int main(int argc, char *argv[]) {
  if (!(argc == 2 || argc == 3))
    Usage();
  std::string game = argv[1];
  int seed = (argc == 3) ? atoi(argv[2]) : 0;
  
  if (game == "nim")
    Play(new Nim, NimPlayer, NimAi, seed);
  else if (game == "staircase")
    Play(new Staircase, StaircasePlayer, StaircaseAi, seed);
  else if (game == "minus134")
    Play(new Minus134, Minus134Player, Minus134Ai, seed);
  else
    Usage();
}

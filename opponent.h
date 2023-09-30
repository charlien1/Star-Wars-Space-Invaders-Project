#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"

#ifndef OPPONENT_H
#define OPPONENT_H

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  OpponentProjectile(int x, int y) : GameElement(x, y, 3, 10) {}
  void Move(const graphics::Image &image) override;
  void Draw(graphics::Image &oProjectile) override;
};

class Opponent : public GameElement {
 public:
  Opponent() : Opponent(0, 0) {}
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}
  std::unique_ptr<OpponentProjectile> LaunchProjectile();
  void Move(const graphics::Image &image) override;
  void Draw(graphics::Image &player2) override;

 private:
  graphics::Image opponent;
  int counter = 0;
};

#endif

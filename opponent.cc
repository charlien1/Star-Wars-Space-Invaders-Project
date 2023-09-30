#include "opponent.h"
#include <vector>
#include "cpputils/graphics/image.h"
#include "game.h"
#include "game_element.h"

void Opponent::Draw(graphics::Image &image) {
  graphics::Color bgColor(255, 255, 255);
  opponent.Load("opponent.bmp");
  for (int i = 0; i < opponent.GetWidth(); i++) {
    for (int j = 0; j < opponent.GetHeight(); j++) {
      if (opponent.GetColor(i, j) != bgColor) {
        image.SetColor(GetX() + i, GetY() + j, opponent.GetColor(i, j));
      }
    }
  }
}

void OpponentProjectile::Draw(graphics::Image &image) {
  graphics::Image opponent_projectile(3, 10);
  opponent_projectile.Load("opponent_projectile.bmp");
  graphics::Color bgColor(255, 255, 255);
  for (int i = 0; i < opponent_projectile.GetWidth(); i++) {
    for (int j = 0; j < opponent_projectile.GetHeight(); j++) {
      if (opponent_projectile.GetColor(i, j) != bgColor) {
        image.SetColor(GetX() + i, GetY() + j,
                       opponent_projectile.GetColor(i, j));
      }
    }
  }
}

std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  if (counter == 10) {
    std::unique_ptr<OpponentProjectile> unique_oppProjectile =
        std::make_unique<OpponentProjectile>(Opponent::GetX(),
                                             Opponent::GetY());
    counter = 0;
    return unique_oppProjectile;
  } else {
    counter++;
    return nullptr;
  }
}

void Opponent::Move(const graphics::Image &image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() + 3);
    SetX(GetX() + 3);
  } else {
    SetIsActive(false);
  }
}

void OpponentProjectile::Move(const graphics::Image &image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
    SetX(GetX() - 3);
  } else {
    SetIsActive(false);
  }
}

#include "player.h"
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

void Player::Draw(graphics::Image& image) {
  graphics::Color bgColor(255, 255, 255);
  graphics::Image player_image(50, 50);
  player_image.Load("player.bmp");
  for (int i = 0; i < player_image.GetWidth(); i++) {
    for (int j = 0; j < player_image.GetHeight(); j++) {
      if (player_image.GetColor(i, j) != bgColor) {
        image.SetColor(GetX() + i, GetY() + j, player_image.GetColor(i, j));
      }
    }
  }
}

void PlayerProjectile::Draw(graphics::Image& image) {
  graphics::Image player_projectile(3, 10);
  graphics::Color bgColor(255, 255, 255);
  player_projectile.Load("player_projectile.bmp");
  for (int i = 0; i < player_projectile.GetWidth(); i++) {
    for (int j = 0; j < player_projectile.GetHeight(); j++) {
      if (player_projectile.GetColor(i, j) != bgColor) {
        image.SetColor(GetX() + i, GetY() + j,
                       player_projectile.GetColor(i, j));
      }
    }
  }
}

void Player::Move(const graphics::Image& image) {}

void PlayerProjectile::Move(const graphics::Image& image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
  } else {
    SetIsActive(false);
  }
}

#include <string>
#include "cpputils/graphics/image.h"

#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

class GameElement {
 public:
  GameElement() : x_(0), y_(0), kWidth_(50), kHeight_(50) {}
  GameElement(int x, int y, int kWidth, int kHeight)
      : x_(x), y_(y), kWidth_(kWidth), kHeight_(kHeight) {}
  virtual void Draw(graphics::Image& image) = 0;
  virtual void Move(const graphics::Image& image) = 0;
  bool IntersectsWith(GameElement* element);
  bool IsOutOfBounds(const graphics::Image& image);
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  void SetIsActive(bool isActive) { is_active = isActive; }
  bool GetIsActive() const { return is_active; }
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetWidth() const { return kWidth_; }
  int GetHeight() const { return kHeight_; }

 protected:
  bool is_active = true;
  int x_;
  int y_;
  int kWidth_;
  int kHeight_;
};

#endif

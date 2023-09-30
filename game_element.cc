#include "game_element.h"
#include "cpputils/graphics/image.h"

bool GameElement::IntersectsWith(GameElement* element) {
  return !(GetX() > element->GetX() + element->GetWidth() ||
           element->GetX() > GetX() + GetWidth() ||
           GetY() > element->GetY() + element->GetHeight() ||
           element->GetY() > GetY() + GetHeight());
}

bool GameElement::IsOutOfBounds(const graphics::Image& image) {
  if (GetX() + GetWidth() > image.GetWidth() ||
      GetY() + GetHeight() > image.GetHeight() || GetX() < 0 || GetY() < 0) {
    return true;
  } else {
    return false;
  }
}

#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "opponent.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 public:
  Game() : Game(800, 600) {}
  Game(int width, int height) { background_.Initialize(width, height); }
  graphics::Image& GetGameScreen() { return background_; }
  void LaunchProjectiles();
  void CreateOpponents();
  void Init();
  void UpdateScreen();
  void RemoveInactive();
  void Start();
  void MoveGameElements();
  void FilterIntersections();
  void OnAnimationStep() override;
  void OnMouseEvent(const graphics::MouseEvent& event) override;
  std::vector<std::unique_ptr<Opponent>>& GetOpponents() { return opponents_; }
  std::vector<std::unique_ptr<OpponentProjectile>>& GetOpponentProjectiles() {
    return opponent_projectiles_;
  }
  std::vector<std::unique_ptr<PlayerProjectile>>& GetPlayerProjectiles() {
    return player_projectiles_;
  }
  Player& GetPlayer() { return player; }
  int GetScore() const { return score_; }
  bool HasLost() { return lost_; }

 private:
  int score_ = 0;
  bool lost_ = false;
  graphics::Image background_;
  std::vector<std::unique_ptr<Opponent>> opponents_;
  std::vector<std::unique_ptr<OpponentProjectile>> opponent_projectiles_;
  std::vector<std::unique_ptr<PlayerProjectile>> player_projectiles_;
  Player player;
  Player playerUpgrade;
};

#endif

#include"../include/Game.hpp"

int main(int argc, char** argv) {
  Game game= Game::GetInstance();
//   getchar();
  game.Run();
  game.~Game();
}
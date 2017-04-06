#include "Action.h"

std::atomic<Action> game_action = Action::NONE;
std::atomic<EnemyAction> Enemy_action = EnemyAction::ENONE;
std::atomic<PowerUp> powerUp_ation = PowerUp::NONE;
std::atomic<GameState> game_state = GameState::MENUE;


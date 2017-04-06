
#pragma once
#include "GameData.h"
#include<atomic>

enum class GameState
{
	MENUE=0,
	WAITINGFORPLAYER,
	PLAY,
	GAMEOVER,
	VICTORY,
};
enum class Action
{
	NONE = 0,
	UP = 1,
	LEFT,
	RIGHT,
	DOWN,
	PICKEDUPITEM,
	CRASHED,
	STARTGAME,
	
};
enum class PowerUp
{
	NONE,
	BOOST,
	JUMP,
	SLOWMO,
};
enum class EnemyAction
{
	EINVALID = -1,
	ENONE = 0,
	EUP,
	ELEFT,
	ERIGHT,
	EDOWN,
};

extern std::atomic<GameState>game_state;
extern std::atomic<Action> game_action;
extern std::atomic<PowerUp> powerUp_ation;
extern std::atomic<EnemyAction> Enemy_action;


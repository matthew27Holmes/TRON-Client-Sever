#include <Game\GameData.h>
#include "Client.h"
#include <Game\Menue.h>
#include <Game\Enemy.h>
#include <Game\Player.h>
#include <Game\Collider.h>
#include <Game\playSpaceBoarders.h>
#include "InputManger.h"
#include <thread>
#include <SFML\Audio.hpp>



class Tron
{
public:
	Tron();
	~Tron();
	void runGame();
	void play();
	void Lobby();
	void input();
	void crash();
	void CheckgridCollisions();
	void cleanGrid();
	void draw();

private:
	sf::RenderWindow* window;
	sf::View* view;
	sf::Event event;
	sf::Music music;
	GameData* _GD;
	bool wascoliding;

	std::thread ClientMSG;
	std::thread ClientInput;

	Client* clientPt;
	Menue* menuept;
	InputManger inputMan;

	playSpaceBoarders playSpace;
	Collider* ColliderPt;

	vector <sf::RectangleShape> Grid;
	sf::RectangleShape JustTouched;
	sf::RectangleShape currentlyTouching;
	Enemy* EnemyPt;
	Player* playerPt;

	bool PreGameSetUp;
	bool makeOnethread;
	bool youWon;
	bool startGame;

	sf::Vector2f BikeSize;
	sf::Font font;
	sf::Text text;

	
	
};

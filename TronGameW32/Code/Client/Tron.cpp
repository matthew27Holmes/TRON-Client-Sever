#include "Tron.h"


Tron::Tron()
{
	window= new sf::RenderWindow(sf::VideoMode(650, 650), "TRON!!!!", sf::Style::Close | sf::Style::Resize);
	view=new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(650.0f, 650.0f));
	menuept = new Menue(window);

	BikeSize = sf::Vector2f(0.2f, 0.2f);
	playerPt = new Player(BikeSize, sf::Vector2f( 650 , 750));
	EnemyPt = new Enemy(BikeSize, sf::Vector2f(650, 650));
	

	_GD = new GameData();
	clientPt = new Client();

	int W;
	
	for (int H = 0; H < 22; H++)
	{
		for ( W= 0; W < 22; W++)
		{
			sf::RectangleShape Tile;
			Tile.setSize(sf::Vector2f(40.0f, 40.0f));
			Tile.setPosition(sf::Vector2f(W*(Tile.getSize().x),H*(Tile.getSize().y)));
			Tile.setOutlineThickness(1.0f);
			Tile.setOutlineColor(sf::Color::Blue.Cyan);
			Tile.setFillColor(sf::Color::Black);
			Grid.push_back(Tile);
		}
		W = 0;
	}
	
	font.loadFromFile("chintzys.ttf");
	text.setFont(font);

	text.setCharacterSize(24);
	text.setPosition(sf::Vector2f(650/2, 650/2));

	PreGameSetUp = true;
	makeOnethread = true;
	
	if (!music.openFromFile("TronMen.ogg"))
	{
		return; // error
	}
	music.play();
	music.setLoop(game_state != GameState::PLAY);
	
}


Tron::~Tron()
{}

void Tron::runGame()
{
	sf::Clock deltaClock;
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			}
		}
		
		switch (game_state)
		{
		case GameState::MENUE:
			
			
			menuept->runMenue();
			break;

		case GameState::PLAY:
			// set delta
			playerPt->setDT(_GD->DT);
			EnemyPt->setDT(_GD->DT);

			if (makeOnethread)
			{
				ClientMSG =  std::thread(&Client::reciveMSG, clientPt);
				ClientInput = std::thread(&Client::input, clientPt);
				makeOnethread = false;
			}
			
			if (clientPt->getStartGame()) //if two clients connected if not move to lobby 
			{	
				if (PreGameSetUp)
				{

					if (clientPt->getControler() == 1 || 0)	// clinet starting postion
					{
						EnemyPt->setPos(sf::Vector2f(100, (view->getSize().y + 10) / 2));
						EnemyPt->getBody().setColor(sf::Color::Yellow);
						playerPt->setPos(sf::Vector2f(view->getSize().x - 130, EnemyPt->getBody().getPosition().y));
						playerPt->getBody().setColor(sf::Color::Blue);
						game_action = Action::LEFT;
						Enemy_action = EnemyAction::ERIGHT;
						
					}
					else
					{
						playerPt->setPos(sf::Vector2f(100, (view->getSize().y + 10) / 2));
						playerPt->getBody().setColor(sf::Color::Blue);
						EnemyPt->setPos(sf::Vector2f(view->getSize().x - 130, playerPt->getBody().getPosition().y));
						EnemyPt->getBody().setColor(sf::Color::Yellow);
						Enemy_action = EnemyAction::ELEFT;
						game_action = Action::RIGHT;
						
						//EnemyPt->SetDirection(2);
					}

					inputMan.setSchema(clientPt->getControler());	// control method used for each client
					inputMan.setKeyboardCommands();	//if not joysticks set up keys for keyboard

					if (!music.openFromFile("TronPlay.ogg"))
					{
						return; // error
					}
					music.play();
					music.setLoop(game_state == GameState::PLAY);

					PreGameSetUp = false;
				}
			play();
			}
			else
			{
				game_state = GameState::WAITINGFORPLAYER;
			}
			break;
		case GameState::WAITINGFORPLAYER:
			Lobby();
			break;

		case GameState::GAMEOVER:
			//cleanGrid();
			if (youWon)
			{
				text.setString("You Won");
			}
			else
			{
				text.setString("You Lost");
			}
			menuept->EndGameMenue();
			break;
		}
		draw();
		_GD->DT = deltaClock.getElapsedTime().asSeconds();
		deltaClock.restart();
	}
}

void Tron::Lobby()
{
	text.setString("Entering Grid...");
	if (clientPt->getStartGame())
	{
		game_state = GameState::PLAY;
	}

}

void Tron::play()
{
	if (clientPt->getOtherPlayerCrashed())
	{
		youWon = true;
		game_state = GameState::GAMEOVER;
	}
	

	input();
	EnemyPt->SetDirection(clientPt->getEnemyDirection());

	if (playerPt->getAlive())
	{
		playerPt->movePlayer();
	}
	EnemyPt->moveEnemy();

	if (ColliderPt->checkCollision(playerPt->getBody(), EnemyPt->getBody()))
	{
		crash();
	}
	
	CheckgridCollisions();

	if (playSpace.isInPlaySpace(playerPt->getBody(), view->getSize()))// player hit wall
	{
		crash();
	}
}

void Tron::input()
{
	switch (inputMan.getSchema())
	{
		case 2:
		{
			inputMan.JotystickInp();
			break;
		}
		default:
			inputMan.KeyboardInp(event);
			break;
	}	
}

void Tron::crash()
{
	playerPt->setAlive(false);//kill player
	youWon = false;
	game_action = Action::CRASHED;
	game_state = GameState::GAMEOVER;//change to gameover state;
}

void Tron::CheckgridCollisions()
{
	for (auto& Tile : Grid)
	{
		//creating enemy trail
		if (ColliderPt->CheckGridCollisions(Tile, EnemyPt->getBody()))
		{
			//broken touching two at the same time 
			if (Tile.getFillColor() == sf::Color::Black)
			{
				Tile.setFillColor(sf::Color::Yellow);
			}
		}


		if (ColliderPt->CheckGridCollisions(Tile, playerPt->getBody())) //creating player trail and checking trail coillisons
		{
			//broken touching two at the same time 
			if (Tile.getFillColor() == sf::Color::Black)
			{
				if (Tile.getPosition() != currentlyTouching.getPosition())
				{
					JustTouched.setPosition(currentlyTouching.getPosition());
				}
				Tile.setFillColor(sf::Color::Blue);
				currentlyTouching.setPosition(Tile.getPosition()); 
			}
			else if (Tile.getFillColor() == sf::Color::Yellow)///*Tile.getPosition() != JustTouched.getPosition()*/)			
			{
				crash();
			}
			/*else if (Tile.getFillColor() == sf::Color::Blue)
			{
				if (Tile.getPosition() != JustTouched.getPosition())
				{
					if (Tile.getPosition() != currentlyTouching.getPosition())
					{
						crash();
					}
				}
			}*/
		}
	}
}

void Tron::cleanGrid()
{
	for (auto& Tile : Grid)
	{
		if (Tile.getFillColor() != sf::Color::Black)
		{
			Tile.setFillColor(sf::Color::Black);
		}
	}
}

void Tron::draw()
{
	for (auto& Tile : Grid)
	{
		window->draw(Tile);
	}

	switch (game_state)
	{
	case GameState::MENUE:
		menuept->drawButtons();
		break;

	case GameState::WAITINGFORPLAYER:
		window->draw(text);     // bug is cleared each tick and re drawn could fix but i think it fits the theme dont you james 
		break;

	case GameState::PLAY:
	
		EnemyPt->draw(window);
		if (playerPt->getAlive())
		{
			playerPt->draw(window);
		}
		break;
	case GameState::GAMEOVER:
		window->draw(text);
		menuept->drawButtons();
		break;
	}
		window->display();
		view->setCenter(sf::Vector2f((650 / 2), (650 / 2)));
		window->clear();
		window->setView(*view);
}



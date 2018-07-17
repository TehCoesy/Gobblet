#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>

#include "MessageBoard.h"

struct Block {
	void setBlock(int in1, int in2) {
		color = in1; size = in2;
	}
	int color = 0;
	int size = 0;
};

class Game {
public:
	Game();
	void newGame();

	void update();
	void drawGame(sf::RenderWindow& window);

	void onMouseClick(int x, int y);
private:
	void drawGrid(sf::RenderWindow& window);
	void drawPlayerStacks(sf::RenderWindow& window);
	void drawInfo(sf::RenderWindow& window);
	void drawClock(sf::RenderWindow& window);

	void checkGame();
	

	std::vector<Block> gameState;
	bool playerTurn = true;
	int stackOption = 0;
	int boardOption = -1;
	int whiteStack[3] = { 1,2,3 };
	int blackStack[3] = { 4,3,2 };

	//Mouse Click
	std::string currentAction = "";
	bool zwischen(int i, int x1, int x2);
	bool boundary(int x, int y, int p1, int p2, sf::Vector2f size);
	void onBoardClick(int place);

	//Game
	void nextTurn();
	bool placeGobb(int place);
	void deletGobb(int place);

	//Miscellanous
	sf::Clock gameTimer;
	sf::Texture blackKingT;
	sf::Texture whiteKingT;
	sf::Sprite	blackKing;
	sf::Sprite whiteKing;
};

#endif // !GAME_H


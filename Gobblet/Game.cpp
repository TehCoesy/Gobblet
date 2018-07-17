#include "Game.h"

Game::Game() {
	if (!blackKingT.loadFromFile("Resources/Texture/blackPlayer.png")) {
		throw "Cannot load blackPlayer.png";
	}
	if (!whiteKingT.loadFromFile("Resources/Texture/whitePlayer.png")) {
		throw "Cannot load whitePlayer.png";
	}
	blackKing.setTexture(blackKingT);
	whiteKing.setTexture(whiteKingT);
	blackKing.setPosition(sf::Vector2f(70,10));
	blackKing.setScale(sf::Vector2f(0.6, 0.6));
	whiteKing.setPosition(sf::Vector2f(500,10));
	whiteKing.setScale(sf::Vector2f(0.6, 0.6));
}
void Game::newGame() {
	for (int i = 0; i < 16; i++) {
		Block block;
		block.setBlock(0, 0);
		gameState.push_back(block);
	}
	gameTimer.restart();
}

void Game::drawGame(sf::RenderWindow& window) {
	drawGrid(window);
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			if (gameState[i * 4 + k].color != 0 && gameState[i * 4 + k].size != 0) {
				sf::CircleShape gobb;
				if (gameState[i * 4 + k].color == 1) {
					gobb.setFillColor(sf::Color::Black);
				}
				else if (gameState[i * 4 + k].color == 2) {
					gobb.setFillColor(sf::Color::White);
				}
				switch (gameState[i * 4 + k].size) {
				case 4:	gobb.setRadius(27);	break;
				case 3: gobb.setRadius(24);	break;
				case 2:	gobb.setRadius(21);	break;
				case 1: gobb.setRadius(18);	break;
				}
				if (boardOption != -1 && boardOption == i * 4 + k) {
					gobb.setOutlineThickness(4);
					gobb.setOutlineColor(sf::Color::Yellow);
				}
				gobb.setPosition(sf::Vector2f(177 + 72 * i - (gameState[i * 4 + k].size - 4) * 3, 177 + 72 * k - (gameState[i * 4 + k].size - 4) * 3));
				window.draw(gobb);
			}
		}
	}
	drawPlayerStacks(window);
	drawInfo(window);
}

void Game::drawGrid(sf::RenderWindow& window) {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			sf::RectangleShape block;
			block.setSize(sf::Vector2f(66, 66));
			block.setPosition(sf::Vector2f(171 + 72 * k, 171 + 72 * i));
			block.setFillColor(sf::Color::Transparent);
			block.setOutlineThickness(6);
			block.setOutlineColor(sf::Color::Black);
			window.draw(block);
		}
	}
}

void Game::drawPlayerStacks(sf::RenderWindow& window) {
	//Black Player
	for (int i = 0; i < 3; i++) {
		sf::CircleShape blackGobb;
		blackGobb.setFillColor(sf::Color::Black);
		switch (blackStack[i]) {
		case 4:	blackGobb.setRadius(27);	break;
		case 3: blackGobb.setRadius(24);	break;
		case 2:	blackGobb.setRadius(21);	break;
		case 1: blackGobb.setRadius(18);	break;
		}
		blackGobb.setPosition(sf::Vector2f(77 - (blackStack[i] - 4) * 3, 177 - (blackStack[i] - 4) * 3 + 72 * i));
		window.draw(blackGobb);
	}
	//White Player
	for (int i = 0; i < 3; i++) {
		sf::CircleShape whiteGobb;
		whiteGobb.setFillColor(sf::Color::White);
		switch (whiteStack[i]) {
		case 4:	whiteGobb.setRadius(27);	break;
		case 3: whiteGobb.setRadius(24);	break;
		case 2:	whiteGobb.setRadius(21);	break;
		case 1: whiteGobb.setRadius(18);	break;
		}
		whiteGobb.setPosition(sf::Vector2f(493 - (whiteStack[i] - 4) * 3, 249 - (whiteStack[i] - 4) * 3 + 72 * i));
		window.draw(whiteGobb);
	}
}

void Game::drawInfo(sf::RenderWindow& window) {
	window.draw(blackKing);
	window.draw(whiteKing);

	sf::RectangleShape textBox;
	textBox.setSize(sf::Vector2f(585, 100));
	textBox.setPosition(sf::Vector2f(20,500));
	textBox.setFillColor(sf::Color::Color(0,0,0,100));
	window.draw(textBox);

	if (playerTurn && stackOption != 0) {
		sf::RectangleShape box;
		box.setSize(sf::Vector2f(66, 66));
		box.setFillColor(sf::Color::Transparent);
		box.setOutlineThickness(5);
		box.setOutlineColor(sf::Color::Yellow);
		box.setPosition(sf::Vector2f(71, 171 + 72 * (stackOption - 1)));
		window.draw(box);
	}
	else if (!playerTurn && stackOption != 0) {
		sf::RectangleShape box;
		box.setSize(sf::Vector2f(66, 66));
		box.setFillColor(sf::Color::Transparent);
		box.setOutlineThickness(5);
		box.setOutlineColor(sf::Color::Yellow);
		box.setPosition(sf::Vector2f(487, 243 + 72 * (stackOption - 1)));
		window.draw(box);
	}
}

bool Game::zwischen(int i, int x1, int x2) {
	if (i >= x1 && i <= x2) {
		return true;
	}
	else {
		return false;
	}
}

bool Game::boundary(int x, int y, int p1, int p2, sf::Vector2f size) {
	if (zwischen(x, p1, p1 + size.x) && zwischen(y, p2, p2 + size.y)) {
		return true;
	}
	else {
		return false;
	}
}

void Game::drawClock(sf::RenderWindow& window) {

}

void Game::onMouseClick(int x, int y) {
	if (zwischen(x, 71, 137) && zwischen(y, 171, 387)) {
		if (zwischen(y, 171, 243)) {
			if (playerTurn) stackOption = 1;
		}
		else if (zwischen(y, 243, 315)) {
			if (playerTurn) stackOption = 2;
		} else {
			if (playerTurn) stackOption = 3;
		}
	}
	else if (zwischen(x, 487, 553) && zwischen(y, 243, 459)) {
		if (zwischen(y, 243, 315)) {
			if (!playerTurn) stackOption = 1;
		}
		else if (zwischen(y, 315, 387)) {
			if (!playerTurn) stackOption = 2;
		}
		else {
			if (!playerTurn) stackOption = 3;
		}
	}
	else if (zwischen(x, 171, 459) && zwischen(y, 171, 459)) {
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 4; k++) {
				if (boundary(x, y, 171 + 72 * i, 171 + 72 * k, sf::Vector2f(66, 66))) {
					onBoardClick(i * 4 + k);
					return;
				}
			}
		}
	}
	else {
		stackOption = 0;
		boardOption = -1;
	}
	std::cout << " " << boardOption;
}

void Game::onBoardClick(int place) {
	if (boardOption == -1 && stackOption != 0) {

	}
}

void Game::update() {

}

bool Game::placeGobb(int place) {
	if (playerTurn && stackOption != 0) {
		if (gameState[place].color == 0) {
			gameState[place].setBlock(1, blackStack[stackOption - 1]);
			return true;
		}
		else {
			return false;
		}
		
	}
	else if (!playerTurn && stackOption != 0) {
		if (gameState[place].color == 0) {
			gameState[place].setBlock(2, whiteStack[stackOption - 1]);
			return true;
		}
		else {
			return false;
		}
	}
}

void Game::deletGobb(int place) {
	gameState[place].color = 0;
	gameState[place].size = 0;
}

void Game::nextTurn() {
	playerTurn = !playerTurn;
}
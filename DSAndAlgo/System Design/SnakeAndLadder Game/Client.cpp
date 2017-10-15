#include<iostream>
#include<string>
#include"Game.cpp"
using namespace std;


int main()
{
	//get the game instance 
	Game game ;

	Die d;
	game.addPlayer("Player 1");
	game.addPlayer("Player 2");
	game.initialize();
	game.play(d);


	//get player instance


	return 0;
}

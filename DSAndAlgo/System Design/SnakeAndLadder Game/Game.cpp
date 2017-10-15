#include<vector>
#include<list>

using namespace std;

class Game;
class Player;


class ISquare{

protected:
	list<Player* > players;
	int pos;
	Game* game;
public:
	ISquare(Game* g, int p)
	{
		game = g;
		pos = p;
	}

	virtual	ISquare* moveAndLand(int moves)
	{
		return game->findSquare(pos, moves)->snakeOrLadder();
	}
	virtual ISquare* snakeOrLadder()
	{
		return this;
	}

	virtual int position()
	{
		return pos;
	};

	virtual void enter(Player* p)
	{

		players.push_back(p);
	}

	virtual void leave(Player* p)
	{
		players.remove(p);
	}

	virtual bool isOccupied()
	{
		return players.size() != 0;
	}

	bool isFirstSquare()
	{
		return false;
	}

	bool isLastSquare()
	{
		return false;
	}
	
	virtual ~ISquare() =0
	{
		game = nullptr;
		pos = -1;
		players.clear();
	}

};

class Player
{

	string name;
	ISquare * square;
public:
	Player(string str)
	{
		name = str;
	}
	void moveForward(int moves)
	{
		square->leave(this);
		square = square->moveAndLand(moves);
		square->enter(this);
		
	}

	bool wins()
	{
		return square->isLastSquare()  ;
	}

	void joinGame(Game* game)
	{
		square = game->getFirstSquare();
		square->enter(this);
		
	}

};

class NormalSquare : public ISquare
{
public:
	NormalSquare(Game* g, int p) : ISquare(g, p) {}

};
class FirstSquare :public ISquare
{

public:
	FirstSquare(Game* g, int p) : ISquare(g, p) {}
	bool isFirstSquare()
	{
		return true;
	}


};

class LastSquare :public ISquare
{
	

public:
	LastSquare(Game* g, int p) : ISquare(g, p) {}
	bool isLastSquare()
	{
		return true;
	}

};

class Snake : public ISquare
{
	int demote;
public:
	Snake( Game* g, int p, int d):ISquare(g,p)
	{
		demote = d;
	}


	ISquare* snakeOrLadder()
	{
		return game->findSquare(pos, -demote);
	}

};


class Ladder : public ISquare
{
	int promote;
public:
	Ladder(Game* g, int p, int d) :ISquare(g, p)
	{
		promote = d;
	}


	ISquare* snakeOrLadder()
	{
		return game->findSquare(pos, promote);
	}

};

class Die
{
	int MAX;
	int MIN;
	int rnd(int min, int max)
	{
		int roll = min + ((max - min)* rand() % (max));
		return roll;
	}
public:
	Die()
	{
		MAX = 6;
		MIN = 1;
	}

	Die(int min,int max)
	{
		MAX = max;
		MIN = min;
	}

	
public:
	int roll()
	{
		return rnd(MIN, MAX);
	}
};

class Game
{
	list<Player*> players;
	vector<ISquare*> squares;
	Player* winner;
	int size;
	
	bool notOver()
	{

		return winner == nullptr;
	}


	void movePlayer(int moves)
	{
		Player* p = players.front();
		players.pop_front();
		p->moveForward(moves);
		players.push_back(p);
		if (p->wins())
			winner = p;
	}

	ISquare* getSquare(int pos)
	{
		//if is valid
		return squares[pos];
	}

	void createSquare()
	{

		//for now 100 squares
		int pos = 0;
		squares.push_back(new FirstSquare(this, pos));
		pos++;
		squares.push_back(new NormalSquare(this, pos));
		pos++;

		ISquare* square;
		for (pos; pos < size-1; pos++)
		{
			if (pos < 10)
			{
				square = new NormalSquare(this, pos);
				squares.push_back(square);
				continue;
			}
			//create rand sqaures
			int squ = rand() % 3;
			switch (squ)
			{
			case 0:
				square = new NormalSquare(this, pos);
				break;
			case 1:
			{
				int rolback = 1 + rand() % pos;
				if (rolback == pos)
					rolback -= (rand() % (pos - 1));
				square = new Snake(this, pos, rolback);
			}
				break;

			case 2:
			{	int promote = 1 + rand() % (size - 2);
			square = new Ladder(this, pos, promote);
			}
				break;

			
			}

			squares.push_back(square);

		}
		squares.push_back(new LastSquare(this, pos));

	
	}

public:
	Game()
	{
	
		size = 100;
	}

	void addPlayer(string name)
	{
		players.emplace_back(name);

	}

	bool initialize()
	{
		//Two player game, for now
		if (players.size() != 2)
		{
			return false;
		}

		for (auto p : players)
		{
			p->joinGame(this);
		}
		
		createSquare();
	}
	void play(Die& die)
	{

		
		while (notOver())
		{

			int roll = die.roll();
			movePlayer(roll);
		}
	}

	ISquare* getFirstSquare()
	{
		return squares[1];
	}


		ISquare* findSquare(int pos, int moves)
	{
		int newPos = pos + moves;
		//next pos is not valid, stay on same pos
		if (newPos > size || newPos < 0)
			return squares[pos];
		//valid newPos, return new sqaure
		return squares[newPos];

	}
		~Game()
		{
			for (auto p : players)
			{
				delete p;
			}

			for (auto s : squares)
				delete s;

			squares.clear();
			players.clear();
		}
};
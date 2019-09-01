#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define P  pair<int,int>    
#define V vector<vector<P>>

bool isVisited(const V& board, const P& pos)
{
	return board[pos.first][pos.second].first !=-1&& board[pos.first][pos.second].second!= -1;
}

void setParent( V& board, const P& pos , const P& parent)
{
	board[pos.first][pos.second].first = parent.first;
	board[pos.first][pos.second].second = parent.second;
}

//void unVisit(V& board, const P& pos)
//{
//	board[pos.first][pos.second] = 0;
//}
bool isValid( const P & pos, const V& board )
{

	if (pos.first <0 || pos.second >= board.size()  || pos.second <0 || pos.first >= board.size() || isVisited(board, pos))
		return false;
	return true;
}

bool isEndPath(const P& pos, const P& end)
{
	return pos.first == end.first && pos.second == end.second;

}

P nextPath(const P& cur, string direction) 
{
	P nextPath(cur);
	if (direction == "UL")
	{
		nextPath.second -= 1;
		nextPath.first -= 2;
	}
	else if (direction == "UR")
	{
		nextPath.second += 1;
		nextPath.first -= 2;

	}
	else if (direction == "R")
	{
		nextPath.second += 2;
		
	}
	else if (direction == "LR")
	{
		nextPath.second += 1;
		nextPath.first += 2;

	}
	else if (direction == "LL")
	{
		nextPath.second -= 1;
		nextPath.first += 2;

	}
	else if (direction == "L")
	{
		nextPath.second -= 2;
		
	}
	return nextPath;
}

bool BFS(const P& start, const P& endPos, V& board)
{

	string path;
	queue<P> que;
	que.push(start);

	P parent;
	parent.first = -1, parent.second = -1;
	setParent(board, start, parent);
	while (!que.empty())
	{
		P cur= que.front(),nxtPath;
		
		que.pop();
		if (isEndPath(cur, endPos))
			return true;
		
		//UL
		nxtPath = nextPath(cur, "UL");
		if (isValid(nxtPath, board))
		{
			que.push(nxtPath);
			setParent(board, nxtPath, cur);
		}

		//UR
		nxtPath = nextPath(cur, "UR");
		if (isValid(nxtPath, board))
		{
			que.push(nxtPath);
			setParent(board, nxtPath, cur);
		}

		//UL
		nxtPath = nextPath(cur, "R");
		if (isValid(nxtPath, board))
		{
			que.push(nxtPath);
			setParent(board, nxtPath, cur);
		}

		//UL
		nxtPath = nextPath(cur, "LR");
		if (isValid(nxtPath, board))
		{
			que.push(nxtPath);
			setParent(board, nxtPath, cur);
		}

		//LL
		nxtPath = nextPath(cur, "LL");
		if (isValid(nxtPath, board))
		{
			que.push(nxtPath);
			setParent(board, nxtPath, cur);
		}
		//L
		nxtPath = nextPath(cur, "L");
		if (isValid(nxtPath, board))
		{
			que.push(nxtPath);
			setParent(board, nxtPath, cur);
		}

		

	}
	return false;;


}


//void BSF(const P& parent, const P& cur, const P& endPos, vector<vector<int>>& board, string& path, bool & isFound, string & shortestPath)
//{
//
//
//	//check if visited
//	if (isVisited(board, cur))
//		return;
//	//visit this pos
//	visit(board, cur);
//
//	//found
//	if (isEndPath(cur, endPos))
//	{	
//		if (shortestPath.size() == 0)
//			shortestPath = path;
//		else if( path.size() < shortestPath.size())
//		{
//			shortestPath = path;
//			
//		}
//		isFound = true;
//		return;
//
//	}
//
//
//	//visit all its neighbours, in priority order
//	P nxtPos;
//	//1.) UL
//	nxtPos = nextPath(cur, "UL");
//	if (isValid(nxtPos,board) && nxtPos != parent)
//	{
//		path.push_back('U');
//		path.push_back('L');
//		path.push_back(' ');
//		BSF(cur, nxtPos, endPos, board, path,isFound,shortestPath);
//		path.pop_back();
//		path.pop_back();
//		path.pop_back();
//
//	}
//	//UR
//	nxtPos = nextPath(cur, "UR");
//	if (isValid(nxtPos, board) && nxtPos != parent)
//	{
//		path.push_back('U');
//		path.push_back('R');
//		path.push_back(' ');
//		BSF(cur, nxtPos, endPos, board, path,isFound, shortestPath);
//		path.pop_back();
//		path.pop_back();
//		path.pop_back();
//
//	}
//
//	//3. R
//	nxtPos = nextPath(cur, "R");
//	if (isValid(nxtPos, board) && nxtPos != parent)
//	{		
//		path.push_back('R');
//		path.push_back(' ');
//		BSF(cur, nxtPos, endPos, board, path, isFound, shortestPath);
//		path.pop_back();
//		path.pop_back();
//
//	}
//
//	//4 LR
//	nxtPos = nextPath(cur, "LR");
//	if (isValid(nxtPos, board) && nxtPos != parent)
//	{
//		path.push_back('L');
//		path.push_back('R');
//		path.push_back(' ');
//		BSF(cur, nxtPos, endPos, board, path, isFound, shortestPath);
//		path.pop_back();
//		path.pop_back();
//		path.pop_back();
//
//	}
//
//	//5 LL
//	nxtPos = nextPath(cur, "LL");
//	if (isValid(nxtPos, board) && nxtPos != parent)
//	{
//		path.push_back('L');
//		path.push_back('L');
//		path.push_back(' ');
//		BSF(cur, nxtPos, endPos, board, path, isFound, shortestPath);
//		path.pop_back();
//		path.pop_back();
//		path.pop_back();
//
//	}
//
//	//6 L
//	nxtPos = nextPath(cur, "L");
//	if (isValid(nxtPos, board) && nxtPos != parent)
//	{
//		path.push_back('L');		
//		path.push_back(' ');
//		BSF(cur, nxtPos, endPos, board, path, isFound, shortestPath);
//		
//		path.pop_back();
//		path.pop_back();
//
//	}
//
//
//	unVisit(board, cur);
//
//
//}

string nextPath(const P& cur, const P& nxt)
{
	int x = cur.first - nxt.first;
	int y = cur.second - nxt.second;

	if (x == 0 && y == -2)
		return "L";
	if (x == 0 && y == 2)
		return "R";
	if (x == -2 && y == -1)
		return "UL";
	if (x == -2 && y == 1)
		return "UR";
	if (x == 2 && y == 1)
		return "LR";
	if (x == 2 && y == -1)
		return "LL";
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N;
	cin >> N;
	
	V board(N, vector<pair<int,int>>(N));
	for (auto& vec : board)
	{
		for (auto& pr : vec)
		{
			pr.first = pr.second = -1;
		}
	}
	P startPos, endPos;
	cin >> startPos.first>>startPos.second;
	cin >> endPos.first >> endPos.second;

	string path, shortestPath;
	bool isFound = false;
	P parent;
	parent.first = parent.second = -1;

	/*BSF(parent, startPos, endPos, board, path, isFound, shortestPath);*/
	
	if (BFS(startPos, endPos, board))
	{		
		vector<string> path;
		//track the path
		P cord = board[endPos.first][endPos.second];
		P cur = endPos;
		while (cord != startPos)
		{
			path.push_back(nextPath(cur, cord));
			
			cur = cord;
			cord = board[cord.first][cord.second];

		}
		path.push_back(nextPath(cur, cord));
		
		
		reverse(path.begin(), path.end());
		for  (auto var : path)
		{
			cout << var;
			cout << " ";
		}
	}
	else
		cout << "IMPOSSIBLE";
	cout <<endl;



	return 0;
}

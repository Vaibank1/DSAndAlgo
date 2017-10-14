#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<array>
using namespace std;

bool isValid(int x, int y, int** visitedTrack, const string* word, char ch)
{
	if (x < 0 || y < 0)
		return false;
	if (x > 7 || y > 7)
		return false;
	if (visitedTrack[x][y])
		return false;
	if (word[x][y] != ch)
		return false;
	return true;
}

unsigned long long countPath(const string* chessBoard , const string& secretWord, int x , int y, string& wordTillNow, int countSoFar, int** visitedTrack)
{
	if (wordTillNow == secretWord)
		return 1;
	if (countSoFar >= secretWord.size())
		return 0;
	wordTillNow.push_back(secretWord[countSoFar]);
	if (wordTillNow == secretWord)
	{
		wordTillNow.pop_back();
		return 1;
	}
	//check all for 4 direction, for next char
	unsigned long int count = 0;
	
	array<array<int, 2>, 8> dir = {-1,0  ,0,-1  ,1,0  ,0,1, 1,1 ,-1,-1,  -1,1 ,1,-1};
	visitedTrack[x][y] = 1;
	
	countSoFar++;


	char nextCh = secretWord[countSoFar];
	int nx, ny;
	for (int i = 0; i < dir.size(); i++)
	{
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if (isValid(nx, ny, visitedTrack, chessBoard, nextCh))
			count +=countPath(chessBoard, secretWord, nx, ny, wordTillNow, countSoFar,visitedTrack);

	}
	visitedTrack[x][y] = 0;
	wordTillNow.pop_back();
	return count;
}

void clearArray(int ** arr)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			arr[i][j] = 0;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	string secretWord;
	cin >> secretWord;
	string chessBoard[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> chessBoard[i];
	}
	
	unsigned long long count = 0;
	int** visitedCells = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		visitedCells[i] = new	int[8];
	}

	clearArray(visitedCells);
	int countSoFar = 0;
		string str;
	for (int i = 0; i < 8; i++)
	{
		
		for (int j = 0; j < 8; j++)
		{
			if (chessBoard[i][j] == secretWord[0])
			{
				clearArray(visitedCells);
				str = "";
				countSoFar = 0;
				count += countPath(chessBoard,secretWord,i,j,str,countSoFar,visitedCells);
			}
		}
	}

	cout << count;
	return 0;
}
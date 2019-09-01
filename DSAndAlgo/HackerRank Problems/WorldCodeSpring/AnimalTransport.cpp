#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

enum Animal
{
	E = 0,
	D, C, M

};

struct animalInfo
{
	int pickZoo;
	int dropZoo;
	Animal type;


	/*animalInfo(int p, int d, Animal t):pickZoo(p),dropZoo(d),type(t)
	{
	}
	animalInfo(int p, int d) :pickZoo(p), dropZoo(d)
	{
	}*/
};

bool sortZoo(const animalInfo& a, const animalInfo& b)
{
	return a.pickZoo < b.pickZoo;

}

bool compareDrop( animalInfo& a, animalInfo& b)
{
	return a.dropZoo > b.dropZoo;

}
bool canCarry(int* anim, Animal type )
{
	//Dogs and Elephanct cannot be together
	if (type == Animal::D)
	{
		return anim[Animal::E] == 0;
	}

	//cats or dogs
	if( type == Animal::C)
		return anim[Animal::D] == 0;

	//mice or cats
	if(type == Animal::M)
		return anim[Animal::C] == 0;

	//elep or mice
	if(Animal::E)
		return anim[Animal::M] == 0;

	return true;
}


void minZooNumber( vector<animalInfo>& animalZoo, int totalZoo)
{
	//for each pickZoo, try to pick an animal.
	//queue<animalInfo> truck;
	priority_queue<animalInfo, vector<animalInfo>, function<bool( animalInfo&,animalInfo&)>> trck(compareDrop);
		
	int currentAnimals[4] = { 0 };

	sort(animalZoo.begin(), animalZoo.end(),sortZoo);

	//pick the first animal
	
	//truck.push(animalZoo[0]);
	
	vector<int> ans(animalZoo.size()+1,-1);
	int vectNum = 0;
	int minZooNumToVisit = 0;
	for (int currentZoo =1; currentZoo <= totalZoo; currentZoo++)
	{
		if (trck.empty())
		{
			int start = vectNum;
			//carry next animal in truck
			while (vectNum <animalZoo.size()&& animalZoo[vectNum].pickZoo == currentZoo)
			{
				if(trck.empty() || canCarry(currentAnimals,animalZoo[vectNum].type))
				{

					
					trck.push(animalZoo[vectNum]);
					currentAnimals[animalZoo[vectNum].type]++;
					minZooNumToVisit = max(animalZoo[vectNum].dropZoo, minZooNumToVisit);
					ans[trck.size()] = minZooNumToVisit;
					trck.pop();
					currentAnimals[animalZoo[vectNum].type]--;
					
				}
				//else 
				//	//this animal cannot be loaded
				//	cout << "-1" << " ";
				
				vectNum++;
			}

			//now try to load max  num

		}

		else
		{
			//check if a animal has to unload in this zoo
			
			while (!trck.empty() && currentZoo==trck.top().dropZoo)
			{
				animalInfo unloadedAnimal = trck.top();
				trck.pop();				
				//ans.push_back(currentZoo);
				currentAnimals[unloadedAnimal.type]--;
			}
			//now try to carry this zoo animal
			//carry next animal in truck
			while (vectNum <animalZoo.size() && animalZoo[vectNum].pickZoo == currentZoo)
			{
				if (trck.empty() || canCarry(currentAnimals, animalZoo[vectNum].type))
				{
					trck.push(animalZoo[vectNum]);
					currentAnimals[animalZoo[vectNum].type]++;
					minZooNumToVisit = max(animalZoo[vectNum].dropZoo, minZooNumToVisit);
					ans[trck.size()] = minZooNumToVisit;
				}
				vectNum++;
			}

			////again check for drop . in case for same 
			//while (!trck.empty() && currentZoo == trck.top().dropZoo)
			//{
			//	animalInfo unloadedAnimal = trck.top();
			//	trck.pop();
			//	ans.push_back(currentZoo);
			//	currentAnimals[unloadedAnimal.type]--;
			//}
		}
	}

	//print the ans
	for (int  i = 0; i < animalZoo.size(); i++)
	{
		if (i < ans.size())
			cout << ans[i];
		else
		{
			cout << "-1";
		}
		cout << " ";

	}

	

}

bool sortZooDropWise(const animalInfo& a, const animalInfo& b)
{
	return a.dropZoo < b.dropZoo;

}

void printZooNumber(vector<animalInfo>& animalZoo, int totalZoo)
{
	//for each pickZoo, try to pick an animal.
	//queue<animalInfo> truck;
	priority_queue<animalInfo, vector<animalInfo>, function<bool(animalInfo&, animalInfo&)>> trck(compareDrop);

	int currentAnimals[4] = { 0 };

	sort(animalZoo.begin(), animalZoo.end(), sortZoo);

	

	vector<int> ans;
	int vectNum = 0;
	trck.push(animalZoo[vectNum]);
	int pickZooNum = trck.top().pickZoo;
	int dropZooNum = trck.top().dropZoo;

	while (pickZooNum <= totalZoo)
	{

	}

	
	//print the ans
	for (int i = 0; i < animalZoo.size(); i++)
	{
		if (i < ans.size())
			cout << ans[i];
		else
		{
			cout << "-1";
		}
		cout << " ";

	}



}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int T;
	cin >> T;
	int m, n;
	for (int i = 0; i<T; i++)
	{
		cin >> m >> n;
		char ch;
		
		vector<animalInfo> animalZoo(n);
		for (int j = 0; j<n; j++)
		{
			cin >> ch;
			if (ch == 'E')
			{
				
				animalZoo[j].type = Animal::E;
			}
			else if (ch == 'D')
			{
				animalZoo[j].type = Animal::D;

				
			}
			else if (ch == 'C')
			{
				animalZoo[j].type = Animal::C;

				
			}
			else if (ch == 'M')
			{
				animalZoo[j].type = Animal::M;

				
			}



		}
		for (int j = 0; j < n; j++)
		{
			cin >> animalZoo[j].pickZoo;
		}
		for (int j = 0; j < n; j++)
		{
			cin >> animalZoo[j].dropZoo;
		}

		minZooNumber(animalZoo,m);

	}
	return 0;
}

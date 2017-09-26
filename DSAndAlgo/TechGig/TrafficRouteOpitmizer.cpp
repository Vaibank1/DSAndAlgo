#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <set>
#include<map>
#include<list>

using namespace std;

vector<string> paths;

class DirectedGraph{

	int V;
	vector<pair<int,int>> *adjMatrix;

public:
	DirectedGraph(int V) : V(V)
	{
		adjMatrix = new vector<pair<int,int>>[V+1] ;
	}

	int AddEdge(int u, int v, int w)
	{		
		//CHECK input 
		for(int i=0; i< adjMatrix[u].size();++i)
			if(adjMatrix[u].at(i).first == v)
				return -1;
			
		adjMatrix[u].push_back(make_pair(v,w));
		//adjMatrix[v].push_back(make_pair(u,w));
		return 1;
	}

	~DirectedGraph()
	{
		delete[] adjMatrix;
		V=0;
	}


	const vector<pair<int,int>>* getAdj()
	{
		return adjMatrix;
	}
};


void getAllPaths(int* visited,  vector<char>& str, DirectedGraph& graph, int v , int end)
{
	//mark this node visited
	visited[v]=1;
	str.push_back((char) v);

	if(v== end)
	{
		/*paths.push_back(str);
		cout<<str;*/
		
		for(int i =0; i<str.size();++i)
		{
			cout<<(int)str[i];
		}
		cout<<endl;
		visited[v]=0;
		str.pop_back();
		return ;
	}
	const vector<pair<int,int>>* adj = graph.getAdj();

	for(int i =0; i<adj[v].size();++i)
	{
		//visit all child
		int u = adj[v].at(i).first;
		if(!visited[u])
			getAllPaths(visited,str,graph,u,end);
	}
	//unmark or backtrack 
	visited[v]=0;
	str.pop_back();


}

void ExtractInfo(const string& str, int&u, int&v,int &w)
{
	int j =0;
	bool flagU= false, flagV=false;
	for(int i =0; i <str.length();++i)
	{
		if(str[i] == '#')
		{
			if(flagU == false)
			{
				u = stoi(str.substr(j,i));
				j=i+1;
				flagU = true;
			}
			else if(flagU == true && flagV ==false)
			{
				v = stoi(str.substr(j,i));
				j=i+1;
				flagV = true;
			}
		

		}
	}
	w = stoi(str.substr(j,str.length()));


}

vector < string > getTolls(int input1,vector < string > input2)
{
	//Write code here
	vector<string> vec;
	DirectedGraph trafficSystem = DirectedGraph(input1);
	int u=0,v=0,w=0;
	for(int i=0; i< input2.size();++i)
	{
		ExtractInfo(input2[i],u,v,w);
		if(-1 == trafficSystem.AddEdge(u,v,w) )
			{
				vec.push_back("NO SOLUTION");
				return vec;
		}

	
	}

	int* visited = new int[input1+1];
	for(int i = 0 ;i <=input1;++i)
		visited[i]=0;

	vector<char> result;
	
	
	getAllPaths(visited,result,trafficSystem,1,input1);
	return vec;
}

int main() {
    vector < string > output;
    int ip1;
    cin >> ip1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip2_size = 0;
    cin >> ip2_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> ip2;
    string ip2_item;
    for(int ip2_i=0; ip2_i<ip2_size; ip2_i++) {
        getline(cin, ip2_item);
        ip2.push_back(ip2_item);
    }
    output = getTolls(ip1,ip2);
    for(int output_i=0; output_i < (int)output.size(); output_i++)
	{
    	cout << output[output_i] << endl;;
    }
   return 0;
}

#include "stdafx.h"


#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

# define MAX_CHARS 27

//trie solution


struct TrieNode
{

	bool isEnd;
	int wordCount;
	TrieNode* child[MAX_CHARS];
	TrieNode()
	{
		isEnd=false;
		wordCount=0;		
		for( int i = 0; i < MAX_CHARS; ++i )
			child[i] = nullptr;
		
	}
	~TrieNode()
	{
		for( int i = 0; i < MAX_CHARS; ++i )
			if(child[i])
				delete child[i];
		if(child)
			delete[] child;
	}
};

TrieNode* trieHead = nullptr;

void insertInTrie(std::string& str, int index, TrieNode** root)
{
	if(str.length() < index)
		return;
	if(*root == nullptr)
	{
		//create the node
		 (*root) = new TrieNode();
	}
	if(str.length() != index)
	{
		
		insertInTrie(str,index+1,&((*root)->child[ tolower( str[index] ) - 97 ]));
	}
	else
	{
		
		(*root)->isEnd = true;
		(*root)->wordCount++;
	}

}

void printTrie(  TrieNode** root,std::string &str)
{
	
	if( *root != nullptr )
	{
		if((*root)->isEnd == false)
		{
			for(int i =0; i <MAX_CHARS;++i)
			{
				if((*root)->child[i])
				{
					str.push_back('a'+i);
					printTrie( &((*root)->child[i]) , str);
					str.pop_back();
				}
			}
		}
		
		else
		{
			std::cout<<str<<'\t'<<(*root)->wordCount<<std::endl;

		}
	}
	
	
	
	

}



int main()
{

	std::string str;

	

	while(true)
	{
		std::cin>>str;
		if(str =="END")
			break;
		insertInTrie(str,0,&trieHead);

	}
	std::cout<<std::endl;
	str="";
	printTrie(&trieHead,str);

	

	
	return 0;
}
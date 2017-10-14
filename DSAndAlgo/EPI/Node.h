#pragma once

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<memory>

#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
#include<iostream>

using namespace std;


template<typename T>
struct  Node
{
	T data;
	std::shared_ptr<Node<T>> next;
	Node(const T& a):data(a),next(nullptr){}


};


template<typename T>
struct  TreeNode
{
	T data;
	std::shared_ptr<TreeNode<T>> left,right;
	TreeNode(const T& a) :data(a), left(nullptr) ,right(nullptr) {}
	

};


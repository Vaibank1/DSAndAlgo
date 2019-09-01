//
// Character Filter
//
// (C) By Autonomous Intelligent Driving GmbH
//
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include<unordered_map>

class AlphaNumericPredicate {
	// Fill implementation here
	size_t histSize;
	int curPos;
	std::unordered_map<char, int> hashTable;
public:

	
	AlphaNumericPredicate() :histSize(), curPos(-1) {}
	bool operator()( char ch, int histSize) {
		
		if (!isalnum(ch))
			return false;
		curPos++;
		if (histSize == 0)
			return true;
		auto res = hashTable.find(ch);
		
		bool ans = false;
		if (res == hashTable.end()) 			
			ans =  true;		
		else if (curPos - res->second > histSize)
			ans= true;

		hashTable[ch] = curPos;
		return ans;
	}

};

template<typename InputIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator filter(InputIterator first, InputIterator last,
	OutputIterator result,
	UnaryPredicate predicate,
	size_t history_size)
{
	
	while (first != last)
	{
		if (predicate(*first,history_size)) {
			*result = *first;
			++result;
		}
		++first;
	}
	if(result != last)
		*result = '/0';
	// Fill implementation here
	return result;
}

//
// Filter string. Helper for mapping binary blobs to strings.
//
std::string filter_string(std::string source, size_t history_size)
{
	source.erase(filter(std::begin(source), std::end(source),
		std::begin(source),
		AlphaNumericPredicate{  }, history_size),
		std::end(source));
	return source;
}

//
// Main entry point.
//
int main()
{
	while (!std::cin.eof())
	{
		size_t history_size = 0;
		std::cin >> history_size;
		std::string source;
		std::getline(std::cin, source);
		std::cout << filter_string(source, history_size) << std::endl;
	}
	return 0;
}

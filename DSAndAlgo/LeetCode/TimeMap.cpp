#include<unordered_map>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class TimeMap {

	std::unordered_map<string, map<int, string>> hashTable;


public:

	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		hashTable[key].insert({ timestamp,value });
	}

	string get(string key, int timestamp) {

		auto it = hashTable.find(key);
		if (it == hashTable.end())
			return "";
		const map<int, string> & mp = it->second;

		if (mp.size() == 1)
		{
			auto it1 = mp.begin();
			if (it1->first <= timestamp)
				return it1->second;
			else
				return "";
		}
		auto itEnd = mp.end();
		itEnd--;
		if (itEnd->first <= timestamp)
			return itEnd->second;
		auto it1 = hashTable[key].upper_bound(timestamp);
		if (it1 == hashTable[key].begin())
			return "";
		it1--;
		return it1->second;


	}
};

/**
* Your TimeMap object will be instantiated and called as such:
* TimeMap* obj = new TimeMap();
* obj->set(key,value,timestamp);
* string param_2 = obj->get(key,timestamp);
*/
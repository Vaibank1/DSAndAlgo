#include<vector>
#include<set>

using namespace std;
class Solution {


public:
	bool dfs(int cur, vector<vector<int>>& graph, vector<int> & color) {

		color[cur] = 1;
		auto &adjList = graph[cur];

		for (auto & adj : adjList) {

			if (color[adj] == 1)
				return false;
			if (color[adj] == 2)
				continue;
			if (!dfs(adj, graph, color))
				return false;
		}

		color[cur] = 2;
		return true;

	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		vector<vector<int>> graph(numCourses, vector<int>());
		vector<int> color(numCourses, 0);
		for (int i = 0; i<prerequisites.size(); i++) {
			graph[prerequisites[i][0]].push_back(prerequisites[i][1]);

		}


		for (int i = 0; i<numCourses; i++) {
			if (color[i] == 0)
				if (!dfs(i, graph, color))
					return false;

		}


		return true;

	}
};


int main()
{
	

	vector<vector<int>> vec(2,vector<int>());
	vec[1].push_back(0);
	//vec[1].push_back(0);
	

	return 0;
}
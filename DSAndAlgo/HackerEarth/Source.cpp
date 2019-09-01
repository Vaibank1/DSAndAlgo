#include <iostream>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<int, int> m;
	map<int, int> ::iterator it;
	int n, q, a, y, z;
	cin >> n >> q;
	while (q--)
	{
		cin >> y >> z;
		if (y == 1)
		{
			m[z] = 1;
		}
		else {
			it = m.lower_bound(z);
			if (it != m.end())
			{
				cout << (it)->first << "\n";
			}
			else
				cout << "-1\n";
		}
	}
	return 0;
}
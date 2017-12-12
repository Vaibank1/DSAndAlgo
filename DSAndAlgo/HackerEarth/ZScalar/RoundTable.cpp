#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

struct StudentPos
{

	int studID;
	int tablePos;
};


bool compare(const StudentPos& a, const StudentPos&b)
{
	return a.studID < b.studID;
}

int main()
{

	int N = 0, Q = 0;
	cin >> N >> Q;
	vector<StudentPos> students(N);

	for (int i = 0; i < N; i++)
	{
		cin >> students[i].studID;
		students[i].tablePos = i;
	}

	sort(students.begin(), students.end(),compare);

	int studA = 0, studB = 0;
	StudentPos a, b;
	for (int i = 0; i < Q; i++)
	{
		cin >> a.studID >> b.studID;
		
		auto resA = lower_bound(students.begin(), students.end(),a, compare);
		auto  resB = lower_bound(students.begin(), students.end(), b, compare);
		vector<int> posA , posB ;

		for (resA; resA != students.end(); resA++)
		{
			if (resA->studID != a.studID)
				break;
			posA.push_back(resA->tablePos);
		}
		for (resB; resB != students.end(); resB++)
		{
			if (resB->studID != b.studID)
				break;
			posB.push_back(resB->tablePos);
		}
		int result = INT_MAX;
		
		for (auto it : posA)
		{
			for (auto itB : posB)
			{
				int tmpMin = abs(it - itB);
				tmpMin = min(tmpMin, N - tmpMin);
				result = min(result, tmpMin);
			}
		}

		result /= 2;
		cout << result << endl;

	}


	return 0;

}
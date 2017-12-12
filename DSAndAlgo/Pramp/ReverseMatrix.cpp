
#include <iostream>
#include <vector>
#include <iterator>
#include<algorithm>

using namespace std;

vector<char> reverseWords(const vector<char>& words)
{
	// your code goes here
	vector<char> arr(words);
	//reverse array

	int start = 0;
	int end = arr.size() - 1;
	char tmp;
	while (start < end)
	{

		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}


	//reverse each word
	start = -1;
	end = 0;
	for (int i = 0; i< arr.size(); i++)
	{
		if (arr[i] == ' ' && start != -1)
		{
			end = i - 1;

			while (start < end)
			{

				tmp = arr[start];
				arr[start] = arr[end];
				arr[end] = tmp;
				start++;
				end--;
			}
			start = -1;
		}
		else if (i == arr.size() - 1 && start != -1)
		{
			end = i;
			while (start < end)
			{

				tmp = arr[start];
				arr[start] = arr[end];
				arr[end] = tmp;
				start++;
				end--;
			}
			start = -1;
		}
		else if (start == -1 && arr[i] !=' ')
			start = i;


	}

	return arr;
}

int main() {
	/*vector<char> arr = { 'p', 'e', 'r', 'f', 'e', 'c', 't', ' ',
		'm', 'a', 'k', 'e', 's', ' ',
		'p', 'r', 'a', 'c', 't', 'i', 'c', 'e' };*/
	vector<char> arr = { 'b',' ',' ',' ', 'a' };

	vector<char>& ans = reverseWords(arr);
	copy(ans.begin(), ans.end(), ostream_iterator<char>(cout, " "));

	return 0;
}
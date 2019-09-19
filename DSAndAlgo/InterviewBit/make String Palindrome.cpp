#include<string>



int solve(std::string str) {
	int start = 0, end = str.length() - 1, tEnd = str.length() - 1;

	while (start<end)
	{
		if (str[start] == str[end])
		{
			start++;
			end--;
		}
		else
		{
			start = 0;
			tEnd--;
			end = tEnd;
		}

	}

	return str.length() - tEnd - 1;

}

int main()
{

	solve("AACECAAAA");
	return 0;
}
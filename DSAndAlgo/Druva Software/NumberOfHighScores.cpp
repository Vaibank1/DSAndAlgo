#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>


using namespace std;


void getData(const string& data, int &id, string & subject, int& marks)
{
	char delim = ',';
	int end = 0, start = 0;
	string arr[3];
	int i = 0;
	while ( (end = data.find(delim,start)) != string::npos)
	{
		arr[i] = data.substr(start, end-start);
		start = end + 1;
		i++;
	}

	arr[i] = data.substr(start, end );
	start = end + 1;

	id = stoi(arr[0]);
	marks = stoi(arr[2]);
	subject = arr[1];

}

void readFile(const  string& file , unordered_map<int, int>& fileData)
{
	ifstream  iFile;
	iFile.open(file);
	if (!iFile)
		cout << "Error occured..File not opened.";
	else
	{
		int marks = 0;
		int id = 0;
		string subject;
		string inputData;
		while (getline(iFile, inputData))
		{

			cout << inputData << endl;
			getData(inputData, id, subject, marks);
			fileData[id] += marks;

		}
	}

}


int countHighScores(const unordered_map<int, int>& studentData)
{
	int count = 0;
	for (auto it : studentData)
	{
		if (it.second >= 100)
			count++;
	}

	return count;
}


void output(const string& file , const string& strOut )
{
	ofstream oFile(file,ios::trunc);
	oFile << strOut;
}

int main()
{
	string inputFile = "Input.txt";
	unordered_map<int, int> fileData;
	readFile(inputFile, fileData);
	string outputFile = "Output.txt";
	
	output(outputFile,std::to_string( countHighScores(fileData)));

	return 0;
	
}
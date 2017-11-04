#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>

#define NUM_FIELDS 3
struct SplitLine {
  std::string fields[NUM_FIELDS];
};

int stroi(const std::string & str )
{
	int j = 0;
	int num=0;
	
	for (j=0; j < str.size();j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			num = num * 10 + (str[j] - '0');
			
		}
	}
	return num;
}

/* If you wish you can include any more files here.
   (from standard libraries only) */

int processData(std::vector<struct SplitLine> data) {
        /* 
         * Modify this function to process `data` as indicated
         * in the question. At the end, return the appropriate 
         * value.
         *
         * Please create appropriate classes, and use appropriate
         * data structures as necessary.
         *
         * Do not print anything in this function.
         *
         * Note: the existing program is not intended to be an example
         * of good programming practice. (For example, struct
         * SplitLine is not a very good way to hold the data for this
         * problem.)  However, the code that *you* write will be
         * evaluated on the basis of the quality of the code, use of
         * appropriate classes/data-structures, comments, and
         * efficiency of the algorithm used.
         *
         * Submit this entire program (not just this function)
         * as your answer
         */


	std::map<int, int> studentData;

	for (int i = 0; i < data.size(); i++)
	{
		SplitLine& sData = data[i];
		int id =   stroi(sData.fields[0]);
		int marks = stroi(sData.fields[2]);
		studentData[id] +=marks;

	}
	int count = 0;
	std::map<int, int>::iterator it = studentData.begin();
	for ( it; it!= studentData.end();it++ )
	{
		if (it->second >= 100)
			count++;
	}
	return count;

  return 0;
}

int main(void) {
  std::ifstream in("input.txt");
  std::vector<struct SplitLine> input_data;
  while (in) {
    struct SplitLine line;
    for (int i=0; i<NUM_FIELDS; i++) {
      if (i==NUM_FIELDS-1)
        std::getline(in, line.fields[i]);
      else
        std::getline(in, line.fields[i], ',');
    }
    if (line.fields[0] != "")
      input_data.push_back(line);
  }
  std::ofstream out("output.txt");
  out << processData(input_data) << std::endl;
  return 0;
}


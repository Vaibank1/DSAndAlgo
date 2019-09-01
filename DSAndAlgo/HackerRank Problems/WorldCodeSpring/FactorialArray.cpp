#include<iostream>
#include<vector>


using namespace std;
#define ULL unsigned long long
#define MAX 100001*2
ULL modM = pow(10, 9);
unsigned long long nfactmod(unsigned long long n, unsigned long long m)
{
	unsigned long long i, f;
	for (i = 1, f = 1; i <= n; i++) {
		f *= i;
		if (f > m) {
			f %= m;
		}
	}
	return f;
}




// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
ULL tree[MAX] = { 0 };  // To store segment tree
int getMid(int s, int e) { return s + (e - s) / 2; }

int getSumUtil( int ss, int se, int qs, int qe, int si)
{
	// If segment of this node is a part of given range, then return
	// the sum of the segment
	if (qs <= ss && qe >= se)
		return tree[si];

	// If segment of this node is outside the given range
	if (se < qs || ss > qe)
		return 0;

	// If a part of this segment overlaps with the given range
	int mid = getMid(ss, se);
	return (getSumUtil( ss, mid, qs, qe, 2 * si + 1) % modM +
		getSumUtil( mid + 1, se, qs, qe, 2 * si + 2) % modM)%modM;
}
// Return sum of elements in range from index qs (quey
// start) to qe (query end).  It mainly uses getSumUtil()
ULL getSum(int n, int qs, int qe)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n - 1 || qs > qe)
	{
		
		return 0;
	}

	return getSumUtil(0, n - 1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for
//  array[ss..se]. si is index of current node in segment
// tree st.
void constructSTUtil(const vector<unsigned int>& arr, int ss, int se, int si)
{
	// out of range as ss can never be greater than se
	if (ss > se)
		return;

	// If there is one element in array, store it in
	// current node of segment tree and return
	if (ss == se)
	{
		tree[si] = arr[ss];
		return;
	}

	// If there are more than one elements, then recur
	// for left and right subtrees and store the sum
	// of values in this node
	int mid = (ss + se) / 2;
	constructSTUtil(arr, ss, mid, si * 2 + 1);
	constructSTUtil(arr, mid + 1, se, si * 2 + 2);

	tree[si] = (tree[si * 2 + 1] + tree[si * 2 + 2])%modM;
}

/* Function to construct segment tree from given array.
This function allocates memory for segment tree and
calls constructSTUtil() to fill the allocated memory */
void constructST(const vector<unsigned int>& arr , int n)
{
	// Fill the allocated memory st
	constructSTUtil(arr, 0, n - 1, 0);
}

void updateValueUtil( int ss, int se, int i, int diff, int si)
{
	// Base Case: If the input index lies outside the range of 
	// this segment
	if (i < ss || i > se)
		return;

	// If the input index is in range of this node, then update 
	// the value of the node and its children
	tree[si] = (tree[si] + diff)%modM;
	if (se != ss)
	{
		int mid = getMid(ss, se);
		updateValueUtil( ss, mid, i, diff, 2 * si + 1);
		updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
	}
}



// Driver program to test above functions
int main()
{
	int n, m;
	cin >> n >> m;
	vector<unsigned int> arr(n, 0),fact(n,0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		fact[i] = nfactmod(arr[i], modM);
	}
	// Build segment tree from given array
	constructST(fact, fact.size());

	
	int queryType, arg1, arg2;
	for (int i = 0; i < m; i++)
	{
		cin >> queryType >> arg1 >> arg2;
		
		if (queryType == 1)
		{
			//make indexes  0 compliant
			arg1--;
			arg2--;
			//increase values by 1
			for(int i=arg1;i<=arg2;i++)
			{
				ULL updateVal = arr[i] * fact[i];
				arr[i]++;
				fact[i] += updateVal;
				updateValueUtil(0, n - 1, i, updateVal, 0);
			}
			
		}
		else if (queryType == 2)
		{

			//make indexes  0 compliant
			arg1--;
			arg2--;
			cout << getSum(n, arg1, arg2) << endl;;
			//cout<<nfactmod(n, modM)<<endl;
		}
		else 
		{
			arg1--;
			ULL updateVal = nfactmod(arg2,modM) -fact[arg1];
			arr[arg1] = arg2;			
			fact[arg1] += updateVal;
			updateValueUtil(0, n - 1, arg1, updateVal, 0);
		}
	}
	

	return 0;
}


using namespace std;
#include <iostream>
#include <vector>

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine(vector<int> A, vector<int> B, vector<int> &R)
{
  int ia = 0;   // index for A
  int ib = 0;   // index for B
  int ir = 0;   // index for R

  while(ia < A.size() || ib < B.size())
    {
      if((ia < A.size()) && ((ib >= B.size() || A[ia] <= B[ib])))
	{
	  R.push_back(A[ia]);
    	  ia++;
	}

      else
	{
	  R.push_back(B[ib]);
      	  ib++;
	}
      
      // be careful -- R comes in as an empty vector with no slots  
      cout << "comparison " << endl;
      ir++;
    }
}


int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  
  for(int i = 1; i <= N; i++)
    {
      cout << "element :"; 
      cin >> e; 
      
      L1.push_back(e);
    } 

  cout << "List2"  << endl; 
  
  for(int i = 1; i <= N; i++)
    { 
      cout << "element :"; 
      cin >> e;
 
      L2.push_back(e);
    } 

  // call combine here to combine L1 and L2 into L3
  combine(L1, L2, L3);
  
  cout << "The result is: ";
  
  for(int i = 0; i < L3.size(); i++)
    { 
      cout << L3[i]; 
    } 

  cout << endl;
}// end of main

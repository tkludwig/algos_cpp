#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <assert.h>

#include <math.h> // for use of INFINITY

void printvec(const std::vector<float> & fvec)
{
  std::cout << "[ ";
  for(auto fvit = fvec.begin(); fvit<fvec.end(); fvit++)
  {
    std::cout << (*fvit) << " ";
  }
  std::cout << "]"<<std::endl;
}

void merge(std::vector<float> & A, int p, int q, int r)
{
  unsigned int n1 = q - p;
  unsigned int n2 = r - q + 1;

  std::vector<float> L(A.begin()+p, A.begin()+q);
  std::vector<float> R(A.begin()+q, A.begin()+r+1);
  L.push_back(INFINITY);
  R.push_back(INFINITY);

  assert(L.size() == n1+1);
  assert(R.size() == n2+1);
  
  int i = 0;
  int j = 0;

  for(int k = p; k <= r; k++)
  {
    printvec(A);
    printvec(L);
    printvec(R);
    std::cout << "i, j, k " << i << " " << j << " " << k << std::endl;
    if(L.at(i) <= R.at(j))
    {
      A.at(k) = L.at(i);
      i++;
    }    
    else
    {
      A.at(k) = R.at(j);
      j++;
    }
  }
}

void merge_sort(std::vector<float> & fvec, int p, int r)
{
  if(p < r)
  {
    int q = (p+r) / 2;
    
  }
  return;
}


int main()
{

  float ma [] = {1., 2., 3., 4., 0.5, 1.5, 2.5, 3.5, 4.5}; //input for p=0, q=4, r=8
  std::vector<float> merge_in(ma, ma+sizeof(ma)/sizeof(ma[0]));
  printvec(merge_in);
  merge(merge_in, 0, 4, 8);
  printvec(merge_in);
 
}



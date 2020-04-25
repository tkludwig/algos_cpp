#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void merge_sort(std::vector<float> & fvec, int p, int r)
{
  
}

void printvec(const std::vector<float> & fvec)
{
  std::cout << "[ ";
  for(auto fvit = fvec.begin(); fvit<fvec.end(); fvit++)
  {
    std::cout << (*fvit) << " ";
  }
  std::cout << "]"<<std::endl;
}

int main()
{
  float farr [] = {1., 2., 2.5, 3., 2.4, 2.1};
  std::vector<float> fvec(farr, farr+sizeof(farr)/sizeof(farr[0]));
  printvec(fvec);

   
 
}



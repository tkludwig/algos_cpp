#include <iostream>
#include <vector>
#include <math.h>

void printvec(const std::vector<float> & fvec)
{
  std::cout << "[ ";
  for(auto fvit = fvec.begin(); fvit<fvec.end(); fvit++)
  {
    std::cout << (*fvit) << " ";
  }
  std::cout << "]"<<std::endl;
}

int partition(std::vector<float> & A, int p, int r)
{
  float x = A.at(r);
  int i = p-1;
  for(int j = p; j < r; j++)
  {
    if (A.at(j) <= x)
    {
      //printvec(A);
      //std::cout << "i, j, p, r " << i << " " << j << " " << p << " " << r << std::endl;
      i++;
      float temp = A.at(i);
      A.at(i) = A.at(j);
      A.at(j) = temp;
    }
  } 
  float temp2 = A.at(i+1);
  A.at(i+1)=A.at(r);
  A.at(r)=temp2;
  return i+1;
}

void quicksort(std::vector<float> & A, int p, int r)
{
  if(p<r)
  {
    int q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int main()
{
  float qs [] = {0.4, 1.4, -0.4, 6.4, 2.4, 7.4, 0.5};
  std::vector<float> qs_in(qs, qs+sizeof(qs)/sizeof(qs[0]));
  printvec(qs_in);

  //int q = partition(qs_in,0,qs_in.size()-1);
  //printvec(qs_in);
  //std::cout << q << std::endl;
  quicksort(qs_in, 0, qs_in.size()-1);
  printvec(qs_in);
}

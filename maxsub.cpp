//maximum subarray algorithm: chapter 4

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

void find_max_crossing_subarray(const std::vector<float> & A,int low,int mid,int high,int &i_max_left,int &i_max_right,float &max_mid)
{
  float left_sum = - INFINITY;
  float sum = 0;
  for(int i=mid; i>=low; i--)
  {
    sum += A.at(i);
    if(sum > left_sum)
    {
      left_sum = sum;
      i_max_left = i;
    }
  }
  float right_sum = - INFINITY;
  sum = 0;
  for(int i=mid+1; i<=high; i++)
  {
    sum += A.at(i);
    if(sum > right_sum)
    {
      right_sum = sum;
      i_max_right = i;
    }
  }
  max_mid = left_sum+right_sum;
}

int main()
{
  float ms [] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}; //input from example: 8..11 is the solution
  std::vector<float> v_ms(ms, ms+sizeof(ms)/sizeof(ms[0]));
  
  int i_max_left = -1;
  int i_max_right = -1;
  float max_mid = 0.;

  find_max_crossing_subarray(v_ms, 0, 8, 15, i_max_left, i_max_right, max_mid);
  std::cout<< i_max_left<< " " <<i_max_right<< " " <<max_mid<<std::endl;
   
}


//maximum subarray algorithm: chapter 4
//  due to the way the algos are written in CLRS, easiest adaptation to C++ was to use void fns w reference parameters rather than returns

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

void find_max_subarray(const std::vector<float> & A, int low, int high, int &i_low, int &i_high, float & sum)
{
  std::cout << "find_max_subarray( ";
  std::cout << " " << low << " " << high << ")"<<std::endl;  
  if(high==low)
  {
    i_low = low;
    i_high = high;
    sum = A.at(low);
  }
  else
  {
    int mid = (low+high)/2;

    int left_low;
    int left_high;
    float left_sum;
    int right_low;
    int right_high;
    float right_sum;

    int cross_low;
    int cross_high;
    float cross_sum;

    find_max_subarray(A,low,mid,                  left_low,  left_high,  left_sum);
    find_max_subarray(A,mid+1,high,               right_low, right_high, right_sum);
    find_max_crossing_subarray(A,low,mid,high,    cross_low,cross_high,cross_sum);


    if(  (left_sum >= right_sum) && (left_sum >= cross_sum))
    {
      std::cout << "left wins   ";
      i_low = left_low;
      i_high = left_high;
      sum = left_sum;
    }
    else if(  (right_sum >= left_sum) && (right_sum >= cross_sum))
    {
      std::cout << "right wins   ";
      i_low = right_low;
      i_high = right_high;
      sum = right_sum;
    }
    else
    {
      std::cout << "cross wins   ";
      i_low = cross_low;
      i_high = cross_high;
      sum = cross_sum;
    }
  }
  std::cout << "i_low, i_high, sum " << i_low << " " << i_high << " " << sum << std::endl;
}

int main()
{
  float ms [] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}; //input from example: 8..11 is the solution
  std::vector<float> v_ms(ms, ms+sizeof(ms)/sizeof(ms[0]));
  
  int i_max_left = -1;
  int i_max_right = -1;
  float max_mid = 0.;

  //find_max_crossing_subarray(v_ms, 0, 8, 15, i_max_left, i_max_right, max_mid);
  //std::cout<< i_max_left<< " " <<i_max_right<< " " <<max_mid<<std::endl;

  find_max_subarray(v_ms, 0, v_ms.size()-1, i_max_left, i_max_right, max_mid);
  std::cout<< i_max_left<< " " <<i_max_right<< " " <<max_mid<<std::endl;
}


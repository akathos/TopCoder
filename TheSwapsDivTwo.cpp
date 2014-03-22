#include <vector>

using namespace std;

class TheSwapsDivTwo {
  public:
  int find(vector <int> sequence)
  {
    int i, j, len, count, extra = 0;

    len = sequence.size();
    count = 0;

    for(i = 0; i < len; ++i)
    {
      for(j = i+1; j < len; ++j)
      {
        if(sequence[i] == sequence[j])
          extra = 1;
        else 
          ++count;
      }
    }

    return count + extra;
  }
};
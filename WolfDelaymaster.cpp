#include <string>

using namespace std;

#define VALID "VALID"
#define INVALID "INVALID"

class WolfDelaymaster {
  public:
  String check(String str)
  {
    const char * wolf = "wolf";
    int n, m, i = 0;
    
    while(str[i] != '\0')
    {
      n = 0;
      for(int j = 0; j < 4; ++j)
      {
        m = 0;
        while(str[i++] == wolf[j])
        {
          if(j == 0) 
            ++n;
          else 
            ++m;
        }
        if(j != 0 && n != m) 
          return INVALID;
      }
    }

    return VALID;
  }
};
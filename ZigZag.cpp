#include <vector>

using namespace std;

class ZigZag
{
public:
	int longestZigZag(vector <int> sequence)
	{
		int count;
		int len = sequence.size();
		int diffs[len-1];
		int i, dir, allEqual = 1;

		// empty sequence
		if(len == 0) return 0;

		// sequence only has 1 element
		if(len == 1) return 1;

		// compute the difference between each number
		for(i = 1; i < len; ++i)
		{
			diffs[i-1] = sequence[i] - sequence[i-1];
			if(allEqual == 1 && diffs[i-1] != 0)
				allEqual = 0;
		}

		// check if all the numbers are the same
		if(allEqual == 1) return 1;

		// count all the zigzags
		len -= 1;
		dir = -1; // -1 don't care, 0 down, 1 up
		count = 1;
		for(i = 0; i < len; ++i)
		{
			if(diffs[i] != 0)
			{
				if(dir == 0 && diffs[i] > 0)
				{
					dir = 1;
					++count;
				}
				else if(dir == 1 && diffs[i] < 0)
				{
					dir = 0;
					++count;
				}
				else if(dir == -1)
				{
					dir = diffs[i] > 0;
					++count;
				}
			}
		}

		return count;
	}
};
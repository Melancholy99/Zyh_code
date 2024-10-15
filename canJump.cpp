#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost , i + nums[i]);
                if (rightmost >= n -1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int start = 0,end = 1;
        int counts = 0;
        while(end < n)
        {   
            int maxPos = 0;
            for (int i = start; i < end; i++)
            {
                maxPos = max(maxPos, i + nums[i]);
            }
            start = end;
            end = maxPos + 1;
            counts++;
        }
        return counts;
    }
};
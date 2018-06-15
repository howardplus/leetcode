#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(const vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while (i < j) {
            int mid = i + (j-i)/2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                i = mid+1;
            else
                j = mid-1;
        }

        if (nums[i] < target)
            return i+1;
        else
            return i;
    }
};

int main()
{
    Solution s;

    cout << s.searchInsert(vector<int>{1,3,4,5}, 0) << endl;
    cout << s.searchInsert(vector<int>{1,3,4,5}, 2) << endl;
    cout << s.searchInsert(vector<int>{1,3}, 0) << endl;

    return 0;
}

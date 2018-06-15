/*
 * https://leetcode.com/problems/4sum/description/
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

using Sums = vector<vector<int>>;
using Hash = unordered_map<string, bool>;

class Solution {

public:
    bool sumTarget(vector<int>& nums, int target, int count, Sums& sums, Hash& hash) {
        if (count == 1) {
            for (auto n : nums) {
                if (target == n) {
                    sums.push_back(vector<int>{n});
                    return true;
                }
            }
            return false;
        }

        for (auto i=0; i<nums.size()-1; i++) {
            Sums s1;
            auto numsLeft = vector<int>(begin(nums)+i+1, end(nums));
            sumTarget(numsLeft, target-nums[i], count-1, s1, hash);
            for (auto it = begin(s1); it != end(s1); ++it) {
                auto s = *it;
                s.insert(begin(s), nums[i]);
                auto tmp = s;

                if (tmp.size() < 4) {
                    sums.push_back(s);
                } else {
                    sort(begin(tmp), end(tmp));
                    stringstream ss;
                    ss << tmp[0] << tmp[1] << tmp[2] << tmp[3];
                    if (hash.find(ss.str()) == end(hash)) {
                        sums.push_back(s);
                        hash[ss.str()] = true;
                    } else {
                        it = s1.erase(it); 
                        if (it == end(s1))
                            break;
                    }
                }
            }
        }
        return true;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        Hash h;
        Sums sums;
        if (nums.size() < 4)
            return sums;

        sumTarget(nums, target, 4, sums, h);
        return sums;
    }
};

int main()
{
    Solution s;

/*
    auto t1 = vector<int>{1, 0, -1, 0, -2, 2};
    Sums s1 = s.fourSum(t1, 0);
    cout << s1.size() << endl;
    for (auto s : s1) {
        for (auto n : s) {
            cout << n << " ";
        }
        cout << endl;
    }

    auto t2 = vector<int>{};
    Sums s2 = s.fourSum(t2, 0);
*/

    auto t3 = vector<int>{-3,-2,-1,0,0,1,2,3};
    Sums s3 = s.fourSum(t3, 0);

    for (auto s : s3) {
        for (auto n : s) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}

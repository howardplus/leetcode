/*
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = 0, j = 0;

        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0)
            return;

        nums1.resize(m+n);
        auto tmp = nums1;
        for (auto k=0; k<(m+n); k++) {
            if (i >= m)
                nums1[k] = nums2[j++];
            else if (j >= n)
                nums1[k] = tmp[i++];
            else if (tmp[i] < nums2[j])
                nums1[k] = tmp[i++]; 
            else 
                nums1[k] = nums2[j++];
        }
    }

    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        while( n > 0 )
            nums1[n + m - 1] = ( m == 0 || nums2[n - 1] > nums1[m - 1]) ? nums2[--n] : nums1[--m];
    }
};

int main()
{
    Solution s;

    vector<int> t1 = {1,2,4,5,6};
    vector<int> t2 = {3}; //2, 7, 8, 12};

    t1.reserve(t1.size() + t2.size());
    s.merge1(t1, t1.size(), t2, t2.size());

    for (auto v: t1) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        auto i = 1;
        auto j = n;
        while (i <= j) {
            auto mid = i + (j-i)/2;
            if (isBadVersion(mid))
                j = mid-1;
            else
                i = mid+1;
        }
        return i;
    }
};

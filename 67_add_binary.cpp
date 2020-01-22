#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int alen = a.length();
        int blen = b.length();

        while (alen || blen) {
            int an = 0;
            int bn = 0;
            if (alen > 0 && a[alen-1] == '1')
                an = 1;
            if (blen > 0 && b[blen-1] == '1')
                bn = 1;
            
            auto val = an + bn + carry;
            carry = val / 2;
            val = val % 2;

            if (val == 0)
                result = result.insert(0, "0");
            else
                result = result.insert(0, "1");

            if (alen > 0)
                alen--;
            if (blen > 0)
                blen--;
        }

        if (carry)
            result = result.insert(0, "1");

        return result;
    }
};

int main() {
    Solution s;

    string a = "11";
    string b = "1";

    cout << s.addBinary(a,b) << endl;

    a = "1010";
    b = "1011";

    cout << s.addBinary(a,b) << endl;

    return 0;
}

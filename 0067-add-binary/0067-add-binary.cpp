class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0, carry = 0;

        while (i < max(a.size(), b.size())) {
            int digitA = (i >= a.size()) ? 0 : a[i] - '0';
            int digitB = (i >= b.size()) ? 0 : b[i] - '0';

            int sum = digitA + digitB + carry;

            res += (sum % 2) + '0';
            carry = sum / 2;

            i++;
        }

        if (carry) res += "1";

        reverse(res.begin(), res.end());
        return res;
    }
};
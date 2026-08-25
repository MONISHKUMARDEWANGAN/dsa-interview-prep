class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int i=0, carry=0;
        while(i<max(num1.size(), num2.size())) {
            int digitA = (i>=num1.size()) ? 0 : num1[i]-'0';
            int digitB = (i>=num2.size()) ? 0 : num2[i]-'0';

            int digit = digitA + digitB + carry;
            carry = digit/10;
            res+=digit%10+'0';

            i++;
        }

        if(carry!=0) res+=carry+'0';
        reverse(res.begin(), res.end());

        return res;
    }
};
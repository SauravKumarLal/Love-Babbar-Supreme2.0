// Debug the code. Add two binary numbers.
#include <iostream>
#include <string.h>
#include<algorithm>
using namespace std;

string addBinary(string a, string b)
{
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            carry += a[i--] - '0';
        if (j >= 0)
            carry += b[j--] - '0';
        ans += carry % 2 + '0';
        carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b; // cin.get(s, 100);
    cout << addBinary(a, b);

    return 0;
}
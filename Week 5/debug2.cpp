// Debug the code. Integer to Romans. 1 ≤ n ≤ 2000.
#include <iostream>
#include <string.h>

using namespace std;

string intToRoman(int num)
{
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM"};

    return ths[num / 1000] + hrns[(num / 100) % 10] + tens[(num / 10) % 10] + ones[num % 10];
}

int main()
{
    int s;
    cin >> s; // cin.get(s, 100);
    cout << intToRoman(s);

    return 0;
}
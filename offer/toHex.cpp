#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int k = 8;
int _count;
char base[16] = {
    '0','1','2','3','4','5','6','7',
    '8','9','a','b','c','d','e','f',
};

string toHex(int num) {
    string res;
    while (k--) {
        _count = 0;
        for (int i = 0; i < 4; i++) {
            _count += (num & 1) * pow(2, i), (num >>= 1);
        }
        res.push_back(base[_count]);
    }
    while (res[res.size() - 1] == '0') {
        res.pop_back();
    }
    if (res == "") {
        res.push_back('0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    while (cin >> n) {
        string result = toHex(n);
        cout << result << endl;
    }
    return 0;
}

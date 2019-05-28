#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

/*
 * 常规解法
 * */
int maxSubArray(vector<int>& nums) {
    int result = INT_MIN;
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum > result) {
            result = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return result;
}

/*
 * 动态规划
 * */
int maxSubArray(vector<int>& nums, int n) {
    vector<int> dp(nums);
    int _max = dp[0] = nums[0];
    for (int i = 0; i < n; i++) {
        if (nums[i] + dp[i - 1] > nums[i]) {
            dp[i] = nums[i] + dp[i - 1];
        } else {
            dp[i] = nums[i];
        }
        if (_max < dp[i]) {
            _max = dp[i];
        }
    }
    return _max;
}
int main()
{
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (size_t i = 0; i < nums.size(); i++) {
            cin >> nums[i];
        }
        cout << maxSubArray(nums) << endl;
    }
    return 0;
}

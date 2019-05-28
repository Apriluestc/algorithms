#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
 * 举例：
 * pushV:1, 2, 3, 4, 5
 *      
 * popV :4, 5, 3, 2, 1
 *      
 * 首先 1 入辅助栈 s，此时栈顶元素为 1 != 4，继续入栈
 *
 * 此时 2 != 4，继续入栈
 * 
 * 此时 3 != 4，继续入栈
 * 
 * 此时 4 == 4，pop 4，弹出序列向后移一位，此时为 5，辅助栈里面是 1, 2, 3
 * 
 * 此时栈顶 3 != 5，继续入栈
 * 
 * 此时栈顶 5 == 5，pop 5，弹出序列向后移动一位，此时为 3，辅助栈里面是 1, 2, 3
 * 
 * 依次执行，最后辅助栈为空，如果不空，则说明不是该序列的弹出序列*/

bool isPopOrder(string pushV, string popV) {

    /*
     * 弹出序列与入栈序列长度不同 false
     * */
    if (pushV.size() != popV.size()) {
        return false;
    }

    /*
     * 辅助栈 s 遍历入栈序列 pushV
     * */
    stack<int> s;

    /*
     * popIndex 用于标识弹出序列的位置
     * */
    int popIndex = 0;

    /*
     * 遍历入栈序列，先将元素放进辅助栈中
     *
     * 然后判断栈顶元素是不是出栈序列的第一个元素
     *
     * 若不是，则继续入栈，若是则出栈，直到相等以后开始出栈
     *
     * 直至辅助栈为空，则说明互为压入、弹出序列
     * */
    for (size_t i = 0; i < pushV.size(); i++) {

        /*
         * 入栈序列的第一个元素先入辅助栈
         * */
        s.push(pushV[i]);

        /*
         * 判断，辅助栈栈顶元素是否与弹出序列的第一个元素相等
         *
         * 若相等，则出栈，弹出序列标记位 popIndex 后移
         * */
        while (!s.empty() && s.top() == popV[popIndex]) {
            s.pop();
            popIndex++;
        }
    }

    /*
     * 辅助栈空，则互为压入弹出序列
     * */
    return s.empty();
}

int main()
{
    /*
     * 第一行，输入一个整数 T
     *
     * 第二行输数 2 * T 个字符串
     * */
    int T;
    while (cin >> T) {
        vector<string> vs(2 * T);
        for (int i = 0; i < 2 * T; i++) {
            cin >> vs[i];
        }
        /*
         * 这里也可用 cin >> vs[i]
         *
         * 两者区别：
         *      cin 遇到空格就结束了，所以应对字符串中有空格的不适用
         *      getline 刚好解决了
         * */
        for (size_t i = 0; i < vs.size(); i += 2) {
            if (isPopOrder(vs[i], vs[i + 1])) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

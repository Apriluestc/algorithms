/*
 * 根据二叉树的前序序列、中序序列重新构建 二叉树
 * */

/*
 * 思路
 * 1、先求出根节点，即前序序列的第一个元素
 * 2、将根节点带入到中序遍历序列中求出左右子树的中序遍历序列
 * 3、通过左右子树的中序遍历序列元素集合带入前序遍历序列可以求出左右子树的前序遍历序列
 * 4、左右子树的前序序列第一个元素分别是根节点的左右儿子
 * 5、求出了左右子树的 4 中序列可以递归上述步骤
 * */

#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        :val(x)
        ,left(nullptr)
        ,right(nullptr)
    {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        TreeNode* root = reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre, int startPre, int endPre, vector<int> vin, int startVin, int endVin) {
        //递归出口
        if (startPre > endPre || startVin > endVin) {
            return nullptr;
        }
        //定义二叉树的根节点
        //先求出树的根节点，即前序序列的第一个元素
        TreeNode* root = new TreeNode(pre[startPre]);

        //在将根节点带入到中序遍历序列中，求出左右子树的中序遍历序列
        for (int i = startVin; i <= endVin; i++) {
            if (vin[i] == pre[startPre]) {
                //通过左右子树的中序遍历序列中带入到前序遍历序列中
                //左右子树的第一个元素分别是左右子树的左右孩子
                root->left = reConstructBinaryTree(pre, startPre + 1, startPre + i - 1, vin, startVin, i - 1);
                root->right = reConstructBinaryTree(pre, i - startVin + startPre + 1, endPre, vin, i + 1, endVin);
                break;
            }
        }
        return root;
    }
};

// 根据后序遍历和中序遍历序列构建二叉树，并输出二叉树的层序遍历序列。
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 首先从后序遍历序列中获取根节点的值，然后在中序遍历序列中找到根节点的位置。
// 根据根节点的位置，将中序遍历序列分为左子树和右子树的序列。
// 然后递归地构建左子树和右子树，并将其连接到根节点上。最后返回根节点。
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& idxMap) {
    if (inStart > inEnd || postStart > postEnd) { // 递归终止条件
        return nullptr;
    }

    int rootVal = postorder[postEnd]; // 后序遍历序列的最后一个元素是根节点
    auto* root = new TreeNode(rootVal); // 构建根节点

    int rootIdx = idxMap[rootVal]; // 根节点在中序遍历序列中的下标
    int leftSubtreeSize = rootIdx - inStart; // 左子树的节点个数

    root->left = buildTree(inorder, postorder, inStart, rootIdx - 1, postStart, postStart + leftSubtreeSize - 1, idxMap); // 递归构建左子树
    root->right = buildTree(inorder, postorder, rootIdx + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1, idxMap); // 递归构建右子树

    return root;
}

// 使用队列进行广度优先搜索，依次将每层的节点加入到结果序列中。
// 首先将根节点加入队列，然后开始循环。
// 每次从队列中取出一个节点，将其值加入结果序列，然后将其左右子节点（如果存在）加入队列。
// 重复这个过程，直到队列为空。最后返回结果序列。
vector<int> levelOrderTraversal(TreeNode* root) { // 层序遍历
    vector<int> levelOrder;

    if (root == nullptr) {
        return levelOrder;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        levelOrder.push_back(node->val);

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }

    return levelOrder;
}

// 首先构建一个哈希表 idxMap，将中序遍历序列中每个元素和对应的索引存储起来。
// 然后调用 buildTree 函数根据后序遍历和中序遍历序列构建二叉树。
// 最后调用 levelOrderTraversal 函数获取二叉树的层序遍历序列，并返回结果。
vector<int> getLevelOrderTraversal(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> idxMap; // 为了在后序遍历序列中快速找到根节点在中序遍历序列中的位置
    // 在构建二叉树的过程中，我们需要根据后序遍历序列中的元素确定当前子树的根节点，并在中序遍历序列中找到该根节点的位置，以将中序遍历序列分为左子树和右子树。
    // 通过构建哈希表 idxMap，我们可以将中序遍历序列中每个元素和对应的索引存储起来，以便快速查找。
    // 这样，在后序遍历序列中确定根节点时，我们可以使用哈希表查找根节点在中序遍历序列中的位置，而不需要进行线性搜索。
    int n = inorder.size();

    for (int i = 0; i < n; i++) {
        idxMap[inorder[i]] = i;
    }

    return levelOrderTraversal(buildTree(inorder, postorder, 0, n - 1, 0, n - 1, idxMap));
}

int main() {
    int N;
    cin >> N;

    vector<int> postorder(N), inorder(N);
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }

    vector<int> levelOrder = getLevelOrderTraversal(inorder, postorder);

    for (int i = 0; i < levelOrder.size(); i++) {
        cout << levelOrder[i];
        if (i != levelOrder.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> tovisit;

        TreeNode *currNode = root;
        TreeNode *lastNode = NULL;

        while (currNode || !tovisit.empty()) {
            if (currNode) {
                tovisit.push(currNode);
                currNode = currNode->left;
            }
            else {
                TreeNode *topNode = tovisit.top();
                if (topNode->right && lastNode != topNode->right) {
                    currNode = topNode->right;
                }
                else {
                    result.push_back(topNode->val);
                    lastNode = topNode;
                    tovisit.pop();
                }
            }
        }

        return result;
    }
};

/* README.md 中的中序遍历代码。*/
void inorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)          // 1.
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            // find predecessor
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)   // 2.a)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else                       // 2.b)
            {
                prev->right = NULL;
                printf("%d ", cur->val);
                cur = cur->right;
            }
        }
    }
}


/******************
*Morris traversal:*
*******************/
void reverseNodes(TreeNode* start, TreeNode* end) {
    if (start == end) return;
    TreeNode* x = start;
    TreeNode* y = start -> right;
    TreeNode* z;
    while (x != end) {
        z = y -> right;
        y -> right = x;
        x = y;
        y = z;
    }
}
void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& nodes) {
    reverseNodes(start, end);
    TreeNode* node = end;
    while (true) {
        nodes.push_back(node -> val);
        if (node == start) break;
        node = node -> right;
    }
    reverseNodes(end, start);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> nodes;
    TreeNode* dump = new TreeNode(0);
    dump -> left = root;
    TreeNode* curNode = dump;
    while (curNode) {
        if (curNode -> left) {
            TreeNode* predecessor = curNode -> left;
            while (predecessor -> right && predecessor -> right != curNode)
                predecessor = predecessor -> right;
            if (!(predecessor -> right)) {
                predecessor -> right = curNode;
                curNode = curNode -> left;
            }
            else {
                reverseAddNodes(curNode -> left, predecessor, nodes);
                predecessor -> right = NULL;
                curNode = curNode -> right;
            }
        }
        else curNode = curNode -> right;
    }
    return nodes;
}

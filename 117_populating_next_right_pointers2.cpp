/* Given a binary tree
 *
 * Populate each next pointer to point to its next right node. If there
 * is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int v): val(v), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        
    }
};

int main() {
    Solution s;

    TreeLinkNode *root = new TreeLinkNode(1);
    TreeLinkNode *n2 = root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    TreeLinkNode *n4 = root->left->left = new TreeLinkNode(4);
    TreeLinkNode *n5 = root->left->right = new TreeLinkNode(5);
    root->right->right = new TreeLinkNode(7);

    s.connect(root);

    cout << n2->next->val << endl;
    cout << n4->next->val << endl;
    cout << n5->next->val << endl;

    return 0;
}

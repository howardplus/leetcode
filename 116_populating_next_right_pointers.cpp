/* Given a binary tree
 *
 * Populate each next pointer to point to its next right node. If there
 * is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 */
#include <iostream>
#include <math.h>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int v): val(v), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    void traverse(TreeLinkNode *n, TreeLinkNode *parent, int level, int& idx) {
        // end of this level
        TreeLinkNode *prev = n;
        int end = pow(2, level)-1;
        int up = 2;
        bool uptrend = true;
        while (idx < end) {
            cout << "idx = " << idx << "; up = " << up << endl;

            // even idx: UP -> Right 
            if (idx % 2 == 0) {
                n = parent->right;
                idx++;
                continue;
            }

            // odd idx
            for (auto i=0; i<up; i++) {
                n = parent;
            }
            n = n->right;
            for (auto i=0; i<up-1; i++) {
                n = n->left;
            }

            if (up == level)
                uptrend = false;

            if (uptrend)
                up++;
            else
                up--;

            prev->next = n;
            prev = n;
            idx++;
        }
    }

    void connect(TreeLinkNode *root) {
        if (root == nullptr)
            return;

        int level = 1;
        TreeLinkNode *parent = root;
        TreeLinkNode *left = root->left;
        while (left) {
            cout << "level = " << level << endl;
            int idx = 0;

            // at left, start traverse
            traverse(left, parent, level, idx);
             
            // go down next level
            level++;
            parent = left;
            left = left->left;
        }
    }
};

int main() {
    Solution s;

    TreeLinkNode *root = new TreeLinkNode(-1);
    root->left = new TreeLinkNode(0);
    root->right = new TreeLinkNode(1);
    root->left->left = new TreeLinkNode(2);
    root->left->right = new TreeLinkNode(3);
    root->right->left = new TreeLinkNode(4);
    root->right->right = new TreeLinkNode(5);
    root->left->left->left = new TreeLinkNode(6);
    root->left->left->right = new TreeLinkNode(7);
    root->left->right->left = new TreeLinkNode(8);
    root->left->right->right = new TreeLinkNode(9);
    root->right->left->left = new TreeLinkNode(10);
    root->right->left->right = new TreeLinkNode(11);
    root->right->right->left = new TreeLinkNode(12);
    root->right->right->right = new TreeLinkNode(13);

    s.connect(root);

    return 0;
}

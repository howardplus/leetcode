/*
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 */
#include <iostream>
#include <stack>
#include <queue>
#include <unistd.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode *> parent;
    TreeNode *current;

    BSTIterator(TreeNode *root): current(root)
    {
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !parent.empty() || (current != NULL);
    }

    void goLeft()
    {
        while (current) {
            parent.push(current);
            current = current->left;
        }
    }

    /** @return the next smallest number */
    int next()
    {
        goLeft();

        current = parent.top();
        parent.pop();
        int val = current->val;
        current = current->right;

        return val;
    }
};

void DFS_Helper(TreeNode *n, stack<TreeNode *>& s)
{
    s.push(n);
    while (!s.empty()) {
        TreeNode *n1 = s.top();
        s.pop();
        if (n1->left) s.push(n1->left);
        if (n1->right) s.push(n1->right);
        cout << n1->val << endl;
    }
}

void DFS(TreeNode *root)
{
    stack<TreeNode *> s;
    DFS_Helper(root, s);
}

void BFS_Helper(TreeNode *n, queue<TreeNode *>& q)
{
    q.push(n);
    while (!q.empty()) {
        TreeNode *n1 = q.front();
        q.pop();
        if (n1->left) q.push(n1->left);
        if (n1->right) q.push(n1->right);
        cout << n1->val << endl;
    }
}

void BFS(TreeNode *root)
{
    queue<TreeNode *> q;
    BFS_Helper(root, q);
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{
    TreeNode *root = new TreeNode(24);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(28);
    root->right->right = new TreeNode(32);

    cout << "DFS:" << endl;
    DFS(root);

    cout << "BFS:" << endl;
    BFS(root);

    /*
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) {
        cout << i.next() << endl;
        sleep(1);
    }
    */
}

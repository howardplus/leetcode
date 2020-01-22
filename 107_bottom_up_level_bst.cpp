#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL)
            return vector<vector<int>>{};

		unordered_map<int, vector<int>> m;
		int level = traverse(root, 0, m);

		vector<vector<int>> result;
        for (int d=level; d>=0; d--) {
			auto v = m[d];
			result.push_back(v);
		}
		return result;
    }

	int traverse(TreeNode *n, int level, unordered_map<int, vector<int>>& m) {
		int max_level = level;
		if (m.find(level) == end(m)) {
			m[level] = vector<int>(1, n->val);
		} else {
			m[level].push_back(n->val);
		}

		if (n->left) {
			int l = traverse(n->left, level+1, m);
			max_level = max(l, max_level);
		}

		if (n->right) {
			int l = traverse(n->right, level+1, m);
			max_level = max(l, max_level);
		}

		return max_level;
	}
};

int main() {
    TreeNode *t = new TreeNode{3}; 
    t->left = new TreeNode{9};
    t->right = new TreeNode{20};
    t->right->left = new TreeNode{15};
    t->right->right = new TreeNode{7};

    Solution s;
    auto r1 = s.levelOrderBottom(t);

    for (auto l: r1) {
        for (auto i : l) {
            cout << i << ",";
        }
        cout << endl;
    }
    
}

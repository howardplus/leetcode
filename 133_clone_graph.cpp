/*
 * https://leetcode.com/problems/clone-graph/description/
 *
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *traverse(UndirectedGraphNode *n, unordered_map<UndirectedGraphNode*, int>&m) {
        if (m.find(n) == end(m)) {
            UndirectedGraphNode *n1 = new UndirectedGraphNode(n->label);
            for (auto i : n->neighbors) {
                n1->neighbors.push_back(traverse(i, m));
            } 
        } else {
            return m.find(n);
        }
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> m; 
        if (node == nullptr)
            return nullptr;
        return traverse(node, m); 
    }
};

int main()
{
    return 0;
}

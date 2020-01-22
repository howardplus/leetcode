/*
 * https://leetcode.com/problems/clone-graph/description/
 *
 * Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraphHelper(Node* n, unordered_map<Node*, Node*>& m) {
        /* skip traversed node */
        Node *clone;
        if (m.find(n) == end(m)) {
            clone = new Node(n->val);
            m[n] = clone;
        } else
            return m[n];

        for (auto i : n->neighbors) {
            clone->neighbors.push_back(cloneGraphHelper(i, m)); 
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return node;

        unordered_map<Node*, Node*> m;
        return cloneGraphHelper(node, m);         
    }
};

int main()
{
    return 0;
}

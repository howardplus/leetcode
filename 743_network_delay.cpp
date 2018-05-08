/*
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * There are N network nodes, labelled 1 to N.
 *
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 *
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 *
 * Note:
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {
    int index;
    int dist;
    Vertex(int i, int d): index(i), dist(d) {}

    friend ostream& operator<<(ostream& out, const Vertex& v)
    {
        out << v.index << "(" << v.dist << ")";
        return out;
    }
};

struct CompareVertex {
    bool operator()(const Vertex& l, const Vertex& r) const
    {
        return l.dist > r.dist; 
    }
};

using pqueue = priority_queue<Vertex, vector<Vertex>, CompareVertex>;

class Solution {
public:
    auto findShortestPath(vector<vector<int>>& times, int N, int K) -> vector<int>
    {
        pqueue pq;
        
        vector<int> paths(N+1, 0);

        pq.push(Vertex{K, 0});
        paths[K] = 0;

        while (!pq.empty()) {
            int u = pq.top().dist;
            pq.pop();

            // adjacents
            for (auto t: times) {
//                if (t[0] == K) {
                    auto v = t[1];
                    auto d = t[2];

                    if (paths[v] > paths[u] + d) {
                        paths[v] = paths[u] + d;
                        pq.push(Vertex{v, paths[v]});
                    }
 //}
            }
        }

        return paths;
    }

    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        /* from K, find all shortest path to every other nodes */
        auto paths = findShortestPath(times, N, K);
        auto max_path = 0;
        for (auto i=1; i<paths.size(); i++) {
            if (i == K) continue;
            max_path = max(paths[i], max_path);
        }
        return max_path;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> times;
    times.push_back(vector<int>{1,4,30});
    times.push_back(vector<int>{1,3,10});
    times.push_back(vector<int>{1,2,50});
    times.push_back(vector<int>{2,4,70});

    cout << s.networkDelayTime(times, 4, 1) << endl;

    return 0;
}

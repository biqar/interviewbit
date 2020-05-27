//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    map<UndirectedGraphNode*, UndirectedGraphNode *> mp;
    queue<UndirectedGraphNode*> Q;

    UndirectedGraphNode* tmp = new UndirectedGraphNode(node->label);
    mp[node] = tmp;
    Q.push(node);

    while(!Q.empty()) {
        UndirectedGraphNode* u = Q.front();
        Q.pop();

        vector<UndirectedGraphNode *> neighborList = u->neighbors;
        int sz = neighborList.size();

        for(int i=0; i<sz; i+=1) {
            UndirectedGraphNode* v = neighborList[i];

            if(mp.find(v) == mp.end()) {
                tmp = new UndirectedGraphNode(v->label);
                mp[v] = tmp;
                Q.push(v);
            }
            mp[u]->neighbors.push_back(mp[v]);
        }
    }

    return mp[node];
}

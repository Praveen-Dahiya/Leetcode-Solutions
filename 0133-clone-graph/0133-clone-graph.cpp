/*
// Definition for a Node.
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
*/

class Solution {
public:
     unordered_map<Node* ,Node*> cloneMp;
    Node* cloneGraph(Node* node) {
      
        if(node==NULL){
            return NULL;
        }
        if (cloneMp.find(node) == cloneMp.end()) {
            cloneMp[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                cloneMp[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return cloneMp[node];
    }
};
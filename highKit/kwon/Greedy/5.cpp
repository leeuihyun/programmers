#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chk[100] = { 0, };

int getParent(int node) {
    if(chk[node] == node) return node;
    return getParent(chk[node]);
}

void connect(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if(node1 < node2)
        chk[node2] = node1;
    else
        chk[node1] = node2;
}

bool isCycle(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if(node1 == node2)
        return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    struct {
        bool operator()(vector<int> a, vector<int> b) {
            return a[2] < b[2];
        }
    } compare;
    
    sort(costs.begin(), costs.end(), compare);
    
    for(int i = 0; i < n; i++)
        chk[i] = i;
    
    for(int i = 0; i < costs.size(); i++) {
        if(!isCycle(costs[i][0], costs[i][1])) {
            answer += costs[i][2];
            connect(costs[i][0], costs[i][1]);
        }
    }
    
    return answer;
}
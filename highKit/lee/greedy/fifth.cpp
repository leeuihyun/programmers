#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int path[101];
bool compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}
int go(int node)
{
    if (path[node] == node)
        return node;
    else
    {
        return path[node] = go(path[node]);
    }
}
int solution(int n, vector<vector<int> > costs)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        path[i] = i;
    }
    sort(costs.begin(), costs.end(), compare);
    for (int i = 0; i < costs.size(); i++)
    {
        int start = go(costs[i][0]);
        int end = go(costs[i][1]);
        int cost = costs[i][2];

        if (start != end)
        {
            answer += cost;
            path[end] = start;
        }
    }
    return answer;
}
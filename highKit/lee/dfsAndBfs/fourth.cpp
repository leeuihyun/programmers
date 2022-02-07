#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool visited[10001];
vector<string> answer;
vector<string> tmp;

bool dfs(string start, vector<vector<string> > tickets)
{
    if (tmp.size() == tickets.size() + 1)
    {
        answer = tmp;
        return true;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (!visited[i] && tickets[i][0] == start)
        {
            visited[i] = true;
            tmp.push_back(tickets[i][1]);
            if (dfs(tickets[i][1], tickets))
            {
                return true;
            }
            visited[i] = false;
            tmp.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string> > tickets)
{
    sort(tickets.begin(), tickets.end());
    tmp.push_back("ICN");
    dfs("ICN", tickets);

    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

bool visited[50];

bool chk(string s, string c)
{
    int cnt = 0;
    if (s == c)
        return false;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != c[i])
            cnt++;
    if (cnt == 1)
        return true;
    return false;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0, n = words.size();

    if (find(words.begin(), words.end(), target) == words.end())
        return answer;

    queue<tuple<string, int, int>> q;
    for (int i = 0; i < n; i++)
        if (chk(begin, words[i]))
            q.push({words[i], i, 1});

    while (!q.empty())
    {
        string s = get<0>(q.front());
        int index = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();

        if (s == target)
        {
            answer = cnt;
            break;
        }

        visited[index] = true;

        for (int i = 0; i < n; i++)
            if (chk(s, words[i]))
                q.push({words[i], i, cnt + 1});
    }

    return answer;
}
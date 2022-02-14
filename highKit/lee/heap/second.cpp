#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
int solution(vector<vector<int> > jobs)
{
    for (int i = 0; i < jobs.size(); i++)
    {
        pq.push({jobs[i][0], jobs[i][1]});
    }
    int current = 0;
    int time = 0;

    while (!pq.empty())
    {
        if (current >= pq.top().first)
        {
            time += (current - pq.top().first + pq.top().second);
            current += pq.top().second;
            pq.pop();
        }
        else
        {
            vector<pair<int, int> > tmp;
            tmp.push_back({pq.top().first, pq.top().second});
            pq.pop();
            while (!pq.empty() && pq.top().first > current)
            {
                tmp.push_back({pq.top().first, pq.top().second});
                pq.pop();
            }
            if (!pq.empty())
            {
                time += (current - pq.top().first + pq.top().second);
                current += pq.top().second;
                pq.pop();
            }
            else
                current++;

            for (int i = 0; i < tmp.size(); i++)
            {
                pq.push({tmp[i].first, tmp[i].second});
            }
        }
    }

    return time / jobs.size();
}
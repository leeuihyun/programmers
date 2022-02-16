#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> dq;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    for (int i = 0; i < people.size(); i++)
        dq.push_back(people[i]);
    while (!dq.empty())
    {
        if (dq.size() == 1)
        {
            answer += 1;
            dq.pop_front();
            break;
        }
        if (dq.front() + dq.back() <= limit)
        {
            answer += 1;
            dq.pop_front();
            dq.pop_back();
        }
        else
        {
            answer += 1;
            dq.pop_front();
        }
    }
    return answer;
}
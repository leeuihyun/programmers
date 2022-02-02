#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N, M;
multimap<string, int> m;
vector<string> part, comp;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    for (int i = 0; i < participant.size(); i++)
        m.insert({participant[i], i});

    for (int i = 0; i < completion.size(); i++)
        if (m.find(completion[i]) != m.end())
            m.erase(m.find(completion[i]));

    if (!m.empty())
        answer = m.begin()->first;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string tmp;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        part.push_back(tmp);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        comp.push_back(tmp);
    }

    cout << solution(part, comp);

    return 0;
}
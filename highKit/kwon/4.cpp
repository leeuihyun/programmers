#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    unordered_map<string, int> um;
    vector<tuple<string, int, int>> gp;

    for (int i = 0; i < genres.size(); i++)
    {
        um[genres[i]] += plays[i];
        gp.push_back({genres[i], plays[i], i});
    }

    vector<pair<string, int>> v(um.begin(), um.end());

    struct
    {
        bool operator()(pair<string, int> a, pair<string, int> b)
        {
            return a.second > b.second;
        }

        bool operator()(tuple<string, int, int> a, tuple<string, int, int> b)
        {
            return get<1>(a) > get<1>(b);
        }
    } compare;

    sort(v.begin(), v.end(), compare);
    sort(gp.begin(), gp.end(), compare);

    for (auto i : v)
    {
        int cnt = 0;
        for (int j = 0; j < gp.size(); j++)
        {
            if (get<0>(gp[j]) == i.first)
            {
                cnt++;
                if (cnt > 2)
                    break;
                answer.push_back(get<2>(gp[j]));
            }
        }
    }

    return answer;
}

int main()
{
    int N;

    cin >> N;

    vector<string> s;
    vector<int> i;

    for (int j = 0; j < N; j++)
    {
        string a;
        int b;
        cin >> a >> b;
        s.push_back(a);
        i.push_back(b);
    }

    vector<int> result = solution(s, i);

    for (auto j : result)
        cout << j << " ";

    return 0;
}
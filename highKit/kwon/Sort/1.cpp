#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (auto i : commands)
    {
        vector<int> res;
        for (int j = i[0] - 1; j < i[1]; j++)
        {
            res.push_back(array[j]);
        }
        sort(res.begin(), res.end());
        answer.push_back(res[i[2] - 1]);
    }

    return answer;
}

int main()
{
    int N, M;

    cin >> N >> M;
    vector<int> arr;
    vector<vector<int>> cmd;

    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    for (int i = 0; i < M; i++)
    {
        vector<int> v;
        for (int j = 0; j < 3; j++)
        {
            int c;
            cin >> c;
            v.push_back(c);
        }
        cmd.push_back(v);
    }

    vector<int> res = solution(arr, cmd);

    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}
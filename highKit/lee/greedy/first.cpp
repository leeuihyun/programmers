#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int arr[31];
int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 0; i <= 30; i++)
    {
        arr[i] = 1;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        arr[reserve[i]] += 1;
    }
    for (int i = 0; i < lost.size(); i++)
    {
        arr[lost[i]] -= 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > 1)
        {
            if (arr[i - 1] == 0)
            {
                arr[i] -= 1;
                arr[i - 1] += 1;
                continue;
            }
            else if (arr[i + 1] == 0)
            {
                arr[i] -= 1;
                arr[i + 1] += 1;
                continue;
            }
            else
                continue;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] >= 1)
            answer += 1;
    }
    return answer;
}
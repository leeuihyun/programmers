#include <string>
#include <vector>

using namespace std;
int answer = 0;

int dp[101][101] = {
    0,
};
bool visited[101][101] = {
    false,
};

int solution(int m, int n, vector<vector<int> > puddles)
{
    for (int i = 0; i < puddles.size(); i++)
    {
        visited[puddles[i][1]][puddles[i][0]] = true;
    }
    dp[1][1] = 1; //n,m
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j])
            {
                dp[i][j] += (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
            }
        }
    }
    answer = dp[n][m];
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> d(n + 1, vector<bool>(n + 1, false));
    vector<int> cnt(n + 1, 0);
    
    for(int i = 0; i < results.size(); i++)
        d[results[i][0]][results[i][1]] = true;
        
    for(int m = 1; m <= n; m++)
        for(int s = 1; s <= n; s++)
            for(int e = 1; e <= n; e++)
                if(d[s][m] && d[m][e])
                    d[s][e] = true;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(d[i][j]) {
                cnt[i]++;
                cnt[j]++;
            }
    
    for(int i = 1; i <= n; i++)
        if(cnt[i] == n - 1)
            answer++;
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0, n = money.size();
    
    vector<int> dp_1(n, 0), dp_2(n, 0);
    
    dp_1[0] = money[0];
    dp_1[1] = 0;
    dp_1[2] = money[0] + money[2];
    dp_2[0] = 0;
    dp_2[1] = money[1];
    
    for(int i = 3; i < n - 1; i++)
        dp_1[i] = max({dp_1[i - 1], dp_1[i - 2] + money[i], dp_1[i - 3] + money[i]});
    for(int i = 2; i < n; i++)
        dp_2[i] = max(dp_2[i - 1], dp_2[i - 2] + money[i]);
    
    answer = max(dp_1[n - 2], dp_2[n - 1]);
    
    return answer;
}
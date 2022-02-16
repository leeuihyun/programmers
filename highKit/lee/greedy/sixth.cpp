#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{ // 진입시간 작은것 정렬
    return a[1] < b[1];
}
int solution(vector<vector<int> > routes)
{
    int answer = 0;
    sort(routes.begin(), routes.end(), compare);
    int i = 0;
    while (i < routes.size())
    {
        int start = routes[i][1];
        i++;
        while (i < routes.size() && routes[i][0] <= start)
        {
            i++;
        }
        answer += 1;
    }
    return answer;
}
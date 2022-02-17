#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string ans = "";
    int idx = 0;
    int cnt = 0;

    while (idx < number.size() - 1 && cnt < k)
    {
        if (cnt == k)
            break;
        if (number[idx] < number[idx + 1])
        {
            number.erase(number.begin() + idx);
            cnt += 1;
            idx = 0;
            continue;
        }
        idx += 1;
    }
    idx = number.size() - 1;
    while (idx > 0 && cnt < k)
    {
        if (cnt == k)
            break;
        if (number[idx] < number[idx - 1])
        {
            number.erase(number.begin() + idx);
            cnt += 1;
            idx = number.size() - 1;
            continue;
        }
        idx -= 1;
    }
    for (int i = 0; i < number.size(); i++)
    {
        ans += number[i];
    }
    return ans;
}
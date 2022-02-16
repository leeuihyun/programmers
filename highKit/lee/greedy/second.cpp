#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int len = name.length();
    int move = len - 1;
    for (int i = 0; i < name.length(); i++)
    {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    int next = 0;
    for (int i = 0; i < name.length(); i++)
    {
        next = i + 1;
        while (name[next] == 'A' && next < name.length())
        {
            next += 1;
        }
        move = min(move, i + len - next + min(i, len - next));
    }

    return answer + move;
}
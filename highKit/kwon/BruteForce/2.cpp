#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrimeNum(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    vector<bool> visited(10000000);

    sort(numbers.begin(), numbers.end(), greater<>());

    for (int k = 1; k <= numbers.size(); k++)
    {
        vector<int> tmp;
        for (int i = 0; i < k; i++)
            tmp.push_back(1);
        for (int i = 0; i < numbers.size() - k; i++)
            tmp.push_back(0);
        sort(tmp.begin(), tmp.end(), greater<>());

        do
        {
            string s = "";
            for (int i = 0; i < tmp.size(); i++)
                if (tmp[i] == 1)
                    s += numbers[i];
            sort(s.begin(), s.end(), greater<>());
            int cmp = stoi(s);
            if (!visited[cmp])
            {
                do {
                    int n = stoi(s);
                    if(!visited[n] && isPrimeNum(n)) {
                        visited[n] = true;
                        answer++;
                    }
                } while(prev_permutation(s.begin(), s.end()));
            }
        } while (prev_permutation(tmp.begin(), tmp.end()));
    }

    return answer;
}

int main()
{
    string s;

    cin >> s;

    cout << solution(s);

    return 0;
}
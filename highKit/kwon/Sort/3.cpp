#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0, cnt = 0, i;
    int n = citations.size();
    vector<int> res;
    
    sort(citations.begin(), citations.end());
    if(citations[n - 1] == 0)
        return answer;
    
    for(i = n - 1; i >= 0; i--) {
        if(citations[i] < cnt)
            break;
        cnt++;
    }
    if(cnt > citations[i + 1])
        cnt = citations[i + 1];
    
    answer = cnt;
    
    return answer;
}

int main()
{
    int N;
    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        v.push_back(data);
    }

    cout << solution(v);
}
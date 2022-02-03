#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> clothes_v;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> um;

    for (auto i : clothes)
        um[i[1]]++;

    for (auto i : um)
        answer *= i.second + 1;

    return answer - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;
    string type_s, name_s;

    for (int i = 0; i < N; i++)
    {
        cin >> type_s >> name_s;
        clothes_v.push_back({type_s, name_s});
    }

    cout << solution(clothes_v);
}
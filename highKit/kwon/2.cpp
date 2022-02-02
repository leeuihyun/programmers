#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    string s;
    int i, j;

    sort(phone_book.begin(), phone_book.end());

    for(i = 0; i < phone_book.size() - 1; i++)
        if(phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
            answer = false;
            return answer;
        }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<string> phoneNumber;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        phoneNumber.push_back(s);
    }

    bool result = solution(phoneNumber);

    cout << result;

    return 0;
}
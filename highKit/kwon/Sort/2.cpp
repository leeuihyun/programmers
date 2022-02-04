#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    int sum = 0;
    for(auto i : numbers)
        sum += i;
    if(sum == 0)
        return "0";
    
    vector<string> v;
    
    for(int i = 0; i < numbers.size(); i++) {
        string s = "";
        s = to_string(numbers[i]);
        v.push_back(s);
    }
    
    struct {
        bool operator()(string a, string b) {
            return a + b > b + a;
        }
    } compare;
    
    sort(v.begin(), v.end(), compare);
    
    for(auto i : v)
        answer += i;
    
    return answer;
}

int main() {
    int N;

    cin >> N;
    vector<int> v;

    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    cout << solution(v);
}
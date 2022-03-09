#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
	int at[2998] = { 0, };
	sort(numbers.begin(), numbers.end());
	//에라토스테네스의 체
	for (int i = 2; i < 2998; i++) {
		at[i] = i;
	}
	for (int i = 2; i < 2998; i++) {
		if (at[i] == 0) continue;
		for (int j = i * 2; j < 2998; j+=i) {
			at[j] = 0;
		}
	}
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			for (int k = j + 1; k < numbers.size(); k++) {
				int num = numbers[i] + numbers[j] + numbers[k];
				if (at[num] != 0) {
					answer += 1;
				}
			}
		}
	}
	return answer;
}
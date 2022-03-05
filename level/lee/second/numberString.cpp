#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer="";
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c >= 'a' && c <= 'z') {
			if (c == 'z') { // zero일 때 , '0'으로 변환 zero의 길이만큼 i를 추가할것.
				answer += '0';
				i += 3;
			}
			else if (c == 'o') {
				answer += '1';
				i += 2;
			}
			else if (c == 't') {
				if (s[i + 1] == 'w') {
					answer += '2';
					i += 2;
				}
				else {
					answer += '3';
					i += 4;
				}
			}
			else if (c == 'f') {
				if (s[i + 1] == 'o') {
					answer += '4';
					i += 3;
				}
				else {
					answer += '5';
					i += 3;
				}
			}
			else if (c == 's') {
				if (s[i + 1] == 'i') {
					answer += '6';
					i += 2;
				}
				else {
					answer += '7';
					i += 4;
				}
			}
			else if (c == 'e') {
				answer += '8';
				i += 4;
			}
			else {
				answer += '9';
				i += 3;
			}
		}
		else {
			answer += c;
		}
	}
	return stoi(answer);
}
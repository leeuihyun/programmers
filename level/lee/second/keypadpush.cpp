#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
	int left_hand = 10;
	int right_hand = 12;
	for (int i = 0; i < numbers.size(); i++) {
		int num = numbers[i];
		if (num == 1 || num == 4 || num == 7) {
			answer += "L";
			left_hand = num;
		}
		else if (num == 3 || num == 6 || num == 9) {
			answer += "R";
			right_hand = num;
		}
		else {
			if (num == 0) {
				num = 11;
			}
			int count_left = 0;
			int count_right = 0;
			if (left_hand > num) {
				for (int i = left_hand-1; i >= num;i--) {
					count_left++;
				}
			}
			else if (left_hand < num) {
				for (int i = left_hand; i < num; i++) {
					count_left++;
				}
			}

			if (right_hand > num) {
				for (int i = right_hand-1; i >= num; i--) {
					count_right++;
				}
			}
			else if (right_hand < num) {
				for (int i = right_hand; i < num; i++) {
					count_right++;
				}
			}

			if ((count_left / 3 + count_left % 3) < (count_right / 3 + count_right % 3)) {
				answer += "L";
				left_hand = num;
			}
			else if ((count_left / 3 + count_left % 3) > (count_right / 3 + count_right % 3)) {
				answer += "R";
				right_hand = num;
			}
			else{
				if (hand.compare("left") == 0) {
					answer += "L";
					left_hand = num;
				}
				else {
					answer += "R";
					right_hand = num;
				}
			}
		}
	}
	return answer;
}
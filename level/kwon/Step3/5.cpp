#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
    
	return a;
}

long long solution(int w,int h) {
    long long answer = (long long) w * h;
    
    int x = gcd(w, h);
    
    int width = w / x;
    int height = h / x;
    
    answer = answer - (width + height - 1) * x;
    
    return answer;
}
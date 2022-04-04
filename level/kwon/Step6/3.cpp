#include <string>
#include <cctype>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    
    bool rule1 = false, rule2 = false;
    bool chk[26] = { false, };
    char word1, word2;
    string words = "";
    
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ')
            return "invalid";
        if(rule1 && rule2) {
            if(isupper(sentence[i])) {
                if(isupper(sentence[i + 1])) {
                    return "invalid";    // 규칙 1, 2에서 연속해서 대문자가 나온 경우
                }
                else {
                    if(sentence[i + 1] != word1 && sentence[i + 1] != word2) {
                        return "invalid";   // 규칙 1, 2에서 대문자 다음 소문자가 다른 단어인 경우
                    }
                    else if(sentence[i + 1] == word2) {
                        words += sentence[i];
                        answer = answer + words + " ";
                        words = "";
                        rule1 = false;
                        rule2 = false;
                        i++;
                    }
                    else {
                        words += sentence[i];
                    }
                }
            }
            else {
                if(islower(sentence[i + 1])) {
                    if(sentence[i + 1] == word1 || sentence[i + 1] == word2) {
                        return "invalid";   // 규칙 1, 2에서 연속해서 소문자가 나왔는데 단어 1, 2와 같은 경우
                    }
                    else {  // 다른 소문자가 나온 경우
                        if(words.length() >= 1)
                            answer = answer + words + " ";
                        words = "";
                        rule1 = false;
                        rule2 = false;
                    }
                }
                else {
                    if(sentence[i] == word2) {
                        if(words.length() >= 1)
                            answer = answer + words + " ";
                        words = "";
                        rule1 = false;
                        rule2 = false;
                    }
                }
            }
        }
        else if(rule1 && !rule2) {
            if(isupper(sentence[i])) {
                if(isupper(sentence[i + 1])) {
                    words += sentence[i];
                    answer = answer + words + " ";
                    words = "";
                    rule1 = false;
                }
                else {
                    if(sentence[i + 1] == word1)
                        words += sentence[i];
                    else {
                        words += sentence[i];
                        answer = answer + words + " ";
                        words = "";
                        rule1 = false;
                    }
                }
            }
            else {
                if(islower(sentence[i + 1])) {
                    return "invalid";
                }
                if(sentence[i] != word1) {
                    return "invalid";
                }
            }
        }
        else if(!rule1 && rule2) {
            if(isupper(sentence[i])) {
                if(isupper(sentence[i + 1]))
                    words += sentence[i];
                else {
                    if(sentence[i + 1] == word2) {
                        words += sentence[i];
                        answer = answer + words + " ";
                        words = "";
                        rule2 = false;
                        i++;
                    }
                    else {
                        words += sentence[i];
                        word1 = sentence[i + 1];
                        rule1 = true;
                        if(chk[word1 - 'a']) {
                            return "invalid";
                        }
                        chk[word1 - 'a'] = true;
                    }
                }
            }
            else {
                return "invalid";
            }
        }
        else {
            if(isupper(sentence[i])) {
                if(isupper(sentence[i + 1]) || i == sentence.length() - 1) {
                    words += sentence[i];
                }
                else if(islower(sentence[i + 1])){
                    if(islower(sentence[i + 3])) {
                        if(words.length() >= 1)
                            answer = answer + words + " ";
                        if(sentence[i + 1] == sentence[i + 3]) {
                            words = sentence[i];
                            rule1 = true;
                            word1 = sentence[i + 1];
                            if(chk[word1 - 'a']) {
                                return "invalid";
                            }
                            chk[word1 - 'a'] = true;
                        }
                        else {
                            words = "";
                            words += sentence[i];
                        }
                    }
                    else {
                        words = sentence[i];
                        rule1 = true;
                        word1 = sentence[i + 1];
                        if(chk[word1 - 'a'])
                            return "invalid";
                    }
                }
            }
            else {
                if(isupper(sentence[i + 1])) {
                    if(words.length() >= 1)
                        answer = answer + words + " ";
                    words = "";
                    rule2 = true;
                    word2 = sentence[i];
                    if(chk[word2 - 'a']) {
                        return "invalid";
                    }
                    chk[word2 - 'a'] = true;
                }
                else {
                    return "invalid";
                }
            }
        }
    }
    answer = answer + words;
    
    if(answer[0] == ' ')
        answer.erase(0, 1);
    if(answer[answer.length() - 1] == ' ')
        answer.erase(answer.length() - 1, 1);
    for(int i = 0; i < answer.length();) {
        if(answer[i] == ' ' && answer[i + 1] == ' ')
            answer.erase(i, 1);
        else
            i++;
    }
    
    return answer;
}

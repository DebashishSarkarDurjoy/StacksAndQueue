#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string msg) {
    stack<char> s;

    for (auto ch : msg) {
        switch(ch) {
            case '(':
            case '{':
            case '[': s.push(ch);
                      break;
            case ')': if (!s.empty() && s.top() == '(') {
                        s.pop();
                    }
                    else {
                        return false;
                    }
                    break;
            case '}': if (!s.empty() && s.top() == '{') {
                        s.pop();
                    }
                    else {
                        return false;
                    }
                    break;
            case ']': if (!s.empty() && s.top() == '[') {
                        s.pop();
                    }
                    else {
                        return false;
                    }
                    break;
            default: continue;
        }
    }


    if (s.empty()) {
        return true;
    }

    return false;
}

int main(void) {
    string msg = "(a+b) * {C}";

    if (isBalanced(msg) == true) {
        cout << "Balanced!";
    }
    else {
        cout << "Not Balanced";
    }

    return 0;
}

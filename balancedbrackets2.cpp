#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string input) {
    stack<char> s;

    for (char c : input) {

        switch(c) {
        case '(':
        case '{':
        case '[': s.push(c);
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

        }
    }
    return true;
}

int main(void) {
    string input = "((a+b)[] - c)";
    if (isBalanced(input)) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string input) {
    stack<char> s;

    for (char c : input) {
        if ( c == '(' || c == '{' || c == '[')  {
            s.push(c);

        }

        else if ( c == ')') {
            if (s.top() == '(') s.pop();
            else return false;
        }


        else if ( c == '}') {
            if (s.top() == '{') s.pop();
            else return false;
        }


        else if ( c == ']') {
            if (s.top() == '[') s.pop();
            else return false;
        }

    }

    return true;
}

int main(void) {
    string input = "((a+b){[}] - c)";
    if (isBalanced(input)) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}

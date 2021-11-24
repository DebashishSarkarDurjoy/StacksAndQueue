#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string simplifyPath(string path) {
    istringstream iss(path);
    vector<string> tokens;

    // filter to get the tokens
    string token;
    while(getline(iss, token, '/')) {
        if (token == "." || token == "") {
            continue;
        }
        tokens.push_back(token);
    }

    for (string token : tokens) {
        cout << token << ", ";
    }
    cout << endl;

    // Handling
    vector<string> stack;
    if (path[0] == '/') {
        stack.push_back(""); //if using abs path
    }

    for (auto token : tokens) {
        if (token == "..") {
            //if relative path
            if (stack.size() == 0 || stack[stack.size() - 1] == "..") {
                stack.push_back("..");
            }
            //otherwise
            else if (stack[stack.size() - 1] != "") {
                stack.pop_back();
            }
        }
        //any other token
        else {
            stack.push_back(token);
        }
    }

    //single element
    if (stack.size() == 1 && stack[0] == "") {
        return "/";
    }

    //combine all elements in the stack to get the answer
    int i = 0;
    ostringstream oss;
    for (auto token : stack) {
        if (i != 0) {
            oss << "/";
        }
        i++;
        oss << token;
    }

    return oss.str();
}

int main(void) {
    string path = "/../x/y/../z/././w/a///../../c/./";
    cout << simplifyPath(path) << endl;

    return 0;
}

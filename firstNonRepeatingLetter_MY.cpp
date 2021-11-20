#include <iostream>
#include <queue>

using namespace std;


int main(void) {
    queue<char> q;
    int freq[27] = {0};

    char ch = ' ';
    do {
        cin >> ch;
        freq[ch - 'a']++;

        if (freq[ch - 'a'] <= 1) {
            q.push(ch);
        }
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        if (q.empty()) {
            cout << "-1" << endl;
        }
        else {
            cout << "-->" << q.front() << endl;
        }


    } while (ch != '.');


    return 0;
}

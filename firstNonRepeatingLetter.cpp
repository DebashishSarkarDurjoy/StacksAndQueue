#include <iostream>
#include <queue>

using namespace std;


int main(void) {
    queue<char> q;
    int freq[27] = {0};

    char ch = ' ';
    do {
        cin >> ch;

        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty()) {
            int idx = ch - 'a';
            if (freq[idx] > 1) {
                q.pop();
            }
            else {
                cout << "-->" << q.front() << endl;
                break;
            }
        }
        if (q.empty()) {
            cout << "-1" << endl;
        }

    } while (ch != '.');


    return 0;
}

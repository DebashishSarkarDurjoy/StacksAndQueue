#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void maxSubArray(vector<int> a, int k) {
    int n = a.size();
    deque<int> Q(k);

    int i = 0;
    for (i = 0; i < k; i++) {
        while (!Q.empty() && a[i] > a[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    for (; i < n; i++) {
        cout << a[Q.front()] << " ";

        while (!Q.empty() && Q.front() <= i-k) {
            Q.pop_front();
        }

        while (!Q.empty() && a[i] > a[Q.back()]) {
            Q.pop_back();
        }

        Q.push_back(i);
    }

    cout << a[Q.front()] << endl;
}

int main(void) {
    vector<int> numbers{1,2,3,1,4,5,2,3,5};
    maxSubArray(numbers, 3);

    return 0;
}

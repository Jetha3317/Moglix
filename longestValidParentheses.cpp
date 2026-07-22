// Moglix
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int longestValidParentheses(std::string s) {
        int n = s.size();
        int arr[n + 1] = {0};
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == ')') {
                if (s[i - 2] == '(') {
                    arr[i] = arr[i - 2] + 2;
                } else {
                    int j = i - arr[i - 1] - 1;
                    if (j && s[j - 1] == '(') {
                        arr[i] = arr[i - 1] + 2 + arr[j - 1];
                    }
                }
            }
        }
        return *max_element(arr, arr + n + 1);
    }
};

int main() {
    Solution solver;
    
    int t;
    cout<< "Enter no of testcase:";
    cin>>t;
    vector<string> S(t);
    int i = 0;
     for (int i = 0; i < t; ++i) {
        cin >> S[i];
    }
    
    cout << "Length of longestValidParentheses:" << endl;
    for (int i = 0; i < t; ++i) {
        int s = solver.longestValidParentheses(S[i]);
        cout << s << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//time: O(n)
//memory: O(n)

vector<int> sol(vector<int> & mas, int k) {
    vector<int> res;
    unordered_set<int> digits;
    for(int i = 0; i < mas.size(); i++) {
        if(digits.find(k - mas[i]) != digits.end()) {
            res = {mas[i], k - mas[i]};
            return res;
        } else {
            digits.insert(mas[i]);
        }
    }
    return res;
}

int main() {
    vector<int> mas = {1,6,4,8,2,5,7,-2,-5,-8,-3,-4,-6};
    int k = 7;
    sort(mas.begin(), mas.end());
    vector<int> res = sol(mas, k);
    if(res.size()) cout << res[0] << " : " << res[1];
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//time: O(n^2)
//memory: O(1)

vector<int> sol(vector<int> & mas, int k) {
    vector<int> res;
    for(int i = 0; i < mas.size()-1; i++) {
        for(int j = i+1; j < mas.size(); j++) {
            if(mas[i] + mas[j] == k) {
                res = {mas[i], mas[j]};
                return res;
            }
        }
    }
    return res;
}

int main() {
    vector<int> mas = {1,6,4,8,2,5,7,-2,-5,-8,-3,-4,-6};
    int k = 100;
    sort(mas.begin(), mas.end());
    vector<int> res = sol(mas, k);
    if(res.size()) cout << res[0] << " : " << res[1];
    return 0;
}
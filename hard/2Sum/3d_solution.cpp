#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//time: O(n)
//memory: O(1)

vector<int> sol(vector<int> & mas, int k) {
    vector<int> res;
    int left = 0;
    int right = mas.size()-1;
    int v = 100000000;
    while(left < right) {
        if(mas[left] + mas[right] == k) {
            res = {mas[left], mas[right]};
            return res;
        } else if(mas[left] + mas[right] > k) {
            if(k - mas[left] + mas[right] < v) {
                res = {mas[left], mas[right]};
                v = k - mas[left] + mas[right];
            }
            right--;
        } else {
            if(mas[left] + mas[right] - k < v) {
                res = {mas[left], mas[right]};
                v = k - mas[left] + mas[right];
            }
            left++;
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
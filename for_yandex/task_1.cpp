#include <iostream>
#include <vector>
#include <string>

using namespace std;

int func(int a) {
    // cout << "here-1\n";
    int k = 0;
    while(a != 1) {
        a >>= 1;
        k++;
    }
    // cout << "here-2\n";
    return k;
}

int main() {
    int w = 0;
    int n, a, b;
    vector<string> mas = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " "};
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        b = abs(a-w);
        cout << mas[func(b)];
        w = a;
        // cout << "here-3\n";
    }

    return 0;
}
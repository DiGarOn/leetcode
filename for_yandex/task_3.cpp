#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<long long> split_to_prime(long long a) {
    vector<long long> mas = {1};
    long long k = 2;
    while(a > 1) {
        if(k * k > a) break;
        if(a % k == 0) {
            mas.push_back(k);
            a /= k;
        } else {
            k++;
        }
    }
    if(a != 1 && a != 0) mas.push_back(a);
    return mas;
}

long long find_max_nod(long long a, long long b) {
    vector<long long> a_prime = split_to_prime(a);
    vector<long long> b_prime = split_to_prime(b);


    if(a_prime.size() == 1) return b_prime.back();
    if(b_prime.size() == 1) return a_prime.back();

    long long max_nod = 1;
    int k_a = 0;
    int k_b = 0;

    while(1) {
        if(a_prime.size() == k_a || b_prime.size() == k_b) break;
        if(a_prime[k_a] == b_prime[k_b]) {
            max_nod *= a_prime[k_a];
            a_prime.erase(a_prime.begin() + k_a);
            b_prime.erase(b_prime.begin() + k_b);
        } else {
            if(a_prime[k_a] < b_prime[k_b]) {
                if(a_prime.size() > k_a+1) k_a++;
                else break;
            } else {
                if(b_prime.size() > k_b+1) k_b++;
                else break;
            }
        }
    }
    if(a_prime.size() == 0) {
        if(b_prime.size() == 0) {
            return max_nod;
        } else return max_nod * b_prime.back();
    } else {
        if(b_prime.size() == 0) {
            return max_nod * a_prime.back();
        } else return max_nod * max(a_prime.back(), b_prime.back());
    }
    
}

int main() {
    int t;
    long long a, b;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << find_max_nod(a, b) << endl;
    }

    return 0;
}
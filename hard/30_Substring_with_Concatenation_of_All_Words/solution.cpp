#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> create(const vector<string>& mas) {
        vector<string> res;
        for(int i = 0; i < mas.size(); i++) {
            res.push_back(mas[i]);
        }
        return res;
    }
    
    bool Is_it(string s, unordered_multiset<string> w, int l) {
//cout << "!!stroka!!  " << s << "\n";
        //cout << "\n";
        for(int i = 0; i < s.length(); i+= l) {
            string a = s.substr(i, l);
            
            //cout << a << " ";
            if(w.find(a) != w.end()) {
                w.erase(w.find(a));
                
            } else {
                return false;
            }
        }
        //cout << "\n" << "!!res!! " << s << "\n";
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int l = words[0].length();
        vector<int> res;
        unordered_multiset<string> word;
        for(int i = 0; i < words.size(); i++) {
            word.insert(words[i]);
        }
        vector<string> val = create(words);
        for(int i = 0; i < s.length()-l*words.size()+1; i+= 1) {
            string a = s.substr(i, l*words.size());
            if(Is_it(a, word, l)) {
                res.push_back(i);
            }
            if(s.length() - i < l*words.size()) break;
            /*
            if(find(val.begin(), val.end(), a) != val.end()){
                cout << "here " << val.size() << "\n";
		        val.erase(find(val.begin(), val.end(), a));
                cout << '\n';
                if(val.size() == 0) {
                    res.push_back(i-l*(words.size()-1));
                    i -= l*(words.size()-1);
                    val = create(words);
	            }
            } else {
                if(find(words.begin(), words.end(), a) != words.end()){
                    i -= l* (words.size()-val.size());
                    val = create(words);
                }
            }
            */
        }
        return res;
    }
};
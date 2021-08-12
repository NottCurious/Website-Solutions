#include "isogram.h"
#include "vector"
#include "iostream"
namespace isogram {
    bool is_isogram(string str) {
        vector<char> vc;
        for(char c : str) {
            if(check_in_vector(vc, c)) {
                return false;
            }
            else {
                vc.push_back(c);
            }
        }

        return true;
    }

    bool check_in_vector(vector<char> vc, char c) {
        for(char my_c : vc) {
            if(c == my_c) {
                return true;
            }
        }

        return false;
    }
}  // namespace isogram

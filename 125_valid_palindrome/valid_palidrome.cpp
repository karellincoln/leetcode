class Solution {
public:
    bool equal(char a, char b){
        if(a == b || (abs(a - b) == 'a' - 'A' && !(a >= '0' && a <= '9') && !(b >= '0' && b <= '9'))) return true;
        return false;
    }

    bool isAlphanum(char c){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int first = 0;
        int last = s.size() - 1;
        bool is_pal = true;
        while(first < last){
            while(first < last && !isAlphanum(s[first])) ++first;
            while(first < last && !isAlphanum(s[last])) --last;
            if(!equal(s[first], s[last])) {
                is_pal = false;
                break;
            }
            ++first;
            --last;
        }

        return is_pal;
    }
};
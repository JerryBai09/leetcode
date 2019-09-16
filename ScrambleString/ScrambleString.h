#include <string>
#include <algorithm>

class Solution {
public:
    bool isScramble(std::string s1, std::string s2) {
      // End condition1
      if (s1 == s2) return true;

      //End conditon2
      std::string tmp1 = s1;
      std::string tmp2 = s2;
      std::sort(tmp1.begin(), tmp1.end());
      std::sort(tmp2.begin(), tmp2.end());
      if (tmp1 != tmp2) return false;

      for (int i = 1; i < s1.size(); i++) {
        if (  (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            ||(isScramble(s1.substr(0, i), s2.substr(s2.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s2.size() - i)))
          )
          return true;
      }

      return false;
    }
};

// Author: Huahua
class Solution {
public:
  string lastSubstring(string s) {
    int i = 0;
      int j = 1;
      int k = 0;
      while(j + k < s.size()){
         if(s[i + k] == s[j + k]) {
            k++;
            continue;
         }
         if(s[i + k] < s[j + k]){
            i = j;
            j++;
         }else{
            j = j + k + 1;
         }
         k = 0;
      }
      return s.substr(i, s.size() - i);
  }
};
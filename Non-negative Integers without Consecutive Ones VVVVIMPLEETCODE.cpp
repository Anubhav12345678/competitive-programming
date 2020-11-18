class Solution {
public:
    string convert(int n){
      string ret = "";
      while(n){
         ret += (n % 2) + '0';
         n >>= 1;
      }
      return ret;
   }
   int findIntegers(int num) {
      string bits = convert(num);
      int n = bits.size();
      vector <int> ones(n);
      vector <int> zeroes(n);
      ones[0] = zeroes[0] = 1;
      for(int i = 1; i < n; i++){
         zeroes[i] = zeroes[i - 1] + ones[i - 1];
         ones[i] = zeroes[i - 1];
      }
      int ret = ones[n - 1] + zeroes[n - 1];
      for(int i = n - 2; i >= 0; i--){
         if(bits[i] == '0' && bits[i + 1] == '0') ret -= ones[i];
         else if(bits[i] == '1' && bits[i + 1]== '1') break;
      }
      return ret;
   }
};
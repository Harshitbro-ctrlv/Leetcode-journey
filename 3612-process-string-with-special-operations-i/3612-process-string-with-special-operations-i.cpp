class Solution {
public:
    string processStr(string s) {
        string result = "";
        char s1[10];
        for (auto c: s){
            if(c =='*'){
                if(result.size()){
                    result.pop_back();
                }
            }else if(c == '#'){
                result += result;
            }else if(c == '%'){
                result = string(result.rbegin(), result.rend());
            }else{
                result += c;
            }
        }
        return result;
    }
};
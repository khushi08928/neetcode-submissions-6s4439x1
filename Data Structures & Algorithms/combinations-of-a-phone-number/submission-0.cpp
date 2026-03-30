class Solution {
private:
    vector<string> mapping={
        "", //0
        "", //1,
        "abc", //2
        "def", //3
        "ghi", //4
        "jkl", //5
        "mno", //6
        "pqrs", //7
        "tuv", //8
        "wxyz" //9
    };

    void getcombinations(string &digits,int index,string &current, vector<string>& ans){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }
        string letter= mapping[digits[index]-'0'];
        for(char c:letter){
            current.push_back(c);
            getcombinations(digits,index+1,current,ans);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty()) return ans;
        string current="";
        getcombinations(digits,0,current,ans);
        return ans;
    }
};

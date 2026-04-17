//will use two stacks,one to store number and other for string ,
//start iteration over string 
//if its digit then calculate num 
//if its open bracket,
//push current num into num stack and current string into str stack ,
//then reset num=0 and curr string=""
//if its closing bracket,
//pop num and previous string from stacks
//then make a temp string by repeating current string k times
//and attach it with previous string(prev+temp)
//otherwise add current char to curr string
//finally return curr

class Solution {
public:
    string decodeString(string s) {
        stack<int>numst;
        stack<string>str;        
        string curr="";
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0'); 
            }
            else if(c=='['){
                numst.push(num);
                str.push(curr);               
                num=0;
                curr="";
            }
            else if(c==']'){
                int k=numst.top(); 
                numst.pop();
                string prev=str.top(); 
                str.pop();                
                string temp="";
                for(int i=0;i<k;i++){
                    temp+=curr;
                }                
                curr=prev+temp;
            }
            else{
                curr+=c;
            }
        }       
        return curr;
    }
};
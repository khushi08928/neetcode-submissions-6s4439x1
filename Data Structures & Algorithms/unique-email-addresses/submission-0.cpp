class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(string email:emails){
            int posOfat=email.find('@');
            string localname=email.substr(0,posOfat);
            string domainName=email.substr(posOfat);
            string name="";
            for(char ch:localname){
                if(ch=='+') break;
                if(ch=='.') continue;
                name+=ch;
            }
            string Uniqueemail=name+domainName;
            st.insert(Uniqueemail);
        }
        return st.size();
    }
};
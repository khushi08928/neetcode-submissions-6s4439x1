// will use two data structures, first is queue and second is set
// and apply BFS (level order traversal)
// start from beginWord and push it into queue with step = 1
// at each step, I take a word and try all possible transformations
// by changing one character at a time (a to z)
// if transformed word exists in set:
// I erase that word from set (to avoid revisiting)
// and push it into queue with steps + 1
// if I reach endWord, return steps
// if queue becomes empty and endWord not found, return 0

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>que;
        unordered_set<string>st(wordList.begin(),wordList.end());
        que.push({beginWord,1});
        st.erase(beginWord);
        while(!que.empty()){
            string word=que.front().first;
            int steps=que.front().second;
            que.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                int originalChar=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        que.push({word,steps+1});
                    }
                }
                word[i]=originalChar;
            }
        }
        return 0;
    }
};

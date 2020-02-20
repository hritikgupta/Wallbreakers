// 212. Word Search II (https://leetcode.com/problems/word-search-ii/)
// Author: Hritik Gupta

struct TrieNode {
    bool is_last;
    int freq;
    unordered_map<char, struct TrieNode *> children;
};

TrieNode *newTrieNode(){
    TrieNode *temp = new TrieNode();
    temp->is_last = false;
    temp->freq = 0;
    return temp;
}

void insertTrie(TrieNode *&head, string s){
    if(head == NULL)
        head = newTrieNode();
    TrieNode *curr = head;
    
    for(int i=0; i<s.size(); i++){
        char letter = s[i];
        if(curr->children.find(letter) == curr->children.end())
            curr->children[letter] = newTrieNode();
        curr->children[letter]->freq++;
        curr = curr->children[letter];
    }
    curr->is_last = true;
}


bool hasPrefix(TrieNode *head, string s){
    if(head == NULL)
        return false;
    
    TrieNode *curr = head;
    for(int i=0; i<s.size(); i++){
        char letter = s[i];
        if(curr->children.find(letter) == curr->children.end())
            return false;
        curr = curr->children[letter];
    }
    return true;
}

bool hasWord(TrieNode *head, string s){
    if(head == NULL)
        return false;
    
    TrieNode *curr = head;
    for(int i=0; i<s.size(); i++){
        char letter = s[i];
        if(curr->children.find(letter) == curr->children.end())
            return false;
        curr = curr->children[letter];
    }
    return curr->is_last;
}

void dfs(vector<vector<char>>& board, TrieNode *head, map<pair<int, int>, bool> &visited, int i, int j, set<string> &res, string acc){
    
    if(!hasPrefix(head, acc))
        return;
    
    visited[{i, j}] = true;
    
    if(hasWord(head, acc) == 1){
        res.insert(acc);
    }
    
    int xdir[] = {-1, 0, 1, 0};
    int ydir[] = {0, 1, 0, -1};
    
    for(int dir=0; dir<4; dir++){
        int newx = xdir[dir] + i;
        int newy = ydir[dir] + j;
        
        if(newx>=0 && newy>=0 && newx<board.size() && newy<board[0].size() && !visited[{newx, newy}]){
               dfs(board, head, visited, newx, newy, res, acc+board[newx][newy]);
        }
    }
    visited[{i, j}] = false;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode *head = NULL;
        for(int i=0; i<words.size(); i++)
            insertTrie(head, words[i]);
        
        set<string> res;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                map<pair<int, int>, bool> visited;
                string acc = "";
                acc += board[i][j];
                dfs(board, head, visited, i, j, res, acc);        
            }
        }
        
        vector<string> ans;
        for(auto it=res.begin(); it!=res.end(); it++)
            ans.push_back(*it);
        
        return ans;
    }
};


/*
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

*/
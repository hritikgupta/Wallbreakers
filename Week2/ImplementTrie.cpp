// 208. Implement Trie (Prefix Tree) (https://leetcode.com/problems/implement-trie-prefix-tree/)
// Author: Hritik Gupta

struct TrieNode {
    bool is_last;
    int freq;
    map<char, TrieNode *> children;
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *head;
    Trie() {
        head = NULL;
    }
    
    TrieNode *newTrieNode(){
        TrieNode *temp = new TrieNode();
        temp->is_last = false;
        temp->freq = 0;
        return temp;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(head == NULL)
            head = newTrieNode();
        TrieNode *curr = head;
        
        for(int i=0; i<word.size(); i++){
            char letter = word[i];
            if(curr->children.find(letter) == curr->children.end())
                curr->children[letter] = newTrieNode();
            curr->children[letter]->freq++;
            curr = curr->children[letter];
        }
        curr->is_last = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s){
      if(head == NULL)
        return false;

      TrieNode *curr = head;
      for(int i=0; i<s.size(); i++){
        char letter = s[i];
        if(curr->children.find(letter) == curr->children.end())
          return false;
        curr = curr->children[letter];
      }
      return (curr->is_last == true)?true:false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(head == NULL)
            return false;
        
        TrieNode *curr = head;
        for(int i=0; i<prefix.size(); i++){
            char letter = prefix[i];
            if(curr->children.find(letter) == curr->children.end())
                return false;
            curr = curr->children[letter];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
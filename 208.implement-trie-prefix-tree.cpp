/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (36.88%)
 * Total Accepted:    165.1K
 * Total Submissions: 445.7K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */
const int TrieNodeNum=26;

struct TrieNode{
    bool ischar;
    TrieNode *next[TrieNodeNum];
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
        root->ischar=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.size();i++){
            if(p->next[word[i]-'a']==nullptr){
                p->next[word[i]-'a']=new TrieNode();
                p=p->next[word[i]-'a'];
                p->ischar=false;
            }
            else{p=p->next[word[i]-'a'];}
        }
        
        p->ischar=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p=root;
        for(int i=0;i<word.size();i++){
            if(p->next[word[i]-'a']==nullptr) return false;
            else{p=p->next[word[i]-'a'];}
        }
        
        return p->ischar;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p=root;
        for(int i=0;i<prefix.size();i++){
            if(p->next[prefix[i]-'a']==nullptr) return false;
            else{p=p->next[prefix[i]-'a'];}
        }
        return true;
    }
    
private:
    TrieNode *root;
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

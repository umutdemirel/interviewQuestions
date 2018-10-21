//
//  ImplementTrie.h
//  
//
//  https://leetcode.com/problems/implement-trie-prefix-tree/description/
//

#ifndef ImplementTrie_h
#define ImplementTrie_h

class TrieNode {
public:
    TrieNode(char val) {
        val = val;
        isWord = false;
    }
    
    char val;
    bool isWord;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    friend class TrieNode;
    
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('*');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* iterator = root;
        for (int i = 0; i < word.size(); i++) {
            if (iterator->children.find(word[i]) != iterator->children.end()) {
                
            } else {
                iterator->children[word[i]] = new TrieNode(word[i]);
            }
            iterator = iterator->children[word[i]];
        }
        iterator->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* iterator = root;
        for (int i = 0; i < word.size(); i++) {
            if (iterator->children.find(word[i]) != iterator->children.end()) {
                iterator = iterator->children[word[i]];
            } else {
                return false;
            }
            
        }
        return iterator->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* iterator = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (iterator->children.find(prefix[i]) != iterator->children.end()) {
                iterator = iterator->children[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

#endif /* ImplementTrie_h */

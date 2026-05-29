class Trie {
    public:
    class TrieNode {
        public:
        bool isEnd;
        TrieNode* children[26];
        TrieNode(){
            isEnd = false;
            for(auto &c: children){
                c = nullptr;
            }
        }
    };
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void add(string &word){
        TrieNode* node = root;
        for(char &ch: word){
            int idx = ch-'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    bool search(string &word){
        TrieNode* node = root;
        return helper(word,0,node);

    }
    bool helper(string &word,int idx,TrieNode* node){
        
        if(idx == word.size()) return node->isEnd;
        char ch = word[idx];
        if(ch!='.'){
            if(!node->children[ch-'a']) return false;
            node = node->children[ch-'a'];
            return helper(word,idx+1,node);
        }
        else{
            for(int i=0;i<26;i++){
                if(node->children[i] &&
                helper(word,idx+1,node->children[i])) return true;
            }
            return false;
        }
        return false;
    }
};

class WordDictionary {
public:
    Trie trie;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.add(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
};

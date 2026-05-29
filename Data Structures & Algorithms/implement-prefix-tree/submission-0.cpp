class PrefixTree {
public:
    class TrieNode {
        
        public:
        TrieNode* children[26];
        bool isEnd;

        TrieNode(){

            isEnd = false;
            for(auto &c: children){
                    c = nullptr;
            }
        }
    };
    TrieNode* root;

    PrefixTree() {   
        root = new TrieNode();
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto &ch: word){
            int idx = ch-'a';
            if(!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto &ch: prefix){
            int idx = ch-'a';
            if(!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

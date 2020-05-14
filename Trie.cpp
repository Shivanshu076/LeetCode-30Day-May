// Implement a trie with insert, search, and startsWith methods.

// Solution :

struct Node {
    unordered_map<char, shared_ptr<Node>> children;
    bool isEnd = false;
};
class Trie {
public:
    Trie() : _root{make_shared<Node>()} {}
    void insert(string word) {
        auto cur{ _root };
        for (auto c: word) {
            if (cur->children.find(c) == cur->children.end())
                cur->children[c] = make_shared<Node>();
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }
    bool search(string word) {
        return _find(word, false);
    }
    bool startsWith(string word) {
        return _find(word, true);
    }
private:
    shared_ptr<Node> _root;
    bool _find(string& word, bool isPrefix) {
        auto cur{ _root };
        for (auto c: word) {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
        return isPrefix ? true : cur->isEnd;    // prefix is true, word is true if and only if cur.isEnd
    }
};

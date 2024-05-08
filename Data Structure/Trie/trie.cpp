#define ELEMENT_SIZE 26
#define MIN_ELEMENT 'a'

class Trie {
   public:
    struct node {
        string value;
        node *child[ELEMENT_SIZE];
    };
    node *root;

    Trie(string init_str = "") {
        root = new node();
        if (init_str != "") Insert(init_str);
    }

    void Insert(string value, int start = 0) {
        insert(value, start, root);
    }

    void insert(string value, int i, node *cur) {
        if (i == value.size()) {
            cur->value = value;
            return;
        }
        if (cur->child[value[i] - MIN_ELEMENT] == NULL) {
            cur->child[value[i] - MIN_ELEMENT] = new node();
        }
        insert(value, i + 1, cur->child[value[i] - MIN_ELEMENT]);
    }

    string Find(string target, int start = 0) {
        return find(target, start, root);
    }

    string find(string target, int i, node *cur) {
        if (i == target.size()) return cur->value;

        node *nxt = cur->child[target[i] - MIN_ELEMENT];
        if (nxt) return find(target, i + 1, nxt);
        else return "";
    }
};

/*
Usage:
    Trie trie;

    trie.Insert("abc");
    string result1 = trie.Find("abc"); //result = "abc"
    string result2 = trie.Find("cba"); //result =  ""
*/
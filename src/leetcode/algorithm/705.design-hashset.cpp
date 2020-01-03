class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
    }
    
    void add(int key) {
        int hashKey = hash(key);
        auto newNode = new Node(key);
        if (hashTable[hashKey] == nullptr)
        {
            hashTable[hashKey] = newNode;
            return;
        }
        if (key < hashTable[hashKey]->key) {
            newNode->next = hashTable[hashKey];
            hashTable[hashKey] = newNode;
            return;
        }
        if (key == hashTable[hashKey]->key) {
            return;
        }
        auto node = hashTable[hashKey];
        while (node->next != nullptr) {
            if (key < node->next->key) {
                newNode->next = node->next;
                node->next = newNode;
                return;
            } else if (key == node->next->key) {
                return;
            } else if (key > node->next->key) {
                node = node->next;
            }
        }
        node->next = newNode;
    }
    
    void remove(int key) {
        int hashKey = hash(key);
        if (hashTable[hashKey] == nullptr) {
            return;
        }
        auto node = hashTable[hashKey];
        if (hashTable[hashKey]->key == key) {
            hashTable[hashKey] = hashTable[hashKey]->next;
            delete node;
            return;
        }
        while (node->next != nullptr) {
            if(key < node->next->key) {
                return;
            } else if (key == node->next->key) {
                auto nodeToRm = node->next;
                node->next = node->next->next;
                delete nodeToRm;
            } else {
                node = node->next;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashKey = hash(key);
        if (hashTable[hashKey] == nullptr) {
            return false;
        }
        if (hashTable[hashKey]->key == key) {
            return true;
        }
        auto node = hashTable[hashKey];
        while (node->next != nullptr) {
            if (key < node->next->key) {
                return false;
            } else if (key == node->next->key) {
                return true;
            } else {
                node = node->next;
            }
        }
        return false;
    }
private:
    const int HASH_NUMBER = 1000;
    int hash(int key) {
        return key % HASH_NUMBER;
    }

    struct Node {
        Node(int v) {
            key = v;
        }
        Node *next = nullptr;
        int key;
    };

    vector<Node*> hashTable = vector<Node*>(HASH_NUMBER, nullptr);
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

class LRUCache {
public:
    class Node{
    public:
            int key , val;
            Node* next;
            Node* prev;
            
            Node(int k, int v ){
                key = k;
                val = v;
                next = prev = NULL;
            }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> m;
    int limit;

    void addNode(Node* newNode){ //O(1)
        Node* oldNext = head->next;
        
        head->next = newNode;
        oldNext->prev = newNode;
        
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode){ //O(1)
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }
    
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) { //O(1)
        if(m.find(key) == m.end()){
            return -1; // does not exist
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int val) { //O(1)
        // check for key exist
        if(m.find(key) != m.end()){ // already exist
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if(m.size() == limit){
            // delete LRU data
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key,val);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
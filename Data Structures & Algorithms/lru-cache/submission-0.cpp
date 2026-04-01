class Node {
    public: 
        int data;
        int key;
        Node* next;
        Node* prev;

        Node(int d, int k) : data(d), key(k), next(nullptr), prev(nullptr){}
};

class LRUCache {
    private: 
        int cap;
        unordered_map<int, Node*>cache;
        Node *head;
        Node *tail;

        void remove(Node* node){
            Node* n = node->next;
            Node* p = node->prev;
            n->prev = p;
            p->next = n;
        }

        void insert(Node* node){
            Node* temp = head->next;
            temp->prev = node;
            node->next = temp;
            node->prev = head;
            head->next = node;
        }


public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        head  = new Node (-1,-1);
        tail = new Node (-1,-1);
        head->next = tail;
        tail->prev = head;
              
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->data;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            Node* old = cache[key];
            remove(old);
            delete old;
        }        

        Node* node = new Node(value, key);
        cache[key] = node;
        insert(node);

        if(cache.size() > cap){
            Node* node = tail->prev;
            remove(node);
            cache.erase(node->key);
            delete node;
        }
    }
};

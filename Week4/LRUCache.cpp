// 146. LRU Cache (https://leetcode.com/problems/lru-cache/)
// Author: Hritik Gupta

struct Node {
    int key;
    int val;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int k, int v){
    struct Node *temp = new Node;
    temp->key = k;
    temp->val = v;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

class LRUCache {
public:
    
    struct Node *head = createNode(-2, -2);
    struct Node *tail = createNode(-2, -2);
    
    int limit;
    int count;
    unordered_map<int, Node*> hash;
    
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        limit = capacity;
        count = 0;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end())
            return -1;
        
        Node *foundNode = hash[key];
        int ans = foundNode->val;
        
        foundNode->prev->next = foundNode->next;
        foundNode->next->prev = foundNode->prev;
        
        foundNode->next = head->next;
        head->next->prev = foundNode;
        head->next = foundNode;
        foundNode->prev = head;
        
        return ans;
    }
    
    void put(int key, int value) {
        
        if(hash.find(key) != hash.end()){
            
            Node *foundNode = hash[key];
            foundNode->val = value;
            
            foundNode->prev->next = foundNode->next;
            foundNode->next->prev = foundNode->prev;
            
            foundNode->next = head->next;
            head->next->prev = foundNode;
            head->next = foundNode;
            foundNode->prev = head;
            
        }
        else{
            Node *newNode = createNode(key, value);
            hash[key] = newNode;
            
            if(count < limit){
                count++;
                newNode->next = head->next;
                head->next->prev = newNode;
                head->next = newNode;
                newNode->prev = head;
            }
            else{
                
                Node *last = tail->prev;
                hash.erase(last->key);
                
                last->prev->next = last->next;
                last->next->prev = last->prev;
                
                newNode->next = head->next;
                head->next->prev = newNode;
                head->next = newNode;
                newNode->prev = head;
                
            }
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
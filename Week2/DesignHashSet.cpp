// 705. Design HashSet (https://leetcode.com/problems/design-hashset/)
// Author: Hritik Gupta

class MyHashSet {
public:
    /** Initialize your data structure here. */
    
    bool big_tab[1000001];
    
    MyHashSet() {
        fill_n(big_tab, 1000001, false);
    }
    
    void add(int key) {
        big_tab[key] = true;
    }
    
    void remove(int key) {
        big_tab[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return big_tab[key];    
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
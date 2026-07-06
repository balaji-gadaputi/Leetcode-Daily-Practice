// Last updated: 06/07/2026, 11:59:14
class RandomizedSet {
public:
    set<int> s;
    RandomizedSet(){}
    
    bool insert(int val) {
        auto it = s.insert(val);
        return it.second;
    }
    
    bool remove(int val) {
        return s.erase(val) > 0;
    }
    
    int getRandom() {
        int idx = rand() % s.size();
        auto it = s.begin();
        advance(it, idx);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
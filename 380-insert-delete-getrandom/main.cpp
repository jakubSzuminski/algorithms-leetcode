class RandomizedSet {
public:
    set<int> s;

    RandomizedSet() {
        s.clear();
    }

    bool insert(int val) {
        if (s.find(val) != s.end()) {
            return false;
        } else {
            s.insert(val);
            return true;
        }
    }

    bool remove(int val) {
        auto it = s.find(val);
        if (it != s.end()) {
            s.erase(it);
            return true;
        } else {
            return false;
        }
    }

    int getRandom() {
        int n = s.size();

        if (n == 0) {
            return -1;
        }

        int randIndex = rand() % n;
        auto it = s.begin();
        advance(it, randIndex);
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
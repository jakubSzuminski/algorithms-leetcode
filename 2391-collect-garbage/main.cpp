class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
    
        // create three arrays where the count of each will be stored
        vector<int> m_count;
        vector<int> p_count;
        vector<int> g_count;
    
        for (int i = 0; i < garbage.size(); i++) {
            string s = garbage[i];
            int m = 0;
            int p = 0;
            int g = 0;

            // count up all the letters and add them to arrays
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == 'M') m++;
                else if (s[j] == 'P') p++;
                else if (s[j] == 'G') g++;
            }

            m_count.push_back(m);
            p_count.push_back(p);
            g_count.push_back(g);

            // add up the travel time
            if ((i - 1) >= 0) {
                m += travel[i - 1];
                p += travel[i - 1];
                g += travel[i - 1];
            }

            ans += m;
            ans += p;
            ans += g;
        }

        // iterate backwards to see if we do not need to travel to some
        // homes because there are no letters (and substract travel times)
        bool exists_m = false;
        bool exists_p = false;
        bool exists_g = false;
    
        for (int i = garbage.size() - 1; i > 0; i--) {
            if (!exists_m && m_count[i] == 0) {
                ans -= travel[i - 1];
            } else {
                exists_m = true;
            }

            if (!exists_p && p_count[i] == 0) {
                ans -= travel[i - 1];
            } else {
                exists_p = true;
            }

            if (!exists_g && g_count[i] == 0) {
                ans -= travel[i - 1];
            } else {
                exists_g = true;
            }
        }

        return ans;
    }
};
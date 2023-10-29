class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // pigs - number of pigs
        // B - number of choices for each pig
        // P - number of choices for all "pigs" 
        // P = B^pigs

        signed pigs = 0,
            B = minutesToTest / minutesToDie + 1,
            P = 1;
        
        for( ; P < buckets; pigs++) P *= B;
        return pigs;
    }
};
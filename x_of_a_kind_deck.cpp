/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

	-Each group has exactly X cards.
	-All the cards in each group have the same integer.
*/

class Solution 
{
    public:
        bool hasGroupsSizeX(vector<int>& deck) 
        {
            if (deck.empty())           return false;
            
            map <int, int> hmap;
            
            for (auto &it: deck)
                if (hmap.find(it) == hmap.end())    hmap.insert({it, 1});
                else                                ++hmap[it];
              
            unsigned int X = hmap[hmap.begin()->first];
            
            for (map <int, int>::const_iterator it = hmap.begin(); it != hmap.end(); ++it)
                X = gcd(it->second, X);
            
            return X > 1;
        }
};

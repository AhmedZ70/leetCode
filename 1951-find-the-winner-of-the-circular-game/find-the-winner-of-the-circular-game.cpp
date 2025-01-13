class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends; 
        for (int i = 1; i <= n; i++){
            friends.push_back(i); 
        }
        int pos = 0; 
        while (friends.size() > 1){
            pos = (pos + k - 1) % friends.size();
            friends.erase(friends.begin() + pos);
        }
        return friends[0];
    }
};
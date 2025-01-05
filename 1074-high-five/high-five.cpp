class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> scores; 
        for (auto item: items){
            scores[item[0]].push(item[1]);

            if(scores[item[0]].size() > 5){
                scores[item[0]].pop();
            }
        }
        vector<vector<int>> res; 

        for (auto [id, pq] : scores){
            int avrg = 0;
            while (!pq.empty()){
                avrg += pq.top();
                pq.pop();
            }
            avrg = avrg/5; 
            res.push_back({id, avrg});
        }
        return res;
    }
};

// 1 : 91, 92, 93, 94, 95, 100
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;

        for (char x : s) {
            mp[x]++;
        }

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        
        while (pq.size() > 1) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();

            ans += top1.second;
            ans += top2.second;

            if (--top1.first > 0)
                pq.push(top1);
            if (--top2.first > 0)
                pq.push(top2);
        }

      
        if (!pq.empty()) {
            if (pq.top().first > 1) return ""; 
            ans += pq.top().second;
        }

        return ans;
    }
};

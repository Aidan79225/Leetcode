class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int time = 0;
        priority_queue<int> temp;
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b){return a[1]<b[1];});
        for(const auto &it : courses){
            time += it[0];
            temp.push(it[0]);
            if(time > it[1]){
                time -= temp.top();
                temp.pop();
            }
        }
        return temp.size();
    }
   
};

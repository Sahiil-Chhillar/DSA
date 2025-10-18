class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (int i : asteroids) {
            bool destroyed = false;
            while (!s.empty() && s.top() > 0 && i < 0) {
                if (abs(s.top()) < abs(i)) {
                    s.pop();
                    continue;
                } else if (abs(s.top()) == abs(i)) {
                    s.pop();
                }
                destroyed = true;
                break;
            }

            if (!destroyed) s.push(i);
        }

        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};
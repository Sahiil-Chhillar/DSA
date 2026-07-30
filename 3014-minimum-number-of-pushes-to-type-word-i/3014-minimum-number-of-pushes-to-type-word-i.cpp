// class Solution {
// public:
//     int minimumPushes(string word) {
//         int cnt = 0;
//         unordered_map<int, int> mp; // btn, pushes

//         // this works because no alphabet is repeating;
//         int btn = 2;
//         for (char& ch : word) {
//             if (btn > 9) btn = 2;

//             mp[btn]++;
//             cnt += mp[btn++];
//         }

//         return cnt;
//     }
// };

class Solution {
public:
    int minimumPushes(string word) {
        int pushes = 0;

        for (int i = 0; i < word.size(); i++) { // after every 8 keys increase one push
            pushes += (i / 8) + 1;
        }

        return pushes;
    }
};
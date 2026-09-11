class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int d : digits) freq[d]++;
        int count = 0;

        // h->Hunderds place , t -> tens place , u -> units place 
        for(int h = 1; h <= 9; h++){
            if (freq[h] == 0) continue;
            freq[h]--;
            for(int t = 0; t <= 9; t++){
                if (freq[t] == 0) continue;
                freq[t]--;
                for(int u = 0; u <= 8; u += 2){
                    if (freq[u] > 0) count++;
                }
                freq[t]++;
            }
            freq[h]++;
        }
        return count;
    }
};

// Complexity :-
// O(9*10*5) ~O(1);
// O(10) ~O(1);
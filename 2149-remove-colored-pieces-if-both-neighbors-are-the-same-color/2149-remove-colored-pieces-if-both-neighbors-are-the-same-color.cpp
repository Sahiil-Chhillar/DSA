class Solution {
public:
    bool winnerOfGame(string colors) {
        int A = 0,B = 0,moveA = 0,moveB = 0;

        for(auto& c : colors){
            if(c == 'A'){
                moveA++;
                if(moveA>=3) A++;

                moveB = 0;
            }
            else{
                moveB++;
                if(moveB >= 3) B++;

                moveA = 0;
            }
        }

        return A>B;
    }
};
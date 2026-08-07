// First Approach (Similiar to part one )

// class Solution {
// public:
//     void increment(string& num) {
//         int i = num.size() - 1;

//         while (i >= 0 && num[i] == '9') {
//             num[i] = '0';
//             i--;
//         }

//         if (i >= 0) num[i]++;
//         else num = "1" + num;
//     }

//     string smallestNumber(string num, long long t) {
//         while (num.size()) {
//             string temp = num;
//             long long currProd = 1;
//             while (temp.size()) {
//                 if (temp.back() == '0') {
//                     currProd = -1;
//                     break;
//                 }

//                 currProd *= (temp.back() - '0');
//                 temp.pop_back();
//             }
//             if (currProd != -1 && currProd % t == 0) return num;
//             increment(num);
//         }

//         return "-1";
//     }
// };

// Second Approach Failed (nhi pta kyu fail hua h )
// class Solution {
// public:
//     vector<vector<int>> digitFactors = {
//         {0,0,0,0},
//         {0,0,0,0},
//         {1,0,0,0},
//         {0,1,0,0},
//         {2,0,0,0},
//         {0,0,1,0},
//         {1,1,0,0},
//         {0,0,0,1}, 
//         {3,0,0,0},
//         {0,2,0,0} 
//     };

//     unordered_map<string, bool> dp;
//     bool canBuild(int remainingLength,int need2, int need3, int need5, int need7) {
//         need2 = max(0, need2);
//         need3 = max(0, need3);
//         need5 = max(0, need5);
//         need7 = max(0, need7);
        
//         if (need2 == 0 && need3 == 0 && need5 == 0 && need7 == 0) return true;
//         if (remainingLength == 0) return false;
//         if (need2 > 3 * remainingLength) return false;
//         if (need3 > 2 * remainingLength) return false;
//         if (need5 > remainingLength) return false;
//         if (need7 > remainingLength) return false;

//         string key = to_string(remainingLength) + "#" + to_string(need2) + "#" + to_string(need3) + "#" + to_string(need5) + "#" + to_string(need7);

//         if (dp.count(key)) return dp[key];

//         for (int digit = 1; digit <= 9; digit++) {
//             if (canBuild( remainingLength - 1, need2 - digitFactors[digit][0], need3 - digitFactors[digit][1], need5 - digitFactors[digit][2], need7 - digitFactors[digit][3])) return dp[key] = true;
//         }

//         return dp[key] = false;
//     }

//     string smallestNumber(string num, long long t) {
//         int need2 = 0;
//         int need3 = 0;
//         int need5 = 0;
//         int need7 = 0;

//         while (t % 2 == 0) {
//             need2++;
//             t /= 2;
//         }

//         while (t % 3 == 0) {
//             need3++;
//             t /= 3;
//         }

//         while (t % 5 == 0) {
//             need5++;
//             t /= 5;
//         }

//         while (t % 7 == 0) {
//             need7++;
//             t /= 7;
//         }

//         if (t != 1) return "-1";

//         for (int length = num.size(); ; length++) {
//             dp.clear();
//             if (!canBuild(length, need2, need3, need5, need7)) continue;

//             string answer = "";

//             int remaining2 = need2;
//             int remaining3 = need3;
//             int remaining5 = need5;
//             int remaining7 = need7;

//             bool alreadyGreater = (length > num.size());
//             bool possible = true;

//             for (int i = 0; i < length; i++) {
//                 int startDigit = 1;
//                 if (!alreadyGreater) startDigit = max(1, num[i] - '0');

//                 bool found = false;
//                 for (int digit = startDigit; digit <= 9; digit++) {
//                     int nextNeed2 = max(0, remaining2 - digitFactors[digit][0]);
//                     int nextNeed3 = max(0, remaining3 - digitFactors[digit][1]);
//                     int nextNeed5 = max(0, remaining5 - digitFactors[digit][2]);
//                     int nextNeed7 = max(0, remaining7 - digitFactors[digit][3]);

//                     if (canBuild(length - i - 1, nextNeed2, nextNeed3,nextNeed5, nextNeed7)) {
//                         answer.push_back(char('0' + digit));

//                         remaining2 = nextNeed2;
//                         remaining3 = nextNeed3;
//                         remaining5 = nextNeed5;
//                         remaining7 = nextNeed7;

//                         if (!alreadyGreater && digit > (num[i] - '0')) alreadyGreater = true;
//                         found = true;
//                         break;
//                     }
//                 }

//                 if (!found) {
//                     possible = false;
//                     break;
//                 }
//             }
//             if (possible) return answer;
//         }

//         return "-1";
//     }
// };


// Same approach fresh Start (LOL iss baar bhi glt aaya )
// class Solution {
// private:
//     bool isInvalid(long long n) {
//         for (int i = 2; i < 10; i++) {
//             while (n % i == 0) n /= i;
//         }
//         return n != 1;
//     }

//     int minDigitsNeeded(long long t) {
//         if (t <= 1) return 0;

//         int count = 0;
//         for (int d = 9; d >= 2; d--) {
//             while (t % d == 0) {
//                 count++;
//                 t /= d;
//             }
//         }
//         return count;
//     }

//     string getMore(long long t) {
//         string sol = "";
//         while (t != 1) {
//             int curr = 9;
//             while (curr > 1 && (t % curr != 0)) curr--;

//             sol.push_back(char(curr + '0'));
//             t /= curr;
//         }

//         reverse(sol.begin(), sol.end());
//         return sol;
//     }

//     long long reduceT(long long t, int d) {
//         for (int f = 9; f >= 2; f--) {
//             while (d % f == 0 && t % f == 0) {
//                 t /= f;
//                 d /= f;
//             }
//         }

//         return t;
//     }

// public:
//     string smallestNumber(string num, long long t) {
//         int n = num.size();

//         if (isInvalid(t)) return "-1";

//         int zeroIdx = -1;
//         for (int i = 0; i < n; i++) {
//             if (num[i] == '0') {
//                 zeroIdx = i;
//                 break;
//             }
//         }

//         if (zeroIdx == -1) {
//             long long tempT = t;
//             for (char c : num) tempT = reduceT(tempT, c - '0');
            
//             if (tempT == 1) return num;
//         }

//         int maxPrefix = (zeroIdx == -1) ? n : zeroIdx;
//         vector<long long> prefixT(n + 1, t);

//         for (int i = 0; i < maxPrefix; i++) {
//             prefixT[i + 1] = reduceT(prefixT[i], num[i] - '0');
//         }

//         for (int i = maxPrefix - 1; i >= 0; i--) {
//             int remainingLen = n - 1 - i;
//             int startDigit = (num[i] - '0') + 1;

//             for (int d = startDigit; d <= 9; d++) {
//                 long long remT = reduceT(prefixT[i], d);

//                 if (minDigitsNeeded(remT) <= remainingLen) {
//                     string sol = num.substr(0, i);
//                     sol.push_back(char(d + '0'));

//                     string suffix = getMore(remT);

//                     while ((int)suffix.size() < remainingLen) {
//                         suffix = "1" + suffix;
//                     }

//                     return sol + suffix;
//                 }
//             }
//         }

//         int reqLen = max(n + 1, minDigitsNeeded(t));

//         string sol = getMore(t);
//         while ((int)sol.size() < reqLen) sol = "1" + sol;

//         return sol;
//     }
// };

// Chaapa hua code (WTH is this)
// LeetCode 3348 - Smallest Divisible Digit Product II
// Memory extreme: same greedy search, but no feasibility table.
//
// The only non-trivial minimum-length question is how many digits are needed to cover
// the remaining 2/3 exponents. Trying 0..5 uses of digit 6 is sufficient because adding
// six more 6s always costs one more digit than the equivalent 8/9 grouping.

#include <algorithm>
#include <array>
#include <string>
using namespace std;

class Solution {
    using Need = array<int, 4>; // exponents of 2, 3, 5, 7

    inline static constexpr int Factor[10][4] = {
        {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {2, 0, 0, 0},
        {0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1}, {3, 0, 0, 0}, {0, 2, 0, 0}
    };

public:
    string smallestNumber(string num, long long t) {
        target_.fill(0);
        if (!factorTarget(t)) {
            return "-1";
        }

        const int n = static_cast<int>(num.size());
        Need covered{};
        int firstZero = n;

        for (int i = 0; i < n; ++i) {
            const int digit = num[i] - '0';
            if (digit == 0 && firstZero == n) {
                firstZero = i;
            }
            addDigit(covered, digit, 1);
        }

        if (firstZero == n && coversTarget(covered)) {
            return num;
        }

        for (int i = n - 1; i >= 0; --i) {
            const int original = num[i] - '0';
            addDigit(covered, original, -1);

            if (firstZero < i) {
                continue;
            }

            const int suffixLen = n - i - 1;
            const int startDigit = max(1, original + 1);

            for (int digit = startDigit; digit <= 9; ++digit) {
                Need remaining = missingAfter(covered, digit);
                if (minDigits(remaining) > suffixLen) {
                    continue;
                }

                string answer;
                answer.reserve(n);
                answer.append(num, 0, i);
                answer.push_back(static_cast<char>('0' + digit));
                appendSmallestSuffix(answer, suffixLen, remaining);
                return answer;
            }
        }

        Need fullNeed = target_;
        const int answerLen = max(n + 1, minDigits(fullNeed));
        string answer;
        answer.reserve(answerLen);
        appendSmallestSuffix(answer, answerLen, fullNeed);
        return answer;
    }

private:
    Need target_{};

    bool factorTarget(long long value) {
        static constexpr int Primes[4] = {2, 3, 5, 7};
        for (int i = 0; i < 4; ++i) {
            while (value % Primes[i] == 0) {
                ++target_[i];
                value /= Primes[i];
            }
        }
        return value == 1;
    }

    static int ceilDiv(int value, int divisor) {
        return (value + divisor - 1) / divisor;
    }

    static int minDigits23(int two, int three) {
        int best = ceilDiv(two, 3) + ceilDiv(three, 2);
        const int maxSixes = min({two, three, 5});

        for (int sixes = 1; sixes <= maxSixes; ++sixes) {
            const int cost = sixes + ceilDiv(two - sixes, 3) + ceilDiv(three - sixes, 2);
            best = min(best, cost);
        }

        return best;
    }

    static int minDigits(const Need& need) {
        return need[2] + need[3] + minDigits23(need[0], need[1]);
    }

    static void addDigit(Need& covered, int digit, int sign) {
        for (int i = 0; i < 4; ++i) {
            covered[i] += sign * Factor[digit][i];
        }
    }

    bool coversTarget(const Need& covered) const {
        for (int i = 0; i < 4; ++i) {
            if (covered[i] < target_[i]) {
                return false;
            }
        }
        return true;
    }

    Need missingAfter(const Need& covered, int digit) const {
        Need remaining{};
        for (int i = 0; i < 4; ++i) {
            remaining[i] = max(0, target_[i] - covered[i] - Factor[digit][i]);
        }
        return remaining;
    }

    static Need consumeDigit(Need need, int digit) {
        for (int i = 0; i < 4; ++i) {
            need[i] = max(0, need[i] - Factor[digit][i]);
        }
        return need;
    }

    void appendSmallestSuffix(string& answer, int length, Need need) const {
        const int coreLen = minDigits(need);
        answer.append(length - coreLen, '1');

        for (int slots = coreLen; slots > 0; --slots) {
            for (int digit = 2; digit <= 9; ++digit) {
                Need next = consumeDigit(need, digit);
                if (minDigits(next) <= slots - 1) {
                    answer.push_back(static_cast<char>('0' + digit));
                    need = next;
                    break;
                }
            }
        }
    }
};

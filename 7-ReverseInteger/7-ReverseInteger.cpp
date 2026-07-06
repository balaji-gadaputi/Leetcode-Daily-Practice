// Last updated: 06/07/2026, 12:01:20
#include <climits> // For INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        long long reversedNum = 0; // Using long long to catch overflow
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            reversedNum = reversedNum * 10 + digit;
            
            // Check for overflow: If reversedNum goes outside the int range, return 0
            if (reversedNum > INT_MAX || reversedNum < INT_MIN) {
                return 0;
            }
        }
        
        return static_cast<int>(reversedNum); // Casting back to int since overflow is checked
    }
};

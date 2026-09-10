class Solution {
  public:
    int pairCount(int x, int y) {
        if (y % x != 0) {
            return 0;
        }

        long long product = (long long)x * y; 
        int total_pairs = 0;

        for (int a = 1; a * a <= product; ++a) {
            if (product % a == 0) {
                int b = product / a;

                if (gcd(a, b) == x && lcm(a, b) == y) {
                    if (a == b) {
                        total_pairs += 1; 
                    } else {
                        total_pairs += 2; 
                    }
                }
            }
        }

        return total_pairs;
    }
};

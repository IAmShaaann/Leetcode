#include <string>
using namespace std;
class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k)
    {
        int mx = 0;
        int vowels = 0;
        for (int i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
                vowels++;
        }
        mx = max(mx, vowels);

        for (int i = k; i < s.size(); i++)
        {
            char current = s[i];
            char lastToCurrent = s[i - k];
            if (isVowel(lastToCurrent))
                vowels--;
            if (isVowel(current))
                vowels++;
            mx = max(mx, vowels);
        }
        return mx;
    }
};

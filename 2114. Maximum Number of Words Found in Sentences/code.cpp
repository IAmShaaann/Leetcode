class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int maxSpacesCount = 0;
        for (string sentence : sentences)
        {
            int spaceCount = 0;
            for (char ch : sentence)
            {
                if (ch == ' ')
                    spaceCount++;
            }
            maxSpacesCount = max(maxSpacesCount, spaceCount + 1);
            spaceCount = 0;
        }
        return maxSpacesCount;
    }
};
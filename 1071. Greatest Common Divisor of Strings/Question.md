Question: For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

```
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
```

Solution:
if: the s + t is not equal to t + s => return "";
else: calculate the greatest common divisor of both the string, return the substring from the smaller string of length 0 to gcd.

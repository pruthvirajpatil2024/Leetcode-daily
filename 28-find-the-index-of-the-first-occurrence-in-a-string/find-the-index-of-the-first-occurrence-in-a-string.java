class Solution {
    public int strStr(String haystack, String needle) {
        int n = haystack.length();
        int lim = needle.length();

        for (int i = 0; i + lim <= n; i++) {  // Fix: use <= to include last possible match
            String str = haystack.substring(i, i + lim);  // Fix: Correct substring range
            if (str.equals(needle)) {  // Fix: Use .equals() for string comparison
                return i;
            }
        }
        return -1;
    }
}

class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        int i = n - 1;
        int cnt = 0;

        // Ignore trailing spaces
        while (i >= 0 && s.charAt(i) == ' ') {
            i--;
        }

        // Count characters of the last word
        while (i >= 0 && s.charAt(i) != ' ') {
            cnt++;
            i--;
        }

        return cnt;
    }
}

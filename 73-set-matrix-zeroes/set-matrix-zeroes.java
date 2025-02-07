import java.util.ArrayList;
import java.util.AbstractMap.SimpleEntry;

class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        ArrayList<SimpleEntry<Integer, Integer>> zeroPositions = new ArrayList<>();

        // Step 1: Store the positions of all zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    zeroPositions.add(new SimpleEntry<>(i, j));
                }
            }
        }

        // Step 2: Set rows and columns to zero based on stored positions
        for (SimpleEntry<Integer, Integer> pos : zeroPositions) {
            int row = pos.getKey();
            int col = pos.getValue();

            // Set entire row to zero
            for (int j = 0; j < m; j++) {
                matrix[row][j] = 0;
            }

            // Set entire column to zero
            for (int i = 0; i < n; i++) {
                matrix[i][col] = 0;
            }
        }
    }
}

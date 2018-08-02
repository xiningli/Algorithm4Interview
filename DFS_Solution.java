import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    
    
    private static int countCells(int[][] grid, int i, int j) {
        if (i<0||j<0||i>=grid.length||j>=grid[0].length ) return 0;
        int count = 1;
        if (grid[i][j] == 0) return 0;
        grid[i][j]--;
        count+=countCells(grid, i, j+1);
        count+=countCells(grid, i-1, j+1);
        count+=countCells(grid, i-1, j);
        count+=countCells(grid, i-1, j-1);
        count+=countCells(grid, i, j-1);
        count+=countCells(grid, i+1, j-1);
        count+=countCells(grid, i+1, j);
        count+=countCells(grid, i+1, j+1);
        return count;
    }
    
    
    
    // Complete the maxRegion function below.
    static int maxRegion(int[][] grid) {
        
        int current_max = 0;
        int row_num = grid.length;
        int col_num = grid[0].length;
        
        
        
        for (int i=0; i<row_num; i++){
            for (int j=0; j<col_num; j++){
                current_max = Math.max(current_max, countCells(grid,i,j));
            }
        } 
        return current_max;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[][] grid = new int[n][m];

        for (int i = 0; i < n; i++) {
            String[] gridRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < m; j++) {
                int gridItem = Integer.parseInt(gridRowItems[j]);
                grid[i][j] = gridItem;
            }
        }

        int res = maxRegion(grid);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

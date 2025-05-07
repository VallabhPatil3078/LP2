public class MatrixAddition {

    // Method to add two matrices
    public static List<List<Integer>> addMatrices(List<List<Integer>> matrix1, List<List<Integer>> matrix2) {
        // Check if both matrices have the same dimensions
        if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
            throw new IllegalArgumentException('Matrices must have the same dimensions');
        }

        // Initialize the result matrix with the same dimensions
        List<List<Integer>> result = new List<List<Integer>>();

        // Loop through each row and column to perform the addition
        for (Integer i = 0; i < matrix1.size(); i++) {
            List<Integer> row = new List<Integer>();
            for (Integer j = 0; j < matrix1[i].size(); j++) {
                Integer sum = matrix1[i][j] + matrix2[i][j];
                row.add(sum);
            }
            result.add(row);
        }

        return result;
    }
}

//AW
// Example matrices
List<List<Integer>> matrix1 = new List<List<Integer>>{
    new List<Integer>{1, 2, 3},
    new List<Integer>{4, 5, 6},
    new List<Integer>{7, 8, 9}
};

List<List<Integer>> matrix2 = new List<List<Integer>>{
    new List<Integer>{9, 8, 7},
    new List<Integer>{6, 5, 4},
    new List<Integer>{3, 2, 1}
};

// Perform matrix addition
List<List<Integer>> result = MatrixAddition.addMatrices(matrix1, matrix2);

// Output the result
System.debug('Resultant Matrix: ' + result);

public class MatrixCalculator {

    // Method to perform matrix multiplication
    public static List<List<Decimal>> multiplyMatrices(List<List<Decimal>> matrixA, List<List<Decimal>> matrixB) {
        // Ensure that the number of columns in matrixA matches the number of rows in matrixB
        Integer rowsA = matrixA.size();
        Integer colsA = matrixA[0].size();
        Integer rowsB = matrixB.size();
        Integer colsB = matrixB[0].size();
        
        if (colsA != rowsB) {
            throw new IllegalArgumentException('Number of columns in matrix A must match number of rows in matrix B');
        }

        // Initialize the result matrix with appropriate size (rowsA x colsB)
        List<List<Decimal>> resultMatrix = new List<List<Decimal>>();
        
        for (Integer i = 0; i < rowsA; i++) {
            List<Decimal> row = new List<Decimal>();
            for (Integer j = 0; j < colsB; j++) {
                Decimal sum = 0;
                // Perform the summation for the element C[i][j]
                for (Integer k = 0; k < colsA; k++) {
                    sum += matrixA[i][k] * matrixB[k][j];
                }
                row.add(sum);
            }
            resultMatrix.add(row);
        }

        return resultMatrix;
    }
}


//AW
List<List<Decimal>> matrixA = new List<List<Decimal>>{
    new List<Decimal>{1, 2, 3},
    new List<Decimal>{4, 5, 6}
};

List<List<Decimal>> matrixB = new List<List<Decimal>>{
    new List<Decimal>{7, 8},
    new List<Decimal>{9, 10},
    new List<Decimal>{11, 12}
};

List<List<Decimal>> result = MatrixCalculator.multiplyMatrices(matrixA, matrixB);

// Output the result
for (List<Decimal> row : result) {
    System.debug(row);
}

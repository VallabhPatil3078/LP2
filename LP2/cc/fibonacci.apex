public class FibonacciSeries {

    // Method to return the Fibonacci series up to n terms
    public static List<Integer> generateFibonacciSeries(Integer n) {
        List<Integer> fibonacciSeries = new List<Integer>();

        if (n <= 0) {
            return fibonacciSeries; // If input is 0 or negative, return an empty list
        }

        // First two terms of the Fibonacci sequence
        Integer a = 0, b = 1;

        // Add the first term
        fibonacciSeries.add(a);

        // If n is greater than 1, add the second term
        if (n > 1) {
            fibonacciSeries.add(b);
        }

        // Generate the remaining Fibonacci numbers
        for (Integer i = 2; i < n; i++) {
            Integer nextTerm = a + b;
            fibonacciSeries.add(nextTerm);
            a = b;
            b = nextTerm;
        }

        return fibonacciSeries;
    }
}


//AW
Integer n = 10;

List<Integer> fibonacci = FibonacciSeries.generateFibonacciSeries(n);

System.debug('Fibonacci series of ' + n + ' terms: ' + fibonacci);

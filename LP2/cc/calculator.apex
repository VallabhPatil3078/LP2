public class ScientificCalculator {

    // Addition
    public static Decimal add(Decimal a, Decimal b) {
        return a + b;
    }

    // Subtraction
    public static Decimal subtract(Decimal a, Decimal b) {
        return a - b;
    }

    // Multiplication
    public static Decimal multiply(Decimal a, Decimal b) {
        return a * b;
    }

    // Division
    public static Decimal divide(Decimal a, Decimal b) {
        if (b == 0) {
            throw new IllegalArgumentException('Cannot divide by zero');
        }
        return a / b;
    }

    // Power (a raised to the power of b)
    public static Decimal power(Decimal a, Decimal b) {
        // Use Math.pow for power operation
        Double result = Math.pow(Double.valueOf(a), Double.valueOf(b));
        return Decimal.valueOf(result);
    }

    // Square Root
    public static Decimal squareRoot(Decimal a) {
        if (a < 0) {
            throw new IllegalArgumentException('Cannot calculate square root of negative number');
        }
        return Decimal.valueOf(Math.sqrt(Double.valueOf(a)));
    }

    // Sin function (in radians)
    public static Decimal sin(Decimal angle) {
        return Decimal.valueOf(Math.sin(Double.valueOf(angle)));
    }

    // Cos function (in radians)
    public static Decimal cos(Decimal angle) {
        return Decimal.valueOf(Math.cos(Double.valueOf(angle)));
    }

    // Tan function (in radians)
    public static Decimal tan(Decimal angle) {
        return Decimal.valueOf(Math.tan(Double.valueOf(angle)));
    }

    // Logarithm (base 10)
    public static Decimal log(Decimal a) {
        if (a <= 0) {
            throw new IllegalArgumentException('Logarithm is undefined for non-positive numbers');
        }
        return Decimal.valueOf(Math.log10(Double.valueOf(a)));
    }

    // Natural Logarithm (ln)
    public static Decimal ln(Decimal a) {
        if (a <= 0) {
            throw new IllegalArgumentException('Natural logarithm is undefined for non-positive numbers');
        }
        return Decimal.valueOf(Math.log(Double.valueOf(a)));
    }

    // Exponential function (e^x)
    public static Decimal exp(Decimal a) {
        return Decimal.valueOf(Math.exp(Double.valueOf(a)));
    }
}


//AW
Decimal a = 16;
Decimal b = 4;

System.debug('Addition: ' + ScientificCalculator.add(a, b));
System.debug('Subtraction: ' + ScientificCalculator.subtract(a, b));
System.debug('Multiplication: ' + ScientificCalculator.multiply(a, b));
System.debug('Division: ' + ScientificCalculator.divide(a, b));
System.debug('Power: ' + ScientificCalculator.power(a, b));
System.debug('Square Root: ' + ScientificCalculator.squareRoot(a));
System.debug('Sin (in radians): ' + ScientificCalculator.sin(Math.PI / 2));  // 90 degrees
System.debug('Cos (in radians): ' + ScientificCalculator.cos(Math.PI));  // 180 degrees
System.debug('Tan (in radians): ' + ScientificCalculator.tan(Math.PI / 4));  // 45 degrees
System.debug('Logarithm (base 10): ' + ScientificCalculator.log(100));
System.debug('Natural Logarithm (ln): ' + ScientificCalculator.ln(Math.E));  // ln(e)
System.debug('Exponential (e^x): ' + ScientificCalculator.exp(1));

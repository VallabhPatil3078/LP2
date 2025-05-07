public class InterestCalculator {

    // Simple Interest = (P × R × T) / 100
    public static Decimal calculateSimpleInterest(Decimal principal, Decimal rate, Integer t) {
        return (principal * rate * t) / 100;
    }

    // Compound Interest = P × (1 + R/(n×100))^(n×T) - P
    public static Decimal calculateCompoundInterest(Decimal principal, Decimal rate, Integer t, Integer n) {
        Decimal base = 1 + (rate / (n * 100));
        Double exponent = n * t;
        Double power = Math.pow((Double)base, exponent);
        Decimal amount = principal * Decimal.valueOf(power);
        return amount - principal;
    }
}

//AW
Decimal principal = 10000;  // Principal amount
Decimal rate = 5;           // Annual interest rate in percent
Integer t = 3;              // Time in years
Integer n = 1;              // Compounded once per year

Decimal simpleInterest = InterestCalculator.calculateSimpleInterest(principal, rate, t);
Decimal compoundInterest = InterestCalculator.calculateCompoundInterest(principal, rate, t, n);

System.debug('Simple Interest: ' + simpleInterest);
System.debug('Compound Interest: ' + compoundInterest);



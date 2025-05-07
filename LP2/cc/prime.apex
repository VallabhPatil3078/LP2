public class PrimeChecker {

    public static Boolean isPrime(Integer num) {
        if (num <= 1) {
            return false;
        }

        for (Integer i = 2; i <= Math.sqrt(num); i++) {
            if ((num / i) * i == num) {  // Checking divisibility using division
                return false;
            }
        }

        return true;
    }
}

//AW
Integer num = 29;

Boolean result = PrimeChecker.isPrime(num);

if (result) {
    System.debug(num + ' is a prime number.');
} else {
    System.debug(num + ' is not a prime number.');
}

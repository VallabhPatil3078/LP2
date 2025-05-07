public class CurrencyConverter {

    // Method to convert currency based on predefined exchange rates
    public static Decimal convertCurrency(Decimal amount, String fromCurrency, String toCurrency) {
        // Predefined exchange rates (for example: USD to EUR, GBP to USD)
        Map<String, Decimal> exchangeRates = new Map<String, Decimal>{
            'USD-EUR' => 0.85,  // 1 USD = 0.85 EUR
            'USD-GBP' => 0.75,  // 1 USD = 0.75 GBP
            'EUR-USD' => 1.18,  // 1 EUR = 1.18 USD
            'GBP-USD' => 1.33   // 1 GBP = 1.33 USD
        };

        // Create the key to look up the exchange rate
        String currencyPair = fromCurrency + '-' + toCurrency;

        // Check if exchange rate exists for the currency pair
        if (exchangeRates.containsKey(currencyPair)) {
            // Convert the amount using the exchange rate
            Decimal exchangeRate = exchangeRates.get(currencyPair);
            return amount * exchangeRate;
        } else {
            // Return a message if the conversion is not supported
            throw new IllegalArgumentException('Currency pair not supported');
        }
    }
}

//AW
Decimal usdToEur = CurrencyConverter.convertCurrency(100, 'USD', 'EUR');
Decimal eurToUsd = CurrencyConverter.convertCurrency(50, 'EUR', 'USD');
Decimal gbpToUsd = CurrencyConverter.convertCurrency(80, 'GBP', 'USD');

System.debug('100 USD to EUR: ' + usdToEur);
System.debug('50 EUR to USD: ' + eurToUsd);
System.debug('80 GBP to USD: ' + gbpToUsd);

// Uncomment below line to test unsupported currency pair
// Decimal unsupported = CurrencyConverter.convertCurrency(100, 'INR', 'USD');

public class TemperatureConverter {

    // Celsius to Fahrenheit
    public static Decimal celsiusToFahrenheit(Decimal celsius) {
        return (celsius * 9 / 5) + 32;
    }

    // Fahrenheit to Celsius
    public static Decimal fahrenheitToCelsius(Decimal fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }

    // Celsius to Kelvin
    public static Decimal celsiusToKelvin(Decimal celsius) {
        return celsius + 273.15;
    }

    // Kelvin to Celsius
    public static Decimal kelvinToCelsius(Decimal kelvin) {
        return kelvin - 273.15;
    }

    // Fahrenheit to Kelvin
    public static Decimal fahrenheitToKelvin(Decimal fahrenheit) {
        return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
    }

    // Kelvin to Fahrenheit
    public static Decimal kelvinToFahrenheit(Decimal kelvin) {
        return celsiusToFahrenheit(kelvinToCelsius(kelvin));
    }
}


//AW
Decimal tempC = 25;
Decimal tempF = 77;
Decimal tempK = 298.15;

System.debug('Celsius to Fahrenheit: ' + TemperatureConverter.celsiusToFahrenheit(tempC));   // 77
System.debug('Fahrenheit to Celsius: ' + TemperatureConverter.fahrenheitToCelsius(tempF));   // 25
System.debug('Celsius to Kelvin: ' + TemperatureConverter.celsiusToKelvin(tempC));           // 298.15
System.debug('Kelvin to Celsius: ' + TemperatureConverter.kelvinToCelsius(tempK));           // 25
System.debug('Fahrenheit to Kelvin: ' + TemperatureConverter.fahrenheitToKelvin(tempF));     // 298.15
System.debug('Kelvin to Fahrenheit: ' + TemperatureConverter.kelvinToFahrenheit(tempK));     // 77

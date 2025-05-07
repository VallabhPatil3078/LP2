public class GeometryAreaCalculator {
    public static Decimal area_of_circle(Decimal radius) {
        return Math.PI * radius * radius;
    }

    public static Decimal area_of_rectangle(Decimal length, Decimal width) {
        return length * width;
    }

    public static Decimal area_of_triangle(Decimal base, Decimal height) {
        return 0.5 * base * height;
    }
}

//AW
Decimal circleArea = GeometryAreaCalculator.area_of_circle(5);
Decimal rectangleArea = GeometryAreaCalculator.area_of_rectangle(4, 6);
Decimal triangleArea = GeometryAreaCalculator.area_of_triangle(3, 7);

System.debug('Circle Area: ' + circleArea);
System.debug('Rectangle Area: ' + rectangleArea);
System.debug('Triangle Area: ' + triangleArea);

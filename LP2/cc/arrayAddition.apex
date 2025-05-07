public class ArrayAddition {
    public static List<Integer> addArrays(List<Integer> arr1, List<Integer> arr2) {
        List<Integer> result = new List<Integer>();
        Integer size = Math.min(arr1.size(), arr2.size());

        for (Integer i = 0; i < size; i++) {
            result.add(arr1[i] + arr2[i]);
        }

        // Add remaining elements from longer array
        if (arr1.size() > size) {
            for (Integer i = size; i < arr1.size(); i++) {
                result.add(arr1[i]);
            }
        } else if (arr2.size() > size) {
            for (Integer i = size; i < arr2.size(); i++) {
                result.add(arr2[i]);
            }
        }

        return result;
    }
}

//AW
List<Integer> arr1 = new List<Integer>{1, 2, 3, 4};
List<Integer> arr2 = new List<Integer>{10, 20, 30};

List<Integer> result = ArrayAddition.addArrays(arr1, arr2);

System.debug('Result of Array Addition: ' + result);

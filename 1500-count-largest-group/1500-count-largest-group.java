class Solution {

    public int findDigitsSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    public int countLargestGroup(int n) {
        Map<Integer, Integer> mp = new HashMap<>();

        int maxSize = 0;
        int count = 0;

        for (int num = 1; num <= n; num++) {
            int digitsSum = findDigitsSum(num);

            mp.put(digitsSum, mp.getOrDefault(digitsSum, 0) + 1);
            if (mp.get(digitsSum) == maxSize) {
                count++;
            } else if (mp.get(digitsSum) > maxSize) {
                maxSize = mp.get(digitsSum);
                count = 1;
            }
        }

        return count;
    }
}
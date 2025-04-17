class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int n = time.length;

        Map<Integer, Integer>mp = new HashMap<>();

        int ans = 0;
        for(int i=0; i<n; ++i) {
            int x = (60 - time[i] % 60) % 60;
            ans += mp.getOrDefault(x, 0);
            int y = time[i] % 60;

            mp.put(y, mp.getOrDefault(y, 0) + 1);
        }
        return ans;
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

class MaxPairwiseProduct {
    static long getMaxPairwiseProduct(long[] numbers) {
        int n = numbers.length;
        long first = 0;
        long second = 0;
    
        for (int x = 0; x < n; ++x) {
            if(numbers[x] >= first) {
                second = first;
                first = numbers[x];
            } else if(numbers[x] > second) {
                second = numbers[x];
            }
        }
    
        return (first * second);
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new
                    InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        int n = scanner.nextInt();
        long[] numbers = new long[n];

        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextLong();
        }
        
        System.out.println(getMaxPairwiseProduct(numbers));
    }
}
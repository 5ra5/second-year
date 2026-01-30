import java.util.Scanner;

public class PrimeNumber {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int limit = scanner.nextInt();

        int cnt = isPrime(limit);

        System.out.println(cnt);
    }

    private static int isPrime(int n){

       boolean[] prime = new boolean[n + 1];
        for (int i = 0; i <= n; i++) {
            prime[i] = true;
        }

        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        int count = 0;
        for (int p = 2; p <= n; p++) {
            if (prime[p])
                count++;
        }

        return count;

    }
}
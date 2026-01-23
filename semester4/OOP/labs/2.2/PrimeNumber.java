import java.util.Scanner;

public class PrimeNumber {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        long limit = scanner.nextInt();

        long cnt = 0;

        for(int i = 2; i <= limit; i++){
            if(isPrime(i) == true){
                cnt++;
            }
        }

        System.out.println(cnt);
    }

    private static boolean isPrime(long num){
        for(int i = 2; i <= Math.sqrt(num); i++) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

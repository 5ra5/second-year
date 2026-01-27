import java.util.Scanner;

public class PrimeNumber {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        long limit = scanner.nextInt();

        long cnt = 0;

        for (int i = 2; i <= limit; i++){
            if(isPrime(i) == true){
                cnt++;
            }
        }

        System.out.println(cnt);
    }

    private static boolean isPrime(long num){

        if (num == 1) {
            return false;
        }

        if (num == 2 || num == 3){
            return true;
        }

        if (num % 2 == 0 || num % 3 == 0){
            return false;
        }

        for(int i = 5; i <= Math.sqrt(num); i+=6) {
            if(num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

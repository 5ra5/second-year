interface PaymentProcessor {
    void processPayment(double amount);
}

class PayPalPayment implements PaymentProcessor {
    public void processPayment(double amount) {
        System.out.println("Processing PayPal payment of $" + amount);
    }
}

class CreditCardPayment implements PaymentProcessor {
    public void processPayment(double amount) {
        System.out.println("Processing Credit Card payment of $" + amount);
    }
}

public class payment {
    public static void main(String[] args){
        PayPalPayment p1 = new PayPalPayment();
        p1.processPayment(200);
    }    
}

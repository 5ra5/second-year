import java.util.ArrayList;
import java.util.List;

public class Fridge {

    // attributes
    private List<String> foodItems = new ArrayList<String>();
    private int balance;

    // constructor
    public Fridge(int initialBalance) {
        
        if(initialBalance < 0) {
            this.balance = 0;
            System.out.println("Error");
        }
        else {
            this.balance = initialBalance;
        }
    }

    // methods
    public void addFood(String item, int cost) {
        if ( balance < cost || cost < 0) {
            System.out.println("Error");
        }
        else if (item == null) {
            System.out.println("Error");
        }
        else {
            foodItems.add(item);
            System.out.printf("Item %s has been added to the fridge.\n", item);
            this.balance -= cost;
        }
    }

    public void getFood(String item) {
        if (foodItems.contains(item)) {
            foodItems.remove(item);
            System.out.printf("Item %s has been removed from the fridge.\n", item);
        }
        else {
            System.out.println("Error");
        }
    }

    public void checkStatus(){

        if (foodItems.isEmpty()) {
            System.out.println("Food items:");
            System.out.println("(none)");
        }
        else {
            System.out.println("Food items:");
            for(String foodItem : foodItems) {
                System.out.println(foodItem);
            }
        }
        System.out.printf("Balance: €%d\n", this.balance);
    }

}

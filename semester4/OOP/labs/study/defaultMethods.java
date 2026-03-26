
interface Animal {
    default void sleep() {
        System.out.println("Sleeping...");
    }
}

class Cat implements Animal {
    public void sleep() { // Overriding the default method
        System.out.println("Meow I'm sleeping...");
    }
}
public class defaultMethods {
    public static void main(String[] args) {
        Cat c = new Cat();
        c.sleep();
    }
}

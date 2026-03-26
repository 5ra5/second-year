import java.util.List;
import java.util.ArrayList;

class Animal {
    public void makeSound() {
        System.out.println("Animal sound");
    }
}

class Dog extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Bark!");
    }
}

class Cat extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Meow!");
    }
}

class Cow extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Moo!");
    }
}

public class poly {
    public static void main(String[] args){
        List<Animal> animals = new ArrayList<>();

        animals.add(new Dog());
        animals.add(new Cat());
        animals.add(new Cow());

        for (Animal a : animals) {
            a.makeSound();
        }
    }
}

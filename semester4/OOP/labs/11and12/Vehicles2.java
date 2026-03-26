abstract class Vehicle {
    public String brand;

    public Engine engine;

    public Vehicle(String brand, Engine engine){
        this.engine = engine;
        this.brand = brand;
    }

    public int getHorsePower() {
        return engine.horsePower;
    }

    abstract void startEngine();
}

class Car extends Vehicle{
    int numDoors;

    public Car(String brand, int numDoors, Engine engine) {
        super(brand, engine);
        this.numDoors = numDoors;
    }

    @Override
    public void startEngine(){
        System.out.printf("Starting car with %d horsepowers\n", this.getHorsePower());
    }
}

class Bike extends Vehicle {
    boolean hasCarrier;

    public Bike(String brand, boolean hasCarrier, Engine engine) {
        super(brand, engine);
        this.hasCarrier = hasCarrier;
    }

    @Override
    public void startEngine() {
        System.out.printf("Starting bike with %d horsepowers\n", this.getHorsePower());
    }
}

class ElectricCar extends Car {
    int batteryCapacity;

    public ElectricCar(String brand, int numDoors, int batteryCapacity, Engine engine){
        super(brand, numDoors, engine);
        this.batteryCapacity = batteryCapacity;
    }

    @Override
    public void startEngine() {
        System.out.printf("Starting electric car silently with %d horsepowers\n", this.getHorsePower());
    }
}

class Engine {
    public int horsePower;

    public Engine(int horsePower) {
        this.horsePower = horsePower;
    }
}

public class Vehicles2 {
    public static void main(String[] args) {
        Engine carEngine = new Engine(150);
        Car myCar = new Car("Toyota", 4, carEngine);
        myCar.startEngine();

        Engine bikeEngine = new Engine(20);
        Bike myBike = new Bike("Yamaha", true, bikeEngine);
        myBike.startEngine();

        Engine electricCarEngine = new Engine(200);
        ElectricCar tesla = new ElectricCar("Tesla", 4, 75, electricCarEngine);
        tesla.startEngine();
    }
}
import java.util.ArrayList;
import java.util.List;

public class SmartHome {
    private String ownerName;
    private List<Appliance> appliances;

    // constructor
    public SmartHome(String ownerName) {
        this.ownerName = ownerName;
        this.appliances = new ArrayList<>();
    }

    public SmartHome(String ownerName, List<Appliance> appliances) {
        this.ownerName = ownerName;
        this.appliances = new ArrayList<>();
    }

    // getters and setters
    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    public String getOwnerName() {
        return this.ownerName;
    }

    // methods
    public void addAppliance(Appliance appliance) {
        if (appliance != null && !appliances.contains(appliance)) {
            appliances.add(appliance);
        }
    }

    public void removeAppliance(Appliance appliance) {
        if (appliances.contains(appliance)) {
            appliances.remove(appliance);
        }
    }

    public int getTotalAppliancesInHome() {

        int total = 0;
        for (int i = 0; i < appliances.size(); i++) {
            total++;
        }
        
        return total;
    }

    public void turnOnAllAppliances() {
        for (int i = 0; i < appliances.size(); i++) {
            appliances.get(i).turnOn();
        }
    }

    public void turnOffAllAppliances() {
        for (int i = 0; i < appliances.size(); i++) {
            appliances.get(i).turnOff();
        }
    }
}

class Appliance {

    private final int id;               // unique identifier for each appliance
    private String brand;
    private double powerConsumption;
    private boolean isOn;               // tracks whether the appliance is currently ON or OFF
    private static int nextId = 1;      // static variable used to generate unique IDs

    // constructor
    public Appliance(String brand, double powerConsumption) {
        this.id = nextId;
        nextId++;
        this.brand = brand;
        this.powerConsumption = powerConsumption;
        this.isOn = false;
    }

    // methods
    public int getId() {
        return this.id;
    }

    void turnOn() {
        if (!this.isOn) {
            this.isOn = true;
            System.out.printf("Turning on %s appliance (ID: %d)\n", this.brand, this.id);
        } else {
            System.out.printf("%s appliance (ID: %d) is already ON\n", this.brand, this.id);
        }
    }

    void turnOff() {
        if (this.isOn) {
            this.isOn = false;
            System.out.printf("Turning off %s appliance (ID: %d)\n", this.brand, this.id);
        } else {
            System.out.printf("%s appliance (ID: %d) is already OFF\n", this.brand, this.id);
        }
    }

    public boolean isOn() {
        return this.isOn;
    }

    // getters and setters
    public String getBrand() {
        return this.brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public double getPowerConsumption() {
        return this.powerConsumption;
    }

    public void setPowerConsumption (double powerConsumption){
        if (powerConsumption <= 0) {
            System.out.println("Invalid value. Must be positive.");
        } else {
            this.powerConsumption = powerConsumption;
        }
    }
}

class WashingMachine extends Appliance {
    private int drumSize;

    // constructor
    public WashingMachine(String brand, double powerConsumption, int drumSize) {
        super(brand, powerConsumption);
        this.drumSize = drumSize;
    }

    // getter and setter
    public int getDrumSize(){
        return this.drumSize;
    }

    public void setDrumSize(int drumSize) {
        if (drumSize < 0) {
            System.out.println("Invalid value. Must be positive.");
        } else {
            this.drumSize = drumSize;
        }
    }

    // method
    void washClothes() {
        if (!this.isOn()) {
            System.out.println("Cannot wash clothes. The washing machine is OFF.");
        } else {
            System.out.printf("Washing clothes in a %s washing machine\n", getBrand());
        }
    }
}

class Refrigerator extends Appliance {
    private double temperature;

    // constructor
    public Refrigerator(String brand, double powerConsumption, double temperature) {
        super(brand, powerConsumption);
        this.temperature = temperature;
    }

    // getter and setter
    public double getTemperature() {
        return this.temperature;
    }

    public void setTemperature(double temperature) {
        this.temperature = temperature;
    }

    // method
    void coolItems() {
        if(this.isOn()) {
            System.out.printf("Cooling items in %s refrigerator at %.1f°C (ID: %d)\n", getBrand(), this.temperature, getId());
        } else {
            System.out.println("Cannot cool items. The refrigerator is OFF.");
        }
    }
}

class SmartWashingMachine extends WashingMachine {
    private boolean hasWiFi;

    // constructor
    public SmartWashingMachine(String brand, double powerConsumption, int drumSize, boolean hasWiFi) {
        super(brand, powerConsumption, drumSize);
        this.hasWiFi = hasWiFi;
    }

    // methods
    void connectToWiFi() {
        if (this.isOn()) {
            System.out.printf("Smart Washing Machine (ID: %d) connected to WiFi.\n", getId());
        } else {
            System.out.println("Cannot connect to WiFi. The machine is OFF.");
        }
    }

    public boolean hasWiFi() {
        return this.hasWiFi;
    }
}
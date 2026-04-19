import java.util.LinkedList;
import java.util.Queue;

class Passenger {
    private String name;
    private String destination;

    public Passenger(String name) {
        this.name = name;
    }

    public void requestRide(String destination, DispatchCenter dispatchCenter) {
        this.destination = destination;
        System.out.println("Passenger " + name + " requested a ride to " + destination + ".");
        dispatchCenter.requestRide(this);
    }

    public String getName() {
        return name;
    }

    public String getDestination() {
        return destination;
    }
}

public class Taxi {
    private String taxiId;
    private boolean available;
    private DispatchCenter dispatchCenter;
    private Passenger currentPassenger;

    public Taxi(String taxiId) {
        this.taxiId = taxiId;
        this.available = false;
    }

    public void setDispatchCenter(DispatchCenter dispatchCenter) {
        this.dispatchCenter = dispatchCenter;
    }

    public void setAvailable(boolean available) {
        this.available = available;

        if (available) {
            System.out.println("Taxi " + taxiId + " is now available.");
            dispatchCenter.taxiAvailable(this);
        }
    }

    public void assignPassenger(Passenger passenger) {
        this.currentPassenger = passenger;
        this.available = false;
    }

    public void respondToRide(boolean accepted) {
        if (currentPassenger == null) {
            return;
        }

        if (accepted) {
            System.out.println("Taxi " + taxiId + " accepted the ride to " + currentPassenger.getDestination() + ".");
            currentPassenger = null;
        } else {
            System.out.println("Taxi " + taxiId + " rejected the ride to " + currentPassenger.getDestination() + ". Searching for another taxi...");
            Passenger rejectedPassenger = currentPassenger;
            currentPassenger = null;
            dispatchCenter.handleRejectedRide(this, rejectedPassenger);
        }
    }

    public String getTaxiId() {
        return taxiId;
    }

    public boolean isAvailable() {
        return available;
    }
}

class DispatchCenter {
    private Queue<Passenger> passengerQueue = new LinkedList<>();
    private Queue<Taxi> taxiQueue = new LinkedList<>();

    public void registerTaxi(Taxi taxi) {
        taxi.setDispatchCenter(this);
    }

    public void requestRide(Passenger passenger) {
        passengerQueue.add(passenger);
        assignTaxi();
    }

    public void taxiAvailable(Taxi taxi) {
        taxiQueue.add(taxi);
        assignTaxi();
    }

    public void handleRejectedRide(Taxi rejectingTaxi, Passenger passenger) {
        taxiQueue.add(rejectingTaxi);
        passengerQueue.add(passenger);
        assignTaxi();
    }

    private void assignTaxi() {
        while (!passengerQueue.isEmpty() && !taxiQueue.isEmpty()) {
            Passenger passenger = passengerQueue.poll();
            Taxi taxi = taxiQueue.poll();

            taxi.assignPassenger(passenger);
            System.out.println("Dispatch assigned Taxi " + taxi.getTaxiId() + " to passenger " + passenger.getName() + ".");
        }
    }
}
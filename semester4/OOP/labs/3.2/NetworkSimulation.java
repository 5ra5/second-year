import java.util.*;

class CellTower {
    private String id;
    private int x;
    private int y;
    private int coverageRadius;
    private Set<Operator> supportedOperators;
    private Set<Client> connectedClients;

    public CellTower(String id, int x, int y, int coverageRadius) {
        this.id = id;
        this.x = x;
        this.y = y;
        this.coverageRadius = coverageRadius;
        this.supportedOperators = new HashSet<>();
        this.connectedClients = new HashSet<>();
    }

    public String getId() {
        return id;
    }

    public int getConnectedClientCount() {
        return connectedClients.size();
    }

    public void addSupportedOperator(Operator operator) {
        supportedOperators.add(operator);
    }

    public boolean supportsOperator(Operator operator) {
        return supportedOperators.contains(operator);
    }

    public void addClient(Client client) {
        connectedClients.add(client);
    }

    public void removeClient(Client client) {
        connectedClients.remove(client);
    }

    public boolean isInRange(int clientX, int clientY) {
        return getDistanceTo(clientX, clientY) <= coverageRadius;
    }

    public double getDistanceTo(int clientX, int clientY) {
        int dx = clientX - x;
        int dy = clientY - y;
        return Math.sqrt(dx * dx + dy * dy);
    }
}

class Operator {
    private String name;
    private Set<Client> clients;
    private Set<CellTower> towers;

    public Operator(String name) {
        this.name = name;
        this.clients = new HashSet<>();
        this.towers = new HashSet<>();
    }

    public String getName() {
        return name;
    }

    public Set<Client> getClients() {
        return clients;
    }

    public void addClient(Client client) {
        clients.add(client);
    }

    public void removeClient(Client client) {
        clients.remove(client);
    }

    public void addTower(CellTower tower) {
        towers.add(tower);
    }

    public void removeTower(CellTower tower) {
        towers.remove(tower);
    }
}

class Client {
    private String phoneNumber;
    private int x;
    private int y;
    private Operator operator;
    private CellTower connectedTower;

    public Client(String phoneNumber, Operator operator, int x, int y) {
        this.phoneNumber = phoneNumber;
        this.operator = operator;
        this.x = x;
        this.y = y;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Operator getOperator() {
        return operator;
    }

    public CellTower getConnectedTower() {
        return connectedTower;
    }

    public void setLocation(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setOperator(Operator operator) {
        this.operator = operator;
    }

    public void setConnectedTower(CellTower tower) {
        this.connectedTower = tower;
    }
}

class Network {
    private Map<String, CellTower> towers;
    private Map<String, Operator> operators;
    private Map<String, Client> clients;

    public Network() {
        towers = new HashMap<>();
        operators = new HashMap<>();
        clients = new HashMap<>();
    }

    public void addOperator(String operatorName) {
        operators.putIfAbsent(operatorName, new Operator(operatorName));
    }

    public void addTower(String towerId, int x, int y, int coverageRadius) {
        towers.putIfAbsent(towerId, new CellTower(towerId, x, y, coverageRadius));
    }

    public void registerOperatorTower(String operatorName, String towerId) {
        Operator operator = operators.get(operatorName);
        CellTower tower = towers.get(towerId);

        if (operator == null || tower == null) {
            return;
        }

        operator.addTower(tower);
        tower.addSupportedOperator(operator);

        for (Client client : operator.getClients()) {
            reconnectClient(client);
        }
    }

    public void addClient(String phoneNumber, String operatorName, int x, int y) {
        Operator operator = operators.get(operatorName);
        if (operator == null) {
            return;
        }

        Client client = new Client(phoneNumber, operator, x, y);
        clients.put(phoneNumber, client);
        operator.addClient(client);
        reconnectClient(client);
    }

    public void removeClient(String phoneNumber) {
        Client client = clients.get(phoneNumber);
        if (client == null) {
            return;
        }

        disconnectClient(client);
        client.getOperator().removeClient(client);
        clients.remove(phoneNumber);
    }

    public void moveClient(String phoneNumber, int newX, int newY) {
        Client client = clients.get(phoneNumber);
        if (client == null) {
            return;
        }

        client.setLocation(newX, newY);
        reconnectClient(client);
    }

    public void changeOperator(String phoneNumber, String newOperatorName) {
        Client client = clients.get(phoneNumber);
        Operator newOperator = operators.get(newOperatorName);

        if (client == null || newOperator == null) {
            return;
        }

        disconnectClient(client);
        client.getOperator().removeClient(client);

        client.setOperator(newOperator);
        newOperator.addClient(client);

        reconnectClient(client);
    }

    public int getTowerClientCount(String towerId) {
        CellTower tower = towers.get(towerId);
        return tower == null ? 0 : tower.getConnectedClientCount();
    }

    public int getOperatorSubscriberCount(String operatorName) {
        Operator operator = operators.get(operatorName);
        return operator == null ? 0 : operator.getClients().size();
    }

    public void removeTower(String towerId) {
        CellTower tower = towers.get(towerId);
        if (tower == null) {
            return;
        }

        List<Client> affectedClients = new ArrayList<>();
        for (Client client : clients.values()) {
            if (client.getConnectedTower() == tower) {
                affectedClients.add(client);
            }
        }

        for (Operator operator : operators.values()) {
            operator.removeTower(tower);
        }

        towers.remove(towerId);

        for (Client client : affectedClients) {
            client.setConnectedTower(null);
            reconnectClient(client);
        }
    }

    public void printNoSignalCount() {
        for (Operator operator : operators.values()) {
            int count = 0;
            for (Client client : operator.getClients()) {
                if (client.getConnectedTower() == null) {
                    count++;
                }
            }
            System.out.println(operator.getName() + ": " + count + " phones without signal.");
        }
    }

    private void reconnectClient(Client client) {
        disconnectClient(client);

        CellTower bestTower = findBestTower(client);
        if (bestTower != null) {
            client.setConnectedTower(bestTower);
            bestTower.addClient(client);
        }
    }

    private void disconnectClient(Client client) {
        CellTower currentTower = client.getConnectedTower();
        if (currentTower != null) {
            currentTower.removeClient(client);
            client.setConnectedTower(null);
        }
    }

    private CellTower findBestTower(Client client) {
        CellTower bestTower = null;
        double bestDistance = Double.MAX_VALUE;

        for (CellTower tower : towers.values()) {
            if (!tower.supportsOperator(client.getOperator())) {
                continue;
            }

            if (!tower.isInRange(client.getX(), client.getY())) {
                continue;
            }

            double distance = tower.getDistanceTo(client.getX(), client.getY());

            if (bestTower == null || distance < bestDistance) {
                bestTower = tower;
                bestDistance = distance;
            } else if (Double.compare(distance, bestDistance) == 0 &&
                    tower.getConnectedClientCount() < bestTower.getConnectedClientCount()) {
                bestTower = tower;
            }
        }

        return bestTower;
    }
}

public class NetworkSimulation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Network network = new Network();

        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();

            if (command.isEmpty()) {
                continue;
            }

            switch (command) {
                case "ADD_OPERATOR":
                    network.addOperator(scanner.nextLine().trim());
                    break;

                case "ADD_TOWER": {
                    String towerId = scanner.nextLine().trim();
                    int x = Integer.parseInt(scanner.nextLine().trim());
                    int y = Integer.parseInt(scanner.nextLine().trim());
                    int coverageRadius = Integer.parseInt(scanner.nextLine().trim());
                    network.addTower(towerId, x, y, coverageRadius);
                    break;
                }

                case "REGISTER_OPERATOR_TOWER": {
                    String operatorName = scanner.nextLine().trim();
                    String towerId = scanner.nextLine().trim();
                    network.registerOperatorTower(operatorName, towerId);
                    break;
                }

                case "ADD_CLIENT": {
                    String phoneNumber = scanner.nextLine().trim();
                    String operatorName = scanner.nextLine().trim();
                    int x = Integer.parseInt(scanner.nextLine().trim());
                    int y = Integer.parseInt(scanner.nextLine().trim());
                    network.addClient(phoneNumber, operatorName, x, y);
                    break;
                }

                case "REMOVE_CLIENT":
                    network.removeClient(scanner.nextLine().trim());
                    break;

                case "MOVE_CLIENT": {
                    String phoneNumber = scanner.nextLine().trim();
                    int newX = Integer.parseInt(scanner.nextLine().trim());
                    int newY = Integer.parseInt(scanner.nextLine().trim());
                    network.moveClient(phoneNumber, newX, newY);
                    break;
                }

                case "CHANGE_OPERATOR": {
                    String phoneNumber = scanner.nextLine().trim();
                    String newOperatorName = scanner.nextLine().trim();
                    network.changeOperator(phoneNumber, newOperatorName);
                    break;
                }

                case "TOWER_CLIENT_COUNT":
                    System.out.println(network.getTowerClientCount(scanner.nextLine().trim()));
                    break;

                case "OPERATOR_SUBSCRIBER_COUNT":
                    System.out.println(network.getOperatorSubscriberCount(scanner.nextLine().trim()));
                    break;

                case "REMOVE_TOWER":
                    network.removeTower(scanner.nextLine().trim());
                    break;

                case "NO_SIGNAL_COUNT":
                    network.printNoSignalCount();
                    break;
            }
        }

        scanner.close();
    }
}
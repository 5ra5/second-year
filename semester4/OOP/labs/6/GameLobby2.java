import java.util.ArrayList;
import java.util.List;

interface Player {
    void joinGame();
    void leaveGame();
    void sendMessage(String message);
    void receiveMessage(String message);
    String getPlayerType();
    String getPlayerName();
}

abstract class AbstractPlayer implements Player {
    protected String name;
    protected GameLobby lobby;

    public AbstractPlayer(String name, GameLobby lobby) {
        this.name = name;
        this.lobby = lobby;
    }

    @Override
    public void sendMessage(String message) {
        lobby.sendMessage(message, this);
    }

    @Override
    public void receiveMessage(String message) {
        System.out.printf("[%s] received: \"%s\"%n", name, message);
    }

    @Override
    public String getPlayerName() {
        return name;
    }

    @Override
    public abstract String getPlayerType();
}

class HumanPlayer extends AbstractPlayer {
    public HumanPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public void joinGame() {
        lobby.registerPlayer(this);
    }

    @Override
    public void leaveGame() {
        lobby.removePlayer(this);
    }

    @Override
    public String getPlayerType() {
        return "HumanPlayer";
    }
}

class AIPlayer extends AbstractPlayer {
    public AIPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public void joinGame() {
        lobby.registerPlayer(this);
    }

    @Override
    public void leaveGame() {
        lobby.removePlayer(this);
    }

    @Override
    public String getPlayerType() {
        return "AIPlayer";
    }
}

class Spectator extends AbstractPlayer {
    public Spectator(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public void joinGame() {
        lobby.registerPlayer(this);
    }

    @Override
    public void leaveGame() {
        lobby.removePlayer(this);
    }

    @Override
    public String getPlayerType() {
        return "Spectator";
    }
}

class AdminPlayer extends AbstractPlayer {
    public AdminPlayer(String name, GameLobby lobby){
        super(name, lobby);
    }

    @Override
    public String getPlayerType() {
        return "AdminPlayer";
    }

     @Override
    public void joinGame() {
        lobby.registerPlayer(this);
    }

    @Override
    public void leaveGame() {
        lobby.removePlayer(this);
    }

    public void kickPlayer(String name){
        lobby.kickPlayer(name, this);
    }
}

class GameLobby {
    private List<Player> players;

    public GameLobby() {
        players = new ArrayList<>();
    }

    void registerPlayer(Player player) {
        players.add(player);
        System.out.printf("[GameLobby] %s %s has joined the lobby.%n", player.getPlayerType(), player.getPlayerName());
    }

    void removePlayer(Player player) {
        players.remove(player);
        System.out.printf("[GameLobby] %s %s has left the lobby.%n", player.getPlayerType(), player.getPlayerName());
    }

    void sendMessage(String message, Player sender) {
        if (sender.getPlayerType().equals("Spectator")) {
            System.out.println("[GameLobby] Spectators cannot send messages.");
            return;
        }

        System.out.printf("[%s] sends: \"%s\"%n", sender.getPlayerName(), message);
        System.out.printf("[GameLobby] Message from %s: \"%s\"%n", sender.getPlayerName(), message);

        for (Player p : players) {
            if (p != sender) {
                p.receiveMessage(message);
            }
        }
    }

    void startMatch() {
        List<Player> matchPlayers = new ArrayList<>();

        for (Player p : players) {
            if (p.getPlayerType().equals("HumanPlayer") || p.getPlayerType().equals("AIPlayer")) {
                matchPlayers.add(p);
            }
        }

        if (matchPlayers.size() < 2) {
            System.out.println("[GameLobby] Not enough players to start a match.");
            return;
        }

        System.out.print("[GameLobby] Starting game with players: ");
        for (int i = 0; i < matchPlayers.size(); i++) {
            System.out.print(matchPlayers.get(i).getPlayerName());
            if (i != matchPlayers.size() - 1) System.out.print(", ");
        }
        System.out.println();
    }

    void kickPlayer(String name, AdminPlayer admin){
        Player target = null;

        for (Player p : players) {
            if (p.getPlayerName().equals(name) && !p.getPlayerType().equals("AdminPlayer")){
                target = p;
                break;
            }
        }

        if(target != null) {
            System.out.printf("[GameLobby] Admin %s kicked %s %s from the lobby.\n",admin.getPlayerName(), target.getPlayerType(), target.getPlayerName());
            removePlayer(target);
        } else {
            System.out.printf("[GameLobby] Player %s not found./n",name);
        }
    }
}
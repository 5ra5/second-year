import java.util.ArrayList;
import java.util.List;

interface Player{
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

    public AbstractPlayer(String name, GameLobby lobby){
        this.name = name;
        this.lobby = lobby;
    }

    @Override
    public void sendMessage(String message) {
        this.lobby.sendMessage(message, this);
        System.out.printf("[%s] sends: \"%s\"%n", name, message);
    }

    public void receiveMessage(String message) {
        System.out.printf("[%s] received: \"%s\"%n", name, message);
    }

    public String getPlayerName(){
        return this.name;
    }

    public abstract String getPlayerType();
}

class HumanPlayer extends AbstractPlayer{

    // constructor
    public HumanPlayer(String name, GameLobby lobby){
        super(name, lobby);
    }

    @Override
    public void joinGame(){
        this.lobby.registerPlayer(this);
    }

    @Override
    public void leaveGame(){
        this.lobby.removePlayer(this);
    }

    @Override
    public String getPlayerType(){
        return "HumanPlayer";
    }
}

class AIPlayer extends AbstractPlayer{
    
    //constructor
    public AIPlayer(String name, GameLobby lobby){
        super(name, lobby);
    }

    @Override
    public void joinGame(){
        this.lobby.registerPlayer(this);
    }

    @Override
    public void leaveGame(){
        this.lobby.removePlayer(this);
    }

    @Override
    public String getPlayerType(){
        return "AIPlayer";
    }
}

class Spectator extends AbstractPlayer{
    
     //constructor
    public Spectator(String name, GameLobby lobby){
        super(name, lobby);
    }
    
    @Override
    public void joinGame(){
        this.lobby.registerPlayer(this);
    }

    @Override
    public void leaveGame(){
        this.lobby.removePlayer(this);
    }

    @Override
    public String getPlayerType(){
        return "Spectator";
    }
}

class GameLobby{
    private List<Player> players;

    // constructor
    public GameLobby() {
        players = new ArrayList<>();
    }

    void registerPlayer(Player player){
        players.add(player);
        System.out.printf("[GameLobby] %s %s has joined the lobby.%n", player.getPlayerType(), player.getPlayerName());
    }

    void removePlayer(Player player){
        players.remove(player);
        System.out.printf("[GameLobby] %s %s has left the lobby.%n", player.getPlayerType(), player.getPlayerName());
    } 

    void sendMessage(String message, Player sender){
        if(sender.getPlayerType().equals("Spectator")){
            System.out.println("[GameLobby] Spectators cannot send messages.");
            return;
        }else{
            for(Player p : players){
                if(p.getPlayerType() != "Spectator"){
                    players.get(i).receiveMessage(message);
                }
            }
            System.out.printf("[GameLobby] Message from %s: \"%s\"%n", sender.getPlayerName(), message);
        }
    }
}
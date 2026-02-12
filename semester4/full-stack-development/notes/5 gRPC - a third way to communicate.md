
sending text data:
-  over time, JSON is more efficient than XML, but we are still sending a lot of noise down the wire (byte for each character and there is a lot of useless bytes being sent - this is slower)

sending binary data:
-  much faster, sending 2 bits of data
-  gRPC - google Remote Procedure Call

in traditional RPC, maybe we can send the `calcuateage()` to a server and get the answer back from the server
```python
class Person:

	def __init__(self, name):
		self.name = name
	
	@rpc
	def calculateage(self):
		pass
		
	def sayHello(self):
		print(f"I'm {self.name}")
		
a = Person("Mike")
a.sayHello()
a.calculateage()
```

-  gRPC relies on coming up with a protocol, but we are structuring it in a contract which generates a code which converts data into binary which makes passing data much faster
-  communicating with a server incredibly quick (e.g. changing a position in a game, which changes the x, y coordinates in a server)
-  tick rate = time in which the computer sounds data to the server and the server updates the game and sends the data back to the computer
-  lagging = error in communication

contract (enum for websockets) - if 1 is sent, someone joined the chat etc
```
enum(
	JOIN_CHAT = 1,
	SENDS_MESSAGE = 2,
	READS_MESSAGE = 3
)
```

the version of this for gRPC
```proto
# define the communication pattern, what our rpc does
service Game {
	rpc Play(stream, PlayerAction) returns (stream GameUpdate);
}

enum Action {
	JOIN = 0;
	LEAVE = 1;
	.
	.
	.
}

message PlayerAction{
	string player_id = 1;
	Action action = 2;
	.
	.
	.
}

message PlayerState{
	string player_id = 1;
	# coordintes
	int32 x = 2;
	int32 y = 3;
	
}
```

after this run the command to read this file and generate code (serialise) to make this as efficient as possible (translating messages from binary to messages for you)

**4 stream patterns for gRPC**

| Pattern                     | Client sends       | Server sends       | Example                  |
| --------------------------- | ------------------ | ------------------ | ------------------------ |
| **Unary**                   | One message        | One message        | Get a player's score     |
| **Server streaming**        | One message        | Stream of messages | Subscribe to a live feed |
| **Client streaming**        | Stream of messages | One message        | Upload a batch of data   |
| **Bidirectional streaming** | Stream of messages | Stream of messages | Multiplayer game         |

-  now you go into the server itself - `server.py`
-  it has functions like tracking coordinates, applying moves (this has things like preventing overlap - two players can't be in the same square, physics rules etc), building updates, tick loop, game service, serve to start the server etc.

`client.py` = draws a grid in the terminal for the game
-  while the game is loading, we wait for the player action, avoid busy waiting
-  once we get the action, we start the appropriate functions

starting game server
```shell
uv run python server.py
uv run python client.py --player_id alice
```

-  A is being moved through the grid

```shell
uv run python server.py
uv run python client.py --player_id bob
```

now we see both bob and alice on the grid and their positions update almost instantly when they move
disadvantage to gRPC: less fluid than web sockets, can't add more stuff after making a contract and compiling files
 -  if you want to change something, you need to change the contract, recompile the file and add more code to the server and client


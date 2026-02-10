-  persistent communication channel - full duplex communication
-  full duplex = client and server have a constant connection
-  communication is always happening, and we are just waiting for an event to happen
-  done by web socket protocol
-  avoiding asking for updates every so often

## real time chat app

-  node.js application  - django and python can't handle this

```bash
npm init -y
```

-  node keeps everything together in package.json, unlike django where we have to manually edit the requirements.txt

```bash
nmp install express
```

```bash
nmp install ws
```

-  don't commit files that you get to git 

creating a public folder
```bash
mkdir public
```

```bash
touch index.js
```

-  node is great for real-time architectures, front-end stuff
-  not great for restful architectures (django is better for this)
```javascript
// index.js
const express = require('express');
const path = require('path');
const app = express();

const server = require('http').createServer(app);
const wss = new WebSocketServer({server});

app.use(express.static(path.join(__dirname, 'public')));

const clients = new Set();

// function (ws){}
wss.on('connection', (ws)=>{
	clients.add(ws);
	
	ws.send(JSON.stringify({type:'system', text:'Welcome to the WebSocket server!'}));
	broadcast({type:'system', text: 'A new client has connected!'}, ws);
	
	// if the connected cliend sends a message
	ws.on('message', (data)=>{
		const msg = JSON.parse(data);
		broadcast({type:'chat', name:msg.name, text: msg.text}, ws);
	})
	
	ws.on('close', () =>(
		clients.delete(ws);
		broadcast({type:'system', text: 'A client has disconnected!'}, ws);
	))
})

function broadcast(message, sender){
	const data = JSON.stringify(message);
	for (const of clients){
		...
	}
}
const PORT = process.env.port || 3000;

app.listen(PORT, () => {
	console.log('Server is running on port ${PORT}');
}
```

-  after this write HTML and CSS, JavaScript for front-end

run the server:
```bash
node index.js
```
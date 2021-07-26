# IMPLEMENTATION:

`server.cpp` is the file that implements the server side of the chat server as follows:

-   Creates a Socket and binds it to a predefined port.
-   Starts listening on the socket.
-   Accepts connections from the n number of clients.
-   Receives and displays text strings sent by multiple clients.

---

`client.cpp` is the file that implements the client side of the chat server as follows:

-   Creates a Socket and connects to the server via the predefined IP address of the server and port.
-   Creates a new IP address for every new client connected to server.
-   Accepts a text strings to be sent over to the server.
-   Receives text strings sent by other clients onto the server.

---

## Running the program:

Assuming the programs are compiled,

At server side:

    ./server

(The server should start listening for connections.)

At client side:

    ./client

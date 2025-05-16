# UDP_Demo

Demo of BSD sockets programs using UDP (datagram) protocol ... peers send/receive datagram messages to each other.

# Server:
    Creates a socket ... binds it.
    Waits for message from 'client' and echo's the message back ... that's all.
    Uses 'rcvFrom()' to receive message from client ... echo's back using 'sendTo()'
    Uses 'select()' to monitor socket for incoming messages.

# Client:
    Creates a socket ... sends message to 'server' ... waits for echo back.
    User types message at command-line
    Message is sent to 'server'
    Looks for 'echo' message
    Uses 'sendTo()' to send message ... uses 'rcvFrom()' to receive message.
    Uses 'select()' to monitor socket ... overkill since there's only one socket

# Usage:

     UDP_server.exe <port>

     UDP_client.exe <IP-addr-of-svr> <svr-port> <client-port>

# Example:

     UDP_server.exe 25555

     UDP_client.exe 127.0.0.1 25555 25556

# Build:

    make

# Clean:

    make clean

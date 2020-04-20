import zmq

context = zmq.Context()

# Socket to talk to server
print("Connecting to hello world server...")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

# Do 10 requests, waiting each time for a response
for request in range(10):
    print(f"Sending request {request}")
    socket.send_string("Hello")

    # Get the reply
    print(f"Awaiting reply {request} ...")
    message = socket.recv()
    decoded_message = float(message.decode("UTF-8").rstrip("\x00"))
    print(f"Received reply {request}: {decoded_message}")

#include <zmq.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

void reply_thread() {
	zmq::context_t ctx(1);
	zmq::socket_t sock(ctx, zmq::socket_type::rep);
	sock.bind("tcp://*:5555");
	while (true) {
		zmq::message_t request;
		sock.recv(&request);
		std::cout << "Received Hello" << std::endl;
		zmq::message_t reply(10);
		double number = 123.456;
		std::string number_str = std::to_string(number);
		memcpy((void *) reply.data(), number_str.c_str(), 10);
		sock.send(reply);
	}
	return;
}

int main() {
	std::thread thr(reply_thread);
	while (true) {
		std::cout << "Yay" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	return 0;
}


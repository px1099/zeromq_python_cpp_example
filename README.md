# zeromq_python_cpp_example
Example of using zeromq to communicate between a python program and a c++ program

## Setup
* Install cmake
```
sudo apt-get install cmake
```
* Install pyzmq for python
```
pip install pyzmq
```
* Install cppzmq for c++ (should be installed in a separate directory):
```
git clone https://github.com/zeromq/libzmq.git
cd libzmq
mkdir build
cd build
cmake ..
sudo make -j4 install
cd ../..
git clone https://github.com/zeromq/cppzmq.git
cd cppzmq
mkdir build
cd build
cmake -DCPPZMQ_BUILD_TESTS=OFF ..
sudo make -j4 install
```
* Compile the c++ program
```
cmake .
make
```
## Run the programs:
* In the 1st terminal: `./ZeroMQExample`
* In the 2nd terminal: `python zmq_client.py`
## References:
* [zeromq](https://zeromq.org/)
* [cppzmq](https://github.com/zeromq/cppzmq)
* [pyzmq](https://github.com/zeromq/pyzmq)
* [example from wonkoderverstaendige](https://gist.github.com/wonkoderverstaendige/7521416)
* [unknown CMake command "catch_discover_tests" issue](https://github.com/zeromq/cppzmq/issues/334)

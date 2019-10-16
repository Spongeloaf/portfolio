# Spongeloaf's Project Portfolio

### The Shape Sifter - Lego sorting machine 
![i](https://camo.githubusercontent.com/75789259a97372c03b6daad6cf308c240ec19da6/68747470733a2f2f692e696d6775722e636f6d2f4c3076664f54372e6a7067)

The Shape Sifter is a lego sorting machine utilizing a neural network, image processing software, a conveyor belt, and air jets. The software is written in C++ and Python. A desktop PC runs the python program that watches the conveyor belt via a webcam. When a part passes the webcam, the Arduino begins to track it's movement along the conveyor belt. A Picture of the part is then passed to a neural network, which classififes it, and assigns it to a bin. Once the part passes in front of the bin, the Arduino activates a pneumatic valve, and blows the part into the bin.

I wrote all of the python and C++ in this project, assembled the hardware, and trained a neural network using fast.ai. 

[Here's a link](https://github.com/Spongeloaf/the-shape-sifter) to the repo.

# 
### TAP Dancer - serial protocol converter
The TAP Dancer alows integration serial TAP output devices to non-TAP serial inputs. It hosts a Serial TAP server, receives messages from TAP output devices, and then strips the payload from the session. That payload is then transmitted as a plain serial text string to any serial input device. One example use is for connecting a popular wander prevention system (Which only provides Serial TAP output) to send alarm notifications to a call server which accepts non-TAP serial strings.

The TAP Dancer was intended to run on an Arduino Mega, however it could run on any embedded microcontroller with a C++ compiler and at least two serial ports.

All memory is pre-allocated where possible. The only dynamically allocated memory is the stack. The serial data is read into 8 pre-allocated buffers, each 256 bytes long. This is sufficient to hold the vast majority of TAP sessions, however the data can be flushed to the output port if the incoming messages exceed that limit. 

Like my other embedded projects, the primary objects exist as singletons in the global scope. Despite the audible gasps from the higher level programmers, the global scope is not polluted with variables and functions as all parameter variables exist in a dedicated namespace, available globally. Additionaly, good OOP practice is used in my classes; Variables are accessed through get/set memebers, and all implementations are private. Modern C++ features such as enum classes (vs. traditional enums) are used wherever appropriate.

Due to the nature of this project (A commission from my former employer), the source code is closed.

#
### MT Wallets Billing Suite - Python/SQLite tenant billing application
![i](https://camo.githubusercontent.com/e67db98fb58c1785eb81ed7c05e3023163ba5179/68747470733a2f2f692e696d6775722e636f6d2f4a3442335132732e706e67)

I wrote the MT Wallets Billing Suite to simplify the process of billing my tenants. The SQLite DB stores utility bills for each month, teneant profiles, and the resultant amounts of each month's utilities divided among the tenants. 

The program has a simple command line interface that is designed to be very quick to use. Once the utility bills and tenant list have been confirmed by the user, the suite will make PDF files and send them via email to the tenants.

[Here's a link](https://github.com/Spongeloaf/mt_wallets_billing) to the repo.

#
### Open Source Contributions
I recently began contributing to OpenRCT2, an open source re-implementation of Roller Coaster Tycoon 2. 
[Here's a link](https://github.com/OpenRCT2/OpenRCT2/pulls?utf8=%E2%9C%93&q=is%3Apr+author%3ASpongeloaf+) to my pull requests.
# Spongeloaf's Project Portfolio

### The Shape Sifter - Lego sorting machine 
![i](https://camo.githubusercontent.com/75789259a97372c03b6daad6cf308c240ec19da6/68747470733a2f2f692e696d6775722e636f6d2f4c3076664f54372e6a7067)

The Shape Sifter is a lego sorting machine utilizing a neural network, image processing software, a conveyor belt, and air jets. The software is written in C++ and Python. A desktop PC runs the python program that watches the conveyor belt via a webcam. When a part passes the webcam, the Arduino begins to track it's movement along the conveyor belt. A picture of the part is then passed to a neural network, which classififes it, and assigns it to a bin. Once the part passes in front of the bin, the Arduino activates a pneumatic valve, and blows the part into the bin.

I wrote all of the python and C++ in this project, assembled the hardware, and trained a neural network using fast.ai. 

[Here's a link](https://github.com/Spongeloaf/the-shape-sifter) to the repo, and here is a [video of it in action](https://www.youtube.com/watch?v=ZOox_HX_6eo).

#
### NoReset Mod for Art of Rally
<img src="https://staticdelivery.nexusmods.com/mods/3778/images/5/5-1668961215-1279930720.png">

I wrote a mod in C# for the game Art of Rally to prevent the car from resetting when you go off course. This allows players to explore terrain of the race course for fun. However the mod causes all events to be counted as DNF, so you cannot cheat the leaderboards by taking shortcuts. Check it out [on GitHub](https://github.com/Spongeloaf/NoResetMod_for_Art_Of_Rally) or [on Nexus Mods](https://www.nexusmods.com/artofrally/mods/5).

# 
### Hotlink - Universal Protocol Converter

The Hotlink is a real-time, universal telecommunications protocol converter. It translates messages in real-time from any of its supported protocols to any other. The Hotlink is a commercial product. Therefore the source code is closed.

The application currently supports the following: TAP, COMP2, ASM, NEC DMLS, Spectralink OAI, raw text, and more. Any of these can be sent/recevied over TCP, UDP, or serial connections. Protocols are implemented as abstract modules, making it easy to add new ones. It is intended for use in the telecommunications industry by system integrators where commercial telecom equipment needs to be integrated with alarm or messaging systems. 

Hotlink was written following two primary objectives: simplictiy and reliability. The application is incredibly light-weight; it sips memory, doesn't have a UI, needs no database, and runs as a service on Ubuntu and Windows 10/11. While running, all memory is pre-allocated where possible. Where not possible, (network interface buffers, for example) custom allocators are used to prevent memory fragmentation. Raw pointers are not used and modern C++ features are exploited, to keep the code clean and safe.

It is also very stable. It's been deployed at many commercial sites since 2019, running 24/7 to deliver alarm messages to staff devices. It has not expereicned a single failure, at any site, as of May 2023.

#
### MT Wallets Billing Suite - Python/SQLite tenant billing application
![i](https://camo.githubusercontent.com/e67db98fb58c1785eb81ed7c05e3023163ba5179/68747470733a2f2f692e696d6775722e636f6d2f4a3442335132732e706e67)

I wrote the MT Wallets Billing Suite to simplify the process of billing my room mates. The SQLite DB stores utility bills for each month, tenant profiles, etc. The program has a simple command line interface for entering each months utility bills. Finally, the program will generate PDF files and send them via email to the tenants.

[Here's a link](https://github.com/Spongeloaf/mt_wallets_billing) to the repo.


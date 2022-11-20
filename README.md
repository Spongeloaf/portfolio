# Spongeloaf's Project Portfolio

### The Shape Sifter - Lego sorting machine 
![i](https://camo.githubusercontent.com/75789259a97372c03b6daad6cf308c240ec19da6/68747470733a2f2f692e696d6775722e636f6d2f4c3076664f54372e6a7067)

The Shape Sifter is a lego sorting machine utilizing a neural network, image processing software, a conveyor belt, and air jets. The software is written in C++ and Python. A desktop PC runs the python program that watches the conveyor belt via a webcam. When a part passes the webcam, the Arduino begins to track it's movement along the conveyor belt. A Picture of the part is then passed to a neural network, which classififes it, and assigns it to a bin. Once the part passes in front of the bin, the Arduino activates a pneumatic valve, and blows the part into the bin.

I wrote all of the python and C++ in this project, assembled the hardware, and trained a neural network using fast.ai. 

[Here's a link](https://github.com/Spongeloaf/the-shape-sifter) to the repo.

#
### NoReset Mod for Art of Rally
<img src="https://staticdelivery.nexusmods.com/mods/3778/images/5/5-1668961215-1279930720.png">
I wrote a mod in C# for the game Art of Rally to prevent the car from resetting when you go off ocurse. This allows players to explore terrain of the race course for fun. However the mod causes all events to be counted as DNF, so you cannot cheat the leaderboards by taking shortcuts. Check it out [on GitHub](https://github.com/Spongeloaf/NoResetMod_for_Art_Of_Rally) or [on Nexus Mods](https://www.nexusmods.com/artofrally/mods/5).

# 
### Hotlink - Univrsal Protocol Converter

The Hotlink is a real-time, universal telecommunications protocol converter. It translates messages in real-time from any of its supported protocols to any other. The application currently supports TAP, COMP2, ASM, NEC DMLS, raw text, and more. Any of these can be sent/recevied over TCP, UDP, or serial connections. Support for more protocols is easy and fast to implement. It is intended for use in the telecommunications industry by system integrators where commercial telecomm equipment needs to be integrated with alarm or messing systems. 

The Hotlink is a commercial product. Therefore the source code is closed. If you're interested in how it was designed, here is brief summary:

Hotlink was written following two primary objectives: Simplictiy and reliability. The application is incredibly light-weight; it sips memeory, doesn't have a UI, needs no database, and runs as a service on Ubuntu and Windows 10/11. It is also very stable. Raw pointers and heap allocation are never used in the application post-startup. While running, all memory is pre-allocated where possible. Where not possible, (network interface buffers, for example) custom allocators are used to prevent memory fragmentation. Raw pointers are not used anywhere in the code, post-startup. Modern C++ features are exploited to keep the code clean and safe.

#
### MT Wallets Billing Suite - Python/SQLite tenant billing application
![i](https://camo.githubusercontent.com/e67db98fb58c1785eb81ed7c05e3023163ba5179/68747470733a2f2f692e696d6775722e636f6d2f4a3442335132732e706e67)

I wrote the MT Wallets Billing Suite to simplify the process of billing my room mates. The SQLite DB stores utility bills for each month, tenant profiles, etc. The program has a simple command line interface for entering each months utility bills. Finally, the program will generate PDF files and send them via email to the tenants.

[Here's a link](https://github.com/Spongeloaf/mt_wallets_billing) to the repo.


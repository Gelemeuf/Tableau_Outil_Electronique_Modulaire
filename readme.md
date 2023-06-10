# Tableau Outil Electronique Modulaire

This part is made to connect interface laboratory instrument to a rapsberry with a web interface to control and have a view into every intrument.
It could be install into a computer to connect every intrument for example in USB.

This soft can be used with the backend TOEM_back. This backend work with TOEM_front a web interface. TOEM_back and TOEM_front should be installed into the same server and TOEM_periph on each computer connected to intruments.

## Software Architecture

├── config.sh
├── install.sh
├── launch.sh
├── LICENSE
├── Makefile
├── obj
│   ├── toem_HANMATEK_HM310T
│   │   ├── inc
│   │   │   └── main.h
│   │   ├── Makefile
│   │   └── src
│   │       ├── main.c
│   │       └── speedtest.c
│   └── toem_HANTEK_6022BE
│       ├── inc
│       │   └── main.h
│       ├── Makefile
│       └── src
│           └── main.c
├── readme.md
└── src
    ├── config
    │   ├── config.c
    │   ├── config.h
    │   └── Makefile
    ├── keepAlive
    │   ├── keepAlive.c
    │   ├── keepAlive.h
    │   ├── Makefile
    │   └── map.yaml
    └── mux
        ├── Makefile
        ├── mux.c
        ├── muxconfig.yaml
        └── mux.h

### Config.sh

An interface to configure everything with terminal
-Network interface configuration
-Peripherals configuration

### Install.sh

Quick auto installation of everything
-Auto start with linux
-Auto config of network interface
-Auto compile every part 

### Launch.sh

Script for launch the system manually or on start of linux 
(If config and install not done will not be accessible by network interface and not compiled 
could be compiled and config manually if needed)

## Configuration

## Creation of libraries




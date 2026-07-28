# Snake

#### General

![License](https://img.shields.io/badge/License-MIT-%23f34b7d.svg?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-2.3.2-%23f34b7d.svg?style=for-the-badge)

#### Languages

![C++](https://img.shields.io/badge/c++-%23f34b7d.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C](https://img.shields.io/badge/C-gray?style=for-the-badge&logo=c&logoColor=white)

![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white)

### Description

A small, terminal-based Snake game.

### Building, Running, Cleaning

This program uses the CMake build system. It can manually be build and run using:

```bash
cmake -S . -B build
cmake --build build
./build/snake
```

There also exists a Dockerfile. With that, a Docker image can be build and run in a container. For that, make sure to run the docker container with the container below. The `-it` argument is needed as argument, so that the container has an interactive terminal attached:

```bash
docker run -it <image>
```


### Requirements

No specific requirements, besides `g++` `cmake` and `build-essential`.

---

The changelog can be found [here](docs/Changelog.md)

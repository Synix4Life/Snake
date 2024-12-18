# Snake

![License](https://img.shields.io/badge/License-MIT-%2300599C.svg?style=for-the-badge)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-%2300599C.svg?style=for-the-badge&logo=make&logoColor=white)
![Version](https://img.shields.io/badge/Version-2.0-%2300599C.svg?style=for-the-badge)

![Bugs](https://img.shields.io/badge/Known_Bugs-2-%2300599C.svg?style=for-the-badge)
![Test](https://img.shields.io/badge/Tests_Passed-0/0-%2300599C.svg?style=for-the-badge)

### Description

A small, terminal- based Snake game.

### Building, Running, Cleaning

You have two options to run this program.

#### 1.

Compile it youreself and run it with:

```bash
g++ -fopemp -o <youre-name> main.cpp
./<youre-name>
```

#### 2.

Use the provided makefile.

Compile it using the command:

```bash
make
```

After that, you can run it by using

```bash
make run
```

For more information and cusomization, please refer to: 

```bash
make help
```

#### Cleaning

Clean it using

```bash
make clean
```


### Requirements

This program can use OpenMP to multithread.

Therefore, it should be installed on youre system. However, you can also play this game sequential (default).

---

### Known Bugs

1. apple\_pos() somtimes delivers useless positions
2. Drawing on collision partially incorrect (on wall & snake collision)

### Changelog

- $\textsf{\color{#4F8BBF}Version 1.0}$
  - Initial Upload with the necessary features

- $\textsf{\color{#4F8BBF}Version 2.0}$
  - Snake Collision added
  - Runtime improvement using OpenMP
  - Makefile added
  - Customization using command- line inputs

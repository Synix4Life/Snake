# Snake

#### General

![License](https://img.shields.io/badge/License-MIT-%23f34b7d.svg?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-2.2.0-%23f34b7d.svg?style=for-the-badge)

#### Languages

![C++](https://img.shields.io/badge/c++-%23f34b7d.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C](https://img.shields.io/badge/C-gray?style=for-the-badge&logo=c&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-%23008FBA.svg?style=for-the-badge&logo=make&logoColor=white)

#### Dev

![Bugs](https://img.shields.io/badge/Known_Bugs-0-%23f34b7d.svg?style=for-the-badge)
![Test](https://img.shields.io/badge/Tests_Passed-0/0-%23f34b7d.svg?style=for-the-badge)

### Description

A small, terminal-based Snake game.

### Building, Running, Cleaning

You have two options to run this program.

#### 1.

Compile it yourself and run it with:

```bash
g++ -o <youre-name> main.cpp src/Snake.cpp src/Field.cpp
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

For more information and customization, please refer to: 

```bash
make help
```

#### Cleaning

Clean it using

```bash
make clean
```

### Requirements

No specific requirements

---

### Changelog

- $\textsf{\color{#f34b7d}Version 1.0}$
  - Initial Upload with the necessary features

- $\textsf{\color{#f34b7d}Version 2.0}$
  - Snake Collision added
  - Runtime improvement using OpenMP
  - Makefile added
  - Customization using command-line inputs

    - $\textsf{\color{#f34b7d}Version 2.0.1}$
      - README fixes
    - $\textsf{\color{#f34b7d}Version 2.0.2}$
      - Small fixes
  - $\textsf{\color{#f34b7d}Version 2.1.0}$
    - 'Drawing Collision Error' fixed
    - Makefile improvement -> Build and executable files now in a separate directories
    - Readability improvement by creating corresponding cpp files
  - $\textsf{\color{#f34b7d}Version 2.2.0}$
    - Removed parallalism (redundant)
    - Fixed apple_pos delivering useless position
    - Added mt19937 random algorithm for better randomness

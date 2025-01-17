# :fire: :point_right: **Basic Calculator with SFML** :point_left: :fire:

This project is a **simple calculator** built using C++ and the **SFML** (Simple and Fast Multimedia Library). It serves as a way to **refresh the fundamentals of C++**, including object-oriented programming, event handling, GUI design, and high-precision arithmetic using **Boost Multiprecision**.

## **Table of Contents**
1. [Purpose](#purpose)
2. [Features](#features)
3. [Learning Outcomes](#learning-outcomes)
4. [Technology Stack](#technology-stack)
5. [Project Structure](#project-structure)
6. [Installation](#installation)
7. [Usage](#usage)
8. [Debugging Mode](#debugging-mode)
9. [Contributing](#contributing)
10. [Acknowledgments](#acknowledgments)
11. [License](#license)


## :one: **Purpose**

The main purpose of this project is to:
- Revisit and practice **core C++ concepts**.
- Work with **SFML** for creating graphical user interfaces.
- Explore **Boost Multiprecision** for handling high-precision arithmetic.
- Reinforce problem-solving techniques through tasks like parsing expressions, converting to RPN, and evaluating mathematical operations.


## :two: **Features**

- **Basic Arithmetic Operations**: Addition, subtraction, multiplication, and division.
- **High Precision Calculations**: Utilizes Boost Multiprecision for accuracy beyond standard `double` types.
- **Interactive GUI**:
    - Buttons for numbers and operations (`+`, `-`, `*`, `/`).
    - Real-time display updates for user input and results.
- **Keyboard and Mouse Support**:
    - Use the GUI buttons or keyboard shortcuts for input.
    - Supports special keys like `Backspace`, `Enter`, and `Escape`.
- **Debug Mode**:
    - Logs tokenization, RPN conversion, and evaluation steps to the console.


## :three: **Learning Outcomes**

Through this project, you can practice and learn:
1. **C++ Basics**:
    - Object-oriented design with classes like `App`, `Button`, `Calculator`, and `Display`.
    - Memory management (e.g., smart pointers with `std::unique_ptr`).
2. **Event-Driven Programming**:
    - Handling mouse and keyboard inputs with SFML.
3. **Algorithm Design**:
    - Implementing and using algorithms like **Shunting-Yard** and **RPN Evaluation**.
4. **Precision Arithmetic**:
    - Using Boost Multiprecision to perform high-accuracy floating-point operations.
5. **Debugging and Testing**:
    - Adding debug logs to understand internal program states.


## :four: **Technology Stack**

- **Language**: C++17
- **Graphics Framework**: [SFML](https://www.sfml-dev.org/)
- **Precision Library**: [Boost Multiprecision](https://www.boost.org/doc/libs/release/libs/multiprecision/)
- **Build System**: CMake
- **Platform**: Cross-platform (Linux (Manjaro))
- **IDE**: CLion


## :five: **Project Structure**

```
basic-calculator-sfml/
│
├── include/                 # Header files
│   ├── App.h                # Main application class
│   ├── Button.h             # Button component for UI
│   ├── Calculator.h         # Core calculator logic
│   ├── Display.h            # Display component for results
│   └── Config.h             # Configuration settings (colors, sizes, etc.)
│
├── src/                     # Source files
│   ├── App.cpp              # Implements App class
│   ├── Button.cpp           # Implements Button class
│   ├── Calculator.cpp       # Implements Calculator logic
│   ├── Display.cpp          # Implements Display rendering
│   └── main.cpp             # Entry point for the application
│
├── assets/                  
│   └── fonts/               # Fonts used in the application
│       ├── DejaVuSans.ttf  
│       └── DejaVuSans-Bold.ttf   
│
├── CMakeLists.txt           # CMake build script
├── LICENSE.txt              # License
└── README.md                # Project documentation
```

## :six: **Instalation**

### **Prerequisites**
1. **C++20**.
2. **CMake** (minimum version 3.30).
3. **SFML** library.
4. **Boost** library.
5. An IDE like **CLion** for easy setup and debugging.

## :one::one: **License** 
This project is licensed under the MIT License. See the LICENSE file for details.
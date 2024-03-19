<div align="center">

# Technical Specification

---
**Title:** Sportshield Project - Team 3

**Author:** Abderrazaq MAKRAN

**Team:** Team 3

**Reviewer(s):** Salaheddine NAMIR

**Created on:** March 13<sup>th</sup>, 2024

**Last updated:**  March 18<sup>th</sup>, 2024

---

### Approvals

| Reviewer           | Role              | Approved | Date       |
| ------------------ | ----------------- | -------- | ---------- |
| Salaheddine NAMIR  | Quality Assurance |          | 26/03/2024 |
| Mouatassime SEIV   | Project Manager   |          | 26/03/2024 |
| Pierre GORIN       | Program Manager   |          | 26/03/2024 |
| Abderrazaq MAKRAN  | Technical Leader  |          | 26/03/2024 |  
| Michel RIFF        | Technical Writer  |          | 26/03/2024 |
| Guillaume DESPAUX  | Software Engineer |          | 26/03/2024 |


</div>

<br><details>
<summary><h3 id="toc"> Table of Contents <i>(Click to expand)</i></h3></summary>


</details>


---

# 1 - Overview

## 1.1 - Purpose

[*(Back to top)*](#toc)

### 1.1.1 - Goals

Develop an innovative anti-theft device for sports equipment and expand its application to other sectors such as camping gear, musical instruments, and locker rooms.

Provide a reliable security solution for individual users of medium to high-end skis and snowboards.


### 1.1.2 - Objectives

The project objectives are as follow:

- Improve energy efficiency of the system.
- Management of a low battery situation.
- Increase the battery lifespan.
- NFC is an expected feature for the users, in order to activate/deactivate the anti-theft system & unlock the cable.
- Via their smartphone and SportShield app (redundant with Bluetooth function, to increase control options for users)
- Add the possibility to stop the alarm when it rings, even if the ringing cycle is not finished.
- Permit the alarm to ring while sending http notification to the server.
- Better management of interruptions
- Increase the security level to connect to the key features of the system

### 1.1.3 - Success Criteria

The project will be considered successful if the following criterias are met:

- Successful implementation and testing of the alarm system. 
- Secure physical locking mechanism preventing unauthorized access.
- Functioning mobile app with Bluetooth connectivity and GPS localization.
## 1.2 - Stakeholders

This project is for educational purposes and is intended for commercial use. The project team will be responsible for the development of the project and the client will be responsible for providing feedback and guidance throughout the development process.

### 1.2.1 - Project Team

| Name               | Role              | Github   |
| ------------------ | ----------------- | -------- |
| Salaheddine NAMIR  | Quality Assurance | [Salaheddine's Github](https://github.com/T3rryc)        |
| Mouatassime SEIV   | Project Manager   | [Mouatassime's Github](https://github.com/seiv007)       |
| Pierre GORIN       | Program Manager   | [Pierre's Github](https://github.com/Pierre2103)         |
| Abderrazaq MAKRAN  | Technical Leader  | [Abderrazaq's Github](https://github.com/Amakran2003)    |
| Michel RIFF        | Technical Writer  | [Michel's Github](https://github.com/MichelRiff)         |
| Guillaume DESPAUX  | Software Engineer | [Guillaume's Github](https://github.com/GuillaumeDespaux)|

### 1.2.2 - Client

| Name             | Role                 | Contact                                                         |
| ---------------- | -------------------- | --------------------------------------------------------------- |
| Coris Innovation | Client               | [Website](https://www.corisinnovation.com/coris-innovation)                             |
| Franck JEANNIN   | ALGOSUP's Co-Founder | [LinkedIn](https://www.linkedin.com/in/franck-jeannin/)         |
| Eric LARCHEVEQUE | ALGOSUP's Co-Founder | [LinkedIn](https://www.linkedin.com/in/ericlarch/)              |
| Natacha BOEZ     | ALGOSUP's Co-Founder | [LinkedIn](https://www.linkedin.com/in/natacha-boez-913a33167/) |

## 1.3 - Usage

[*(Back to top)*](#toc)

### 1.3.1 - Requirements
- [Arduino IDE](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjm4NzL6_OEAxVTUaQEHfAYB8MQmhN6BAhVEAI&url=https%3A%2F%2Ffr.wikipedia.org%2Fwiki%2FArduino&usg=AOvVaw36wKonvDZOyb7wbdqDRmEy&opi=89978449) - Arduino is an Italian open-source hardware and software company, project, and user community that designs and manufactures single-board microcontrollers and microcontroller kits for building digital devices. 
- [VS Code](https://code.visualstudio.com/download) - Visual Studio Code is a free source-code editor made by Microsoft for Windows, Linux and macOS.
- [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) - C/C++ for Visual Studio Code is an extension for VS Code that provides IntelliSense, debugging, and code browsing support for C and C++ code.
-

The software is developed using the 23<sup>rd</sup> version of the C++ language.


### 1.3.3 - Running

## 1.4 - Scope

[*(Back to top)*](#toc)

### 1.4.1 - In Scope

The project will include the following features:

- 
- 
- 

### 1.4.2 - Out of Scope

The project will not include the following features:
---

# 2 - Overall Description

## 2.1 System Architecture

[*(Back to top)*](#toc)

### 2.1.1 - Hardware

<!-- | Specification    | Lenovo ThinkBook 14  | Apple MacBook Air M1 2020 |
| ---------------- | -------------------- | ------------------------- |
| Processor        | Intel Core i7-1065G7 | Apple Silicon M1          |
| RAM[^15]         | 16 GB                |  8 GB                     |
| Operating System | Windows 11 Pro       | macOS Sonoma              | -->


|Name|Size|Specification|Image|
|--------------|-------|---------|--------|
|Xiao BLE Sense nrf52840|2 x 2 x 0,5 cm|- BLE 5.0 & 6 DoF IMU - 11 GPIO (UART, SPI, I2C)|![Xiao](Docs/Specifications/img/Capture d’écran 2024-03-18 à 17.15.29.png)|
|GNSS PA1010D|2,5 x 2,5 x 1 cm|- Integrated antenna - UART & I2C|![GNSS](Docs/Specifications/img/Capture d’écran 2024-03-18 à 17.15.41.png)|
| GSM/2G SIM800L Module | 2,2 x 1,8 x 0,5 cm | - GPRS & HTTP, UART - SIM Card holde -> With 1NCE SIM card | ![GSM](Docs/Specifications/img/Capture d’écran 2024-03-18 à 17.15.53.png) |
| Electromagnet | 2,7 x 1,6 x 1,3 cm | 12V, 500mA | |
| Piezoelectric buzzer | unknown | - 12V, avec oscillator control circuit - ~ 90-100 dB | |
| Lithium-Polymer battery | 5,1 x 3,5 x 0,6 cm | 3.7V, 1100mAh, 4.1Wh | |
| NFC antenna | 5,5 x 4,5 x 0,017 cm | 13,56MHz frequency | |


#### 2.2 - Software Components
- Programming Language: Arduino (C/C++) 
- IDE: Arduino IDE
- Main Software Files:
  - `original.ino`: Contains original code or primary logic for SportShield.
  - `batteryState.ino`: Manages battery state and consumption.
  - `bluetooth.ino`: Handles Bluetooth connectivity for the mobile app.
  - `gps.ino`: Implements GPS functionality for device localization.
  - `imu.ino`: Manages the Inertial Measurement Unit (IMU) for movement detection.
  - `nfc.ino`: Controls NFC functionality for device management.
  - `sim.ino`: Handles SIM card communication for GPRS connectivity.
  - `sounds.ino`: Implements sound generation for alarm and notifications.
  - `struct.h`: Contains data structures used across the software components.

## 2.2 - Project Folder Structure

[*(Back to top)*](#toc)

The project will be organized in the following folder structure:

```bash
~ 2023-2024-project-4-sportshield-team-3                     # 🌳 Root folder
|----- docs                                                  # 📁 Documentation folder
|     |--- Hardware                                             # 📁
|     |    |-- Batterie_LP603449.pdf                               # 📃
|     |    |-- CD-PA1010D-Datasheet-v.02.pdf                       # 📃
|     |    |-- SIM800L-SIMCom.pdf                                  # 📃 
|     |    |-- Seeed-Studio-XIAO-nRF52840-Sense-v1.1.pdf           # 📃
|     |    └── nRF52840_PS_v1.5.pdf                                # 📃
|     ├── Management                                            # 📁 Management folder
|     |    |--- Team-Management                                    # 📁 Team management folder
|     |    |    |-- RACI.md                                           # 📖
|     |    |--- Weekly-Reports                                     # 📁 Weekly reports folder
|     |    |    |-- Cumulative.md                                     # 📖
|     |    |    |-- Template.md#                                      # 📖
|     |    |    |-- Weekly-Report-1.md#                               # 📖
|     |    |    |-- Weekly-Report-2.md#                               # 📖
|     |    |    |-- Weekly-Report-3.md#                               # 📖
|     |    |    |-- Weekly-Report-4.md#                               # 📖
|     |    |    |-- Weekly-Report-5.md#                               # 📖
|     |    |    └── Weekly-Report-6.md#                               # 📖
|     |    |-- Project-Charter.md                                  # 📖 Project charter file
|     |    └── Risk-Management-Plan.md                             # 📖 Risk management plan file
|     └── Specifications                                        # 📁
|          |-- img                                                 # 📁 Images folder
|          |  |-- Functional-Specifications
|          |  |    |-- 1.png 
|          |  |    └── [etc...] 
|          |  |-- Technical-Specifications 
|          |  |    |-- 1.png 
|          |  |    └── [etc...] 
|          |  └──Test-Plan
|          |       |-- 1.png 
|          |       └── [etc...] 
|          |
|          |-- Functional-Specifications.md                     # 📖
|          |-- Technical-Specifications.md                      # 📖
|          └── Test-Plan.md                                     # 📖
|----- src                                                   # 📁
|        |-- struct.h                                           # 📄
|        └── SS_05-03_anglais-batterycontrol.ino                # 📝
|-- .gitignore                                               # 📖
|-- LICENSE.MD                                               # 📖
└── README.md                                                # 📖

```

**Legend:**
| 🌳          | 📁       | 📖        | 📃      | 📄           | 📝            | 🖼️     |
| ----------- | ------- | --------- | ------- | ------------ | ------------- | ------ |
| Root folder | Folders | Documents | PDF Files | Header Files | Arduino File | Images |


# 4 - End Matter

## 4.1 - Contributors
[*(Back to top)*](#toc)

|                                                                                                        Photos                                                                                                        |         Name          |                                                                     GitHub                                                                     |                                                                               LinkedIn                                                                                |
| :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-------------------: | :--------------------------------------------------------------------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| <img src="https://media.licdn.com/dms/image/C5603AQF4HZAk-2E6_g/profile-displayphoto-shrink_400_400/0/1660715651722?e=1716422400&v=beta&t=Y8iX2D3b1agoR57z2bGOah0L5KGhZ5RUgfUnCLpjQ4M" width="70px" height="70px"> | **Mouatassime SEIV**  |         [![GitHub](https://img.shields.io/badge/GitHub-seiv007-lightgrey?logo=github&style=flat-square)](https://github.com/seiv007)          |  [![LinkedIn](https://img.shields.io/badge/LinkedIn-Mouatassime_Seiv-blue?logo=linkedin&style=flat-square)](https://www.linkedin.com/in/moutassime-seiv-9542171a9/)   |
|                                                            <img src="https://avatars.githubusercontent.com/u/91249863?v=4" width="70px" height="70px">                                                             |   **Pierre GORIN**    |       [![GitHub](https://img.shields.io/badge/GitHub-Pierre2103-lightgrey?logo=github&style=flat-square)](https://github.com/Pierre2103)       |      [![LinkedIn](https://img.shields.io/badge/LinkedIn-Pierre_Gorin-blue?logo=linkedin&style=flat-square)](https://www.linkedin.com/in/pierre-gorin-61a784221/)      |
|                                                            <img src="https://avatars.githubusercontent.com/u/145991267?v=4" width="70px" height="70px">                                                            | **Abderrazaq MAKRAN** |      [![GitHub](https://img.shields.io/badge/GitHub-Amakran2003-lightgrey?logo=github&style=flat-square)](https://github.com/Amakran2003)      |      [![LinkedIn](https://img.shields.io/badge/LinkedIn-Abderrazaq_Makran-blue?logo=linkedin&style=flat-square)](https://www.linkedin.com/in/abderrazaq-makran/)      |
|                                                            <img src="https://avatars.githubusercontent.com/u/146001004?v=4" width="70px" height="70px">                                                            |    **Michel RIFF**    |       [![GitHub](https://img.shields.io/badge/GitHub-MichelRiff-lightgrey?logo=github&style=flat-square)](https://github.com/MichelRiff)       |       [![LinkedIn](https://img.shields.io/badge/LinkedIn-Michel_Riff-blue?logo=linkedin&style=flat-square)](https://www.linkedin.com/in/michel-riff-693007293/)       |
|                                                            <img src="https://avatars.githubusercontent.com/u/146001117?v=4" width="70px" height="70px">                                                            | **Guillaume DESPAUX** | [![GitHub](https://img.shields.io/badge/GitHub-GuillaumeDespaux-lightgrey?logo=github&style=flat-square)](https://github.com/GuillaumeDespaux) | [![LinkedIn](https://img.shields.io/badge/LinkedIn-Guillaume_Despaux-blue?logo=linkedin&style=flat-square)](https://www.linkedin.com/in/guillaume-despaux-084b10206/) |
|                                                            <img src="https://avatars.githubusercontent.com/u/71770514?v=4" width="70px" height="70px">                                                             | **Salaheddine NAMIR** |           [![GitHub](https://img.shields.io/badge/GitHub-T3rryc-lightgrey?logo=github&style=flat-square)](https://github.com/T3rryc)           | [![LinkedIn](https://img.shields.io/badge/LinkedIn-Salaheddine_Namir-blue?logo=linkedin&style=flat-square)](https://www.linkedin.com/in/salaheddine-namir-3402471b8/) |


## 4.2 - Related Documents

[*(Back to top)*](#toc)

|                        Document                         |                              Description                              |
| :-----------------------------------------------------: | :-------------------------------------------------------------------: |
| [Functional Specification](Functional-Specifications.md) | This document describes the functional specifications of the project. |
|                [Test Plan](Test-Plan.md)                |         This document describes the test plan of the project.         |
|                 [Readme](../../readme.md)                  |                 This document describes the project.                  |

## 4.3 - License

[*(Back to top)*](#toc)

This project is licensed under the MIT License - see the [LICENSE](/Users/abderrazaqmakran/Documents/2023-2024-project-4-sportshield-team-3/LICENSE.MD) file for details.

## 4.4 - References

[*(Back to top)*](#toc)

In this section, you will find all the tools and references used to create this document.

### 4.4.1 - Tools
- [Mermaid Live Editor](https://mermaid-js.github.io/mermaid-live-editor/)
- [Shield.io](https://shields.io/)

### 4.4.2 - References
- [Markdown Guide](https://www.markdownguide.org/cheat-sheet/)
- [Practical Guide to Writing Technical Specs](https://stackoverflow.blog/2020/04/06/a-practical-guide-to-writing-technical-specs/)

## 4.5 - Glossary

[*(Back to top)*](#toc)

<!-- |             Term              |                                                                                                                     Definition                                                                                                                      |                                                                                    What it means in this project                                                                                    |                              Additional Content                               |
| :---------------------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :---------------------------------------------------------------------------: |
|       **Processor[^1]**       |                                                                   A processor is the logic circuitry that responds to and processes the basic instructions that drive a computer.                                                                   |                                                             The processor is the virtual processor that will execute the assembly code.                                                             |      [Wikipedia](https://en.wikipedia.org/wiki/Central_processing_unit)       |
|      **Interpreter[^2]**      |       In computer science, an interpreter is a computer program that directly executes instructions written in a programming or scripting language, without requiring them previously to have been compiled into a machine language program.        |                                                            The interpreter is the virtual processor that will execute the assembly code.                                                            |      [Wikipedia](https://en.wikipedia.org/wiki/Interpreter_(computing))       |
|   **Assembly Language[^3]**   | An assembly language is a low-level programming language for a computer, or other programmable device, in which there is a very strong (generally one-to-one) correspondence between the language and the architecture's machine code instructions. |                                                      The assembly language is the language that will be interpreted by the virtual processor.                                                       |         [Wikipedia](https://en.wikipedia.org/wiki/Assembly_language)          |
|           **C[^4]**           |                                        C is a general-purpose, procedural computer programming language supporting structured programming, lexical variable scope, and recursion, with a static type system.                                        |                                                                       C is the language used to write the virtual processor.                                                                        |      [Wikipedia](https://en.wikipedia.org/wiki/C_(programming_language))      |
|  **Low-Level Language[^5]**   |                                                  A low-level programming language is a programming language that provides little or no abstraction from a computer's instruction set architecture.                                                  |                                                                           The assembly language is a low-level language.                                                                            |   [Wikipedia](https://en.wikipedia.org/wiki/Low-level_programming_language)   |
|       **Emulation[^6]**       |                                                   In computing, emulation refers to the ability of a computer program in an electronic device to emulate (or imitate) another program or device.                                                    |                                                                           The virtual processor will emulate a processor.                                                                           |              [Wikipedia](https://en.wikipedia.org/wiki/Emulator)              |
|      **Instruction[^7]**      |                                                                                   An instruction is an order given to a computer processor by a computer program.                                                                                   |                                                                         The assembly language is composed of instructions.                                                                          |   [Wikipedia](https://en.wikipedia.org/wiki/Instruction_(computer_science))   |
|   **Operating System[^8]**    |                                                   An operating system is system software that manages computer hardware, software resources, and provides common services for computer programs.                                                    |                                                              The operating system is the software that will run the virtual processor.                                                              |          [Wikipedia](https://en.wikipedia.org/wiki/Operating_system)          |
|  **Visual Studio Code[^9]**   |                                                                           Visual Studio Code is a free source-code editor made by Microsoft for Windows, Linux and macOS.                                                                           |                                                               Visual Studio Code is the IDE[^10] used to write the virtual processor.                                                               |         [Wikipedia](https://en.wikipedia.org/wiki/Visual_Studio_Code)         |
|         **IDE[^10]**          |                                           An integrated development environment (IDE) is a software application that provides comprehensive facilities to computer programmers for software development.                                            |                                                                 Visual Studio Code is the IDE used to write the virtual processor.                                                                  | [Wikipedia](https://en.wikipedia.org/wiki/Integrated_development_environment) |
|         **GCC[^11]**          |                                                  GCC, formerly an acronym for GNU Compiler Collection, is a compiler system produced by the GNU Project supporting various programming languages.                                                   |                                                                     GCC is the compiler used to compile the virtual processor.                                                                      |      [Wikipedia](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)       |
|       **Compiler[^12]**       |                                        A compiler is a computer program that translates computer code written in one programming language (the source language) into another language (the target language).                                        |                                                                     GCC is the compiler used to compile the virtual processor.                                                                      |              [Wikipedia](https://en.wikipedia.org/wiki/Compiler)              |
| **Performance Analysis[^13]** |                                   Performance analysis is the process of assessing the performance of a computer, comparing the performance of one or more systems, or evaluating the performance of a component.                                   |                                                     Performance analysis is the process of assessing the performance of the virtual processor.                                                      |  [Wikipedia](https://en.wikipedia.org/wiki/Profiling_(computer_programming))  |
|  **Memory Management[^14]**   |                               Memory management is the process of controlling and coordinating computer memory, assigning portions called blocks to various running programs to optimize overall system performance.                                |       Memory management is the process of controlling and coordinating computer memory, assigning portions called blocks to various running programs to optimize overall system performance.        |         [Wikipedia](https://en.wikipedia.org/wiki/Memory_management)          |
|         **RAM[^15]**          |                                              Random-access memory (RAM) is a form of computer memory that can be read and changed in any order, typically used to store working data and machine code.                                              |                                                                          RAM is the memory used by the virtual processor.                                                                           |        [Wikipedia](https://en.wikipedia.org/wiki/Random-access_memory)        |
|  **Naming Convention[^16]**   |                         A naming convention is a set of rules for choosing the character sequence to be used for identifiers which denote variables, types, functions, and other entities in source code and documentation.                         | A naming convention is a set of rules for choosing the character sequence to be used for identifiers which denote variables, types, functions, and other entities in source code and documentation. |  [Wikipedia](https://en.wikipedia.org/wiki/Naming_convention_(programming))   |
|       **Register[^17]**       |                                                      In computer architecture, a processor register is a quickly accessible location available to a computer's central processing unit (CPU).                                                       |                                                                     Registers are used by the virtual processor to store data.                                                                      |         [Wikipedia](https://en.wikipedia.org/wiki/Processor_register)         |
|         **Jump[^18]**         |                                                           In computer science, a jump statement is a statement that unconditionally transfers program control to a designated statement.                                                            |                                                         Jump statements are used by the virtual processor to change the flow of execution.                                                          |     [Wikipedia](https://en.wikipedia.org/wiki/Branch_(computer_science))      |
|       **Parsing[^19]**        |                  Parsing, syntax analysis, or syntactic analysis is the process of analyzing a string of symbols, either in natural language, computer languages or data structures, conforming to the rules of a formal grammar.                   |                                                                   Parsing is the process of analyzing the assembly language code.                                                                   |              [Wikipedia](https://en.wikipedia.org/wiki/Parsing)               |
|       **Operand[^20]**        |                                                    In mathematics and computer programming, an operand is the object of a mathematical operation, a quantity on which an operation is performed.                                                    |                                                            Operands are used by the virtual processor to perform arithmetic operations.                                                             |              [Wikipedia](https://en.wikipedia.org/wiki/Operand)               | -->

## 4.6 - Footnotes

[*(Back to top)*](#toc)

[^1]:  []()
[^2]:  []()
[^3]:  []()
[^4]:  []()
[^5]:  []()
[^6]:  []()
[^7]:  []()
[^8]:  []()
[^9]:  []()
[^10]: []()
[^11]: []()
[^12]: []()
[^13]: []()
[^14]: []()
[^15]: []()
[^16]: []()
[^17]: []()
[^18]: []()
[^19]: []()
[^20]: []()
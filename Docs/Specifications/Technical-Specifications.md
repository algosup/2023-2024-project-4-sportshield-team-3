<div align="center">

# Technical Specification

---
**Title:** Sportshield Project - Team 3

**Author:** Abderrazaq MAKRAN

**Team:** Team 3

**Reviewer(s):** Salaheddine NAMIR

**Created on:** March 13<sup>th</sup>, 2024

**Last updated:**  <sup>th</sup>, 2024

---

### Approvals

| Reviewer           | Role              | Approved | Date       |
| ------------------ | ----------------- | -------- | ---------- |
| Salaheddine NAMIR  | Quality Assurance |          | 02/09/2024 |
| Mouatassime SEIV   | Project Manager   |          | 02/09/2024 |
| Pierre GORIN       | Program Manager   |          | 02/09/2024 |
| Abderrazaq MAKRAN  | Technical Leader  |          | 02/09/2024 |  
| Michel RIFF        | Technical Writer  |          | 02/09/2024 |
| Guillaume DESPAUX  | Software Engineer |          | 02/09/2024 |


</div>

<br><details>
<summary><h3 id="toc"> Table of Contents <i>(Click to expand)</i></h3></summary>


</details>


---

# 1 - Overview

## 1.1 - Purpose

[*(Back to top)*](#toc)

### 1.1.1 - Goals

This project aims to develop a program for our client Coris innovation. Using the ressources given by the client, we have to code in C++ the program


### 1.1.2 - Objectives

The project objectives are as follow:

- Decrease the battery consumption 
- Increase the battery lifespan
- Implement the NFC locker
- Alarm management 

### 1.1.3 - Success Criteria

The project will be considered successful if the following criterias are met:

- The Sportshield can work for at least 4 days without charging it 
- The Sportshield detect the two different type of movement 
- 
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


### 1.3.2 - Installation

#### 1.3.2.1 - Installation with Bash

#### 1.3.2.2 - Installation with GitHub Desktop

### 1.3.3 - Running

## 1.4 - Scope

[*(Back to top)*](#toc)

### 1.4.1 - In Scope

The project will include the following features:

### 1.4.2 - Out of Scope

The project will not include the following features:
---

# 2 - Overall Description

## 2.1 System Environment

[*(Back to top)*](#toc)

### 2.1.1 - Hardware

<!-- | Specification    | Lenovo ThinkBook 14  | Lenovo ThinkBook 14  | Lenovo ThinkPad 2023 | Apple MacBook Air M1 2020 | Apple MacBook Air M1 2020 |
| ---------------- | -------------------- | -------------------- | -------------------- | ------------------------- | ------------------------- |
| Processor        | Intel Core i7-1065G7 | Intel Core i7-1165G7 | Intel Core i7-1355U  | Apple Silicon M1          | Apple Silicon M1          |
| RAM[^15]         | 16 GB                 | 16 GB                | 16 GB                 | 8 GB                      | 8 GB                      |
| Operating System | Windows 11 Pro       | Windows 11 Pro       | Windows 11 Pro       | macOS Ventura             | macOS Sonoma              | -->

### 2.1.2 - Software

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


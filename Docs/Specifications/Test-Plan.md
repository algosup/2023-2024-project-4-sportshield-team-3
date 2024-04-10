# Test Plan 2023-2024-project-4-sport shield-team-3

![GitHub Logo](https://img.shields.io/badge/-GitHub-181717?logo=github) ![Arduino Logo](https://img.shields.io/badge/-Arduino-00979D?logo=arduino&logoColor=white) ![C logo](https://img.shields.io/badge/-C-A8B9CC?logo=c&logoColor=white)  ![C++ Logo](https://img.shields.io/badge/-C++-00599C?logo=c%2B%2B&logoColor=white)
![Last Updated](https://img.shields.io/github/last-commit/algosup/2023-2024-project-4-sportshield-team-3/test-plan)
![GitHub issues](https://img.shields.io/github/issues/algosup/2023-2024-project-4-sportshield-team-3)
| Contributers        | Role              |GitHub|Photos|
| ----------------- | ----------------- | ----|---|
| Salaheddine NAMIR | **Quality Assurance** |  [![GitHub](https://img.shields.io/badge/GitHub-T3rryc-lightgrey?logo=github&style=flat-square)](https://github.com/T3rryc)  | <img src="https://avatars.githubusercontent.com/u/71770514?v=4" width="70px" height="70px">|
| Mouatassime SEIV  | **Project Manager**   |[![GitHub](https://img.shields.io/badge/GitHub-seiv007-lightgrey?logo=github&style=flat-square)](https://github.com/seiv007)  |  <img src="https://media.licdn.com/dms/image/C5603AQF4HZAk-2E6_g/profile-displayphoto-shrink_400_400/0/1660715651722?e=1716422400&v=beta&t=Y8iX2D3b1agoR57z2bGOah0L5KGhZ5RUgfUnCLpjQ4M" width="70px" height="70px"> |    
| Pierre GORIN      | **Program Manager**   |[![GitHub](https://img.shields.io/badge/GitHub-Pierre2103-lightgrey?logo=github&style=flat-square)](https://github.com/Pierre2103)       |  <img src="https://avatars.githubusercontent.com/u/91249863?v=4" width="70px" height="70px">     |
| Michel RIFF       | **Technical Writer**  | [![GitHub](https://img.shields.io/badge/GitHub-MichelRiff-lightgrey?logo=github&style=flat-square)](https://github.com/MichelRiff) |<img src="https://avatars.githubusercontent.com/u/146001004?v=4" width="70px" height="70px"> |         
| Guillaume DESPAUX | **Software Engineer** | [![GitHub](https://img.shields.io/badge/GitHub-GuillaumeDespaux-lightgrey?logo=github&style=flat-square)](https://github.com/GuillaumeDespaux) | <img src="https://avatars.githubusercontent.com/u/146001117?v=4" width="70px" height="70px"> |       
| Abderrazaq MAKRAN|**Technical Leader**|[![GitHub](https://img.shields.io/badge/GitHub-Amakran2003-lightgrey?logo=github&style=flat-square)](https://github.com/Amakran2003)|<img src="https://avatars.githubusercontent.com/u/145991267?v=4" width="70px" height="70px"> |
<details>
<summary>📖Table of Contents</summary>

1. [Introduction](#1-introduction)
    1. [Scope](#11-scope)
        1. [In Scope](#111-in-scope)
        2. [Out of Scope](#112-out-of-scope)
    2. [Quality Objective](#12-quality-objective)
    3. [Roles and Responsibilities](#13-roles-and-responsibilities)
2. [Test Methodology](#2-test-methodology)
    1. [Overview](#21-overview)
    2. [Test Levels](#22-test-levels)
    3. [Bug Triage](#23-bug-triage)
    4. [Suspension Criteria and Resumption Requirements](#24-suspension-criteria-and-resumption-requirements)
    5. [Test Completeness](#25-test-completeness)
3. [Test Deliverables](#3-test-deliverables)
4. [Resource & Environment Needs](#4-resource--environment-needs)
    1. [Testing Tools](#41-testing-tools)
    2. [Test Environment](#42-test-environment)
5. [Terms/Acronyms](#5-termsacronyms)

</details>

## 1 Introduction   
SportShield is a smart anti-theft device designed to protect sports equipment. Developed by Coris Innovation, a company specializing in systems and process engineering. The device features include choke sensors, theft alarms, GPS tracking, and remote lock/unlock functionality. The goal of the project is to improve battery consumption management, device management with NFC alarm management, and simultaneous actions. 

### 1.1  Scope

#### 1.1.1 In Scope
##### 1. Battery Consumption Management:

- Improve the energy efficiency of the system by implementing strategies such as turning on components only when needed and managing sleep modes effectively.
- Implement measures to handle low battery situations, ensuring skis are secured even when the battery is low.
- Increase battery lifespan by enforcing charging limits (e.g., no charge above 80% of Vmax) and discharge thresholds (e.g., no discharge under 20%).

##### 2. Device Management with NFC:

- Enable NFC functionality for users to activate/deactivate the anti-theft system and unlock the cable via their smartphone and SportShield app.

- Implement NFC functionality redundantly with Bluetooth to provide users with increased control options.
##### 3. Alarm Management and Simultaneous Actions:

- Add the capability to stop the alarm when it rings, regardless of whether the ringing cycle is completed.
- Enable the alarm to ring while simultaneously sending HTTP notifications to the server.
- Enhance interruption management for better user experience.


#### 1.1.2 Out of Scope
##### 1. Hardware Modifications:
- Changes or modifications to hardware components such as circuitry or electromagnets are not within the scope of this test plan.

##### 2. Advanced Connectivity Features:
- Introducing new connectivity features beyond NFC and Bluetooth, such as Wi-Fi or cellular connectivity, is out of scope for this phase of testing.

##### 3. User Interface Overhaul:

- Significant redesign or overhaul of the user interface beyond the necessary changes to accommodate new features is not within the scope of this test plan.
##### 4. Server-Side Changes:

- Modifications or enhancements to the server-side infrastructure beyond implementing HTTP notifications are not included in this test plan.
##### 5. Third-Party Integration:

- Integrating with third-party services or platforms beyond basic HTTP notifications is out of the scope of this test plan.
##### 6. Physical Design Changes:

- Alterations to the physical design of the device, such as size, shape, or material changes, are not part of this test plan.

### 1.2 Quality Objective

The primary objective of this test plan is to validate that the SportShield device functions as expected and meets all defined requirements. This includes ensuring that the device's battery management, NFC functionality, and alarm management features work correctly and provide a satisfactory user experience.

Specific quality objectives include:

- **Functionality**: The device should perform all its functions correctly, including battery management, NFC functionality, and alarm management.
- **Reliability**: The device should operate reliably under normal conditions, with minimal downtime or errors.
- **Usability**: The device should be easy to use, with clear instructions and intuitive controls.
- **Performance**: The device should respond quickly to user inputs and should manage its battery efficiently.
- **Security**: The device should securely handle user data and should not be susceptible to unauthorized access or control.

The testing process will aim to identify and resolve any issues that could affect these quality objectives. The ultimate goal is to ensure that the SportShield device provides a reliable, efficient, and user-friendly solution for protecting sports equipment.




### 1.3 Roles and Responsibilities 

The following roles and responsibilities are defined for the testing process:

- **Quality Assurance (QA)**: Responsible for overseeing the testing process, defining test strategies, and ensuring that the device meets quality standards.

- **Project Manager**: Responsible for coordinating the testing activities, managing resources, and ensuring that the project stays on schedule.

- **Program Manager**: Responsible for defining the overall project goals and objectives, including quality standards and testing requirements.

- **Technical Lead**: Responsible for providing technical guidance and support to the testing team, including reviewing test plans and results.

- **Technical Writer**: Responsible for documenting the testing process, including test plans, test cases, and test results.

- **Software Engineer**: Responsible for developing and implementing test cases, executing tests, and reporting defects.

Each team member will contribute to the testing process according to their role and responsibilities. Collaboration and communication among team members will be essential to ensure the success of the testing effort.





## 2 Test Methodology
In this section, we will describe the test methodology that will be used to validate the SportShield device. This includes an overview of the testing process, the different test levels that will be applied, bug triage procedures, and criteria for suspending and resuming testing activities.

### 2.1 Overview
The testing process will follow a structured approach to validate the SportShield device's functionality, reliability, usability, performance, and security. The testing activities will be organized into different levels, each focusing on specific aspects of the device's behavior. The test plan will include detailed test cases, test procedures, and expected results to ensure comprehensive coverage of all requirements.

Extreme Programming (XP) is a software development methodology that focuses on delivering high-quality software quickly and efficiently. It emphasizes collaboration, feedback, and continuous improvement to ensure that the final product meets customer requirements and expectations. XP is based on a set of core values and principles that guide the development process and help teams deliver value to customers. This method is a type of agile methodology that is well-suited for projects with changing requirements and tight deadlines.     

### 2.2 Test Levels

The testing process will be conducted at several levels to ensure comprehensive coverage of all aspects of the SportShield device. The test levels include:

1. **Unit Testing**: This level of testing will focus on individual components of the software. The goal is to ensure that each function or method works correctly in isolation. This will be the responsibility of the Software Engineers, who will write and execute these tests.

2. **Integration Testing**: After unit testing, the individual components will be combined and tested together. The aim is to identify any issues that arise when different parts of the software interact with each other. This will be overseen by the Technical Lead and executed by the Software Engineers.

3. **System Testing**: At this level, the entire system will be tested as a whole. This includes testing the software and hardware integration, as well as the complete functionality of the SportShield device. The Quality Assurance team will be responsible for this level of testing.

4. **Acceptance Testing**: The final level of testing is to ensure that the SportShield device meets all the defined requirements and is ready for release. This will involve testing the device in conditions that mimic real-world use to ensure it meets the needs and expectations of the end users. The Project Manager and Quality Assurance team will collaborate on this level of testing.

### 2.3 Bug Triage

Each level of testing will be documented, including the test cases, test results, and any identified and resolved issues. This will ensure transparency and traceability throughout the testing process.

During this phase, the team will prioritize the identified bugs based on their severity and impact on the system. The following criteria will be used to determine the priority of each bug

- **Identification**: The test plan will include a list of all identified bugs, including a description of the issue, steps to reproduce, and severity level. This will help the team track and prioritize bugs for resolution.
- **Categorization**: Bugs will be categorized based on their severity and impact on the system. This will help the team prioritize bug fixes and allocate resources effectively.
- **Prioritization**: The team will prioritize bugs based on their severity, impact on the system, and customer requirements. Critical bugs that affect core functionality will be addressed first, followed by less critical issues.
- **Assignment**: Each bug will be assigned to a team member responsible for resolving it. The team will collaborate to ensure that bugs are fixed in a timely manner and that the system meets quality standards. 
- **Verification**: Once a bug is fixed, the team will verify the resolution and retest the affected functionality to ensure that the issue has been resolved. This will help prevent regression and ensure that the system remains stable.
- **Closure**: Once a bug is verified and resolved, it will be marked as closed. The team will document the resolution and update the bug-tracking system to reflect the status of the bug. This will help track the progress of bug fixes and ensure that all issues are addressed before release.

All of these steps are reported on [GitHub issues](https://github.com/algosup/2023-2024-project-4-sportshield-team-3/issues) to ensure that the team is aware of the status of each bug and can collaborate effectively to resolve them.
A labeling system will be used to categorize and prioritize bugs based on their severity and impact on the system. This will help the team track and manage bugs effectively and ensure that critical issues are addressed promptly.

### 2.4 Suspension Criteria and Resumption Requirements



### 2.5 Test Completeness

All test cases will be executed and documented to ensure that the testing process is complete. The test plan will include a list of all test cases, along with their expected results and actual outcomes. This will help the team track the progress of testing and ensure that all requirements are met.
## 3 Test Deliverables

The following test deliverables will be produced as part of the testing process:
[Test Case](Test-Case.md)

## 4 Resource & Environment Needs

The testing process will require the following resources and environments to ensure that the SportShield device is thoroughly tested and validated. This includes testing tools, test environments, and other necessary resources.

### 4.1 Testing Tools
This following tools will be used to conduct the testing process:

**LightBlue app**: 
- A mobile application that allows users to interact with Bluetooth Low Energy (BLE) devices. This app will be used to test the SportShield device's Bluetooth functionality and ensure that it can communicate with other devices effectively.

**SportShield app**:
- A mobile application developed specifically for the SportShield device. This app will be used to test the device's NFC functionality and ensure that users can activate/deactivate the anti-theft system and unlock the cable using their smartphone.

### 4.2 Test Environment

The testing process will be conducted in a controlled environment to ensure that the SportShield device is tested under realistic conditions. The test environment will include the following components:

**Hardware Components**:
- The [SportShield device](https://github.com/algosup/2023-2024-project-4-sportshield-team-3/blob/main/Docs/Specifications/Technical-Specifications.md#31---hardware), including all sensors, actuators, and communication modules.
- A smartphone on Android with the LightBlue app installed to test Bluetooth functionality.
- A smartphone on Android with the SportShield app installed to test NFC functionality.
- [Computer](https://github.com/algosup/2023-2024-project-4-sportshield-team-3/blob/main/Docs/Specifications/Technical-Specifications.md#31---hardware) with internet access to test HTTP notifications and server-side functionality.

## 5 Terms/Acronyms 

|Terms|Definition|
|---|---|
|**XP**|Extreme Programming|
|**BLE**|Bluetooth Low Energy|
|**NFC**|Near Field Communication|
|**HTTP**|Hypertext Transfer Protocol|
|**QA**|Quality Assurance|






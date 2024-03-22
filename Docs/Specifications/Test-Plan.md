# Test Plan 2023-2024-project-4-sportshield-team-3

![GitHub Logo](https://img.shields.io/badge/-GitHub-181717?logo=github) ![Arduino Logo](https://img.shields.io/badge/-Arduino-00979D?logo=arduino&logoColor=white) ![C logo](https://img.shields.io/badge/-C-A8B9CC?logo=c&logoColor=white)  ![C++ Logo](https://img.shields.io/badge/-C++-00599C?logo=c%2B%2B&logoColor=white)
![Last Updated](https://img.shields.io/github/last-commit/algosup/2023-2024-project-4-sportshield-team-3/test-plan)
![GitHub issues](https://img.shields.io/github/issues/algosup/2023-2024-project-4-sportshield-team-3)
| Contributers        | Role              |
| ----------------- | ----------------- | 
| Salaheddine NAMIR | Quality Assurance |         
| Mouatassime SEIV  | Project Manager   |        
| Pierre GORIN      | Program Manager   |         
| Abderrazaq MAKRAN | Technical Lead    |         
| Michel RIFF       | Technical Writer  |          
| Guillaume DESPAUX | Software Engineer |          

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
SportShield is a smart anti-thieft device designed to protect sport equipement. Developed by Coris Innovation, a company specialised on systems and process engineering. The device feature include choke sensors, thieft alarme, GPS tracking, remote lock/unlock functinality. The goal of the project is to improve the battery consumption management, device management with NFC and alarm management and simultaneous actions. 

### 1.1  Scope

#### 1.1.1 In Scope
1. Battery Consumption Management:

- Improve energy efficiency of the system by implementing strategies such as turning on components only when needed and managing sleep modes effectively.
- Implement measures to handle low battery situations, ensuring skis are secured even when the battery is low.
- Increase battery lifespan by enforcing charging limits (e.g., no charge above 80% of Vmax) and discharge thresholds (e.g., no discharge under 20%).

2. Device Management with NFC:

- Enable NFC functionality for users to activate/deactivate the anti-theft system and unlock the cable via their smartphone and SportShield app.

- Implement NFC functionality redundantly with Bluetooth to provide users with increased control options.
3. Alarm Management and Simultaneous Actions:

- Add the capability to stop the alarm when it rings, regardless of whether the ringing cycle is completed.
- Enable the alarm to ring while simultaneously sending HTTP notifications to the server.
- Enhance interruption management for better user experience.

	

#### 1.1.2 Out of Scope
1. Hardware Modifications:
- Changes or modifications to hardware components such as circuitry or electromagnets are not within the scope of this test plan.

2. Advanced Connectivity Features:
- Introducing new connectivity features beyond NFC and Bluetooth, such as Wi-Fi or cellular connectivity, is out of scope for this phase of testing.

3. User Interface Overhaul:

- Significant redesign or overhaul of the user interface beyond the necessary changes to accommodate new features is not within the scope of this test plan.
4. Server-Side Changes:

- Modifications or enhancements to the server-side infrastructure beyond implementing HTTP notifications are not included in this test plan.
5. Third-Party Integration:

- Integrating with third-party services or platforms beyond basic HTTP notifications is out of scope for this test plan.
6. Physical Design Changes:

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
### 2.1 Overview








### 2.2 Test Levels








	
### 2.3 Bug Triage




### 2.4 Suspension Criteria and Resumption Requirements



### 2.5 Test Completeness

## 3 Test Deliverables




## 4 Resource & Environment Needs

### 4.1 Testing Tools





### 4.2 Test Environment



## 5 Terms/Acronyms 




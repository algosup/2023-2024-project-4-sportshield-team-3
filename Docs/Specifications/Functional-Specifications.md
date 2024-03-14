<!-- See: Docs/Specifications/FuncSpecs-Helper.md -->

<div align="center">

# Functional Specifications

---
**Title:** SportShield - Team 3

**Author:** Pierre GORIN

**Team:** Team 3

**Reviewer(s):** Salaheddine NAMIR

**Created on:** March 11<sup>th</sup>, 2024

**Last updated:** March 13<sup>th</sup>, 2024

---

### Approvals

| Reviewer          | Role              | Approved | Date |
| ----------------- | ----------------- | -------- | ---- |
| Salaheddine NAMIR | Quality Assurance |          |      |
| Mouatassime SEIV  | Project Manager   |          |      |
| Pierre GORIN      | Program Manager   |          |      |
| Abderrazaq MAKRAN | Technical Lead    |          |      |
| Michel RIFF       | Technical Writer  |          |      |
| Guillaume DESPAUX | Software Engineer |          |      |

</div>

<br><details>
<summary><h3 id="toc"> Table of Contents <i>(Click to expand)</i></h3></summary>

- [Functional Specifications](#functional-specifications)
    - [Approvals](#approvals)
- [1. - Glossary](#1---glossary)
- [2. - Introduction](#2---introduction)
  - [2.1 - Overview](#21---overview)
  - [2.2 - Project Definition](#22---project-definition)
    - [2.2.1 - Purpose](#221---purpose)
    - [2.2.2 - Scope](#222---scope)
    - [2.2.3 - Deliverables](#223---deliverables)
  - [2.3 - Project Organization](#23---project-organization)
    - [2.3.1 - Project Representatives](#231---project-representatives)
    - [2.3.2 - Stakeholders](#232---stakeholders)
    - [2.3.3 - Project Team](#233---project-team)
    - [2.3.4 - Project Reviewers](#234---project-reviewers)
  - [2.4 - Project Plan](#24---project-plan)
    - [2.4.1 - Retro-planning](#241---retro-planning)
    - [2.4.2 - Milestones](#242---milestones)
    - [2.4.3 - Resources](#243---resources)
    - [2.4.4 - Assumptions and Constraints](#244---assumptions-and-constraints)
- [3. - Personas](#3---personas)
  - [3.1 - Individual Sports Enthusiasts](#31---individual-sports-enthusiasts)
    - [3.1.1 - The Weekend Warrior](#311---the-weekend-warrior)
    - [3.1.2 - The Extreme Sports Adventurer](#312---the-extreme-sports-adventurer)
    - [3.1.3 - The Fitness Fanatic](#313---the-fitness-fanatic)
  - [3.2 - Professional Athletes and Performers](#32---professional-athletes-and-performers)
    - [3.2.1 - The Touring Musician](#321---the-touring-musician)
    - [3.2.2 - The Competitive Skier](#322---the-competitive-skier)
  - [3.3 - Outdoor and Travel Enthusiasts](#33---outdoor-and-travel-enthusiasts)
    - [3.3.1 - The Global Backpacker](#331---the-global-backpacker)
    - [3.3.2 - The Tech-Savvy Traveler](#332---the-tech-savvy-traveler)
</details>

# 1. - Glossary

# 2. - Introduction

## 2.1 - Overview

## 2.2 - Project Definition

### 2.2.1 - Purpose

The Goals and Objectives of this project is to work on the development of the SportShield device. The SportShield device is a lockspan powered by a microcontroller and equipped with a set of sensors and a communication module. The device is designed to be attached to a sports equipment, such as a pair of skis, a snowboard, a bike, a surf, etc. The device is intended to provide the user with a set of features to protect the equipment from theft and to monitor the equipment's status.

This Project is piloted by the company [Coris Innovation](https://www.corisinnovation.com/), A company founded in 2015 by Stéphane MAIGE and specialized in the development of innovative products in many fields like Aerospace, Automotive, Energy, Railway, Pharmaceutical, Watchmaking, etc...
Coris Innovation is made of a team of 90 employees spreaded over 5 sites in France and Switzerland.

### 2.2.2 - Scope

| Feature             | Description                                                                           | In Scope | Out of Scope |
| ------------------- | ------------------------------------------------------------------------------------- | -------- | ------------ |
| GPS Tracking        | The device must be able to provide the user with the GPS coordinates of the equipment | ✅        |              |
| Alarm               | The device must be able to trigger an alarm when the equipment is moved               | ✅        |              |
| Remote Locking      | The device must be able to lock the equipment remotely                                | ✅        |              |
| Remote Unlocking    | The device must be able to unlock the equipment remotely                              | ✅        |              |
| Battery Monitoring  | The device must be able to monitor its battery level                                  | ✅        |              |
| Communication       | The device must be able to communicate with a smartphone                              | ✅        |              |
| User Interface      | The device must be able to provide the user with a user interface                     |          | ❌            |
| User Authentication | The device must be able to authenticate the user                                      |          | ❌            |


### 2.2.3 - Deliverables

The deliverables of this project are:

| Deliverable               | Link to the Document                                        |
| ------------------------- | ----------------------------------------------------------- |
| Functional Specifications | [Functional Specifications](./Functional-Specifications.md) |
| Technical Specifications  | [Technical Specifications](./Technical-Specifications.md)   |
| Test Plan                 | [Test Plan](./Test-Plan.md)                                 |
| User Manual               | [User Manual](./User-Manual.md)                             |
| Code                      | [Code](../../Src/New/main.ino)                              |

## 2.3 - Project Organization

### 2.3.1 - Project Representatives

| Owners                 | Representative                                |
| ---------------------- | --------------------------------------------- |
| ***Coris Innovation*** | Represented by ***Florent ANON***             |
| ***ALGOSUP***          | Represented by ***Franck JEANNIN***           |
| Mouatassime SEIV       | Represented by Pierre GORIN (Program Manager) |

The project sponsors (highlighted in ***bold italic***) are expected to be in charge of:

- Defining the vision and high-level objectives for the project.
- Approving the requirements, timetable and resources.
- Authorising the provision of funds/resources.
- Approving the Functional and Technical Specifications written by the team.
- Approving any major changes in scope.
- Approving the Test Plan and User Manual written by the team.
- Received Project Weekly Reports and take action accordingly to resolve issues escalated by the Project Manager.
- Providing final acceptance of the solution upon project completion.

### 2.3.2 - Stakeholders

| Stakeholder      | Interest                                                                  |
| ---------------- | ------------------------------------------------------------------------- |
| Coris Innovation | The company that initiate the project and will sell the device            |
| ALGOSUP          | The company that will help on the development of the software             |
| Students         | The team that will work on the development and optimization of the device |
| End Users        | The people that will use the device                                       |

### 2.3.3 - Project Team

| Role              | Description                                                                                                                                                                                                                    | Name              |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ----------------- |
| Project Manager   | • He is in charge of organization, planning, and budgeting.<br>• Ensure communication within the team and keep them motivated.                                                                                                 | Mouatassime SEIV  |
| Program Manager   | • Makes sure the project meets the client's expectations.<br>• He is the intermediary between the client and the development team.<br>• He is responsible for writing the Functional Specifications.                           | Pierre GORIN      |
| Technical Lead    | • He is in charge of making the technical decisions in the project.<br>• He translates the Functional Specifications into Technical Specifications.                                                                            | Abderrazaq MAKRAN |
| Technical Writer  | • He is in charge of writing the documentation of the project.<br>• Based on the specifications, he writes a Manual for the end-users.                                                                                         | Michel RIFF       |
| Software Engineer | • Responsible for Writing the code and the unit tests, commenting, and documenting his code.<br>• He participates in the technical choices.                                                                                    | Guillaume DESPAUX |
| Quality Assurance | • Tests all the functionalities of the product to find bugs and issues. Defines the test strategy and writes the test plan.<br>• He documents all the encountered bugs and issues, then checks that the errors are well fixed. | Salaheddine NAMIR |

### 2.3.4 - Project Reviewers

External project reviewers have been appointed by the project owner to review our specifications and provide us with feedback.

## 2.4 - Project Plan

### 2.4.1 - Retro-planning

### 2.4.2 - Milestones

### 2.4.3 - Resources

### 2.4.4 - Assumptions and Constraints

# 3. - Personas

## 3.1 - Individual Sports Enthusiasts

### 3.1.1 - The Weekend Warrior

### 3.1.2 - The Extreme Sports Adventurer

### 3.1.3 - The Fitness Fanatic

## 3.2 - Professional Athletes and Performers

### 3.2.1 - The Touring Musician

### 3.2.2 - The Competitive Skier

## 3.3 - Outdoor and Travel Enthusiasts

### 3.3.1 - The Global Backpacker

### 3.3.2 - The Tech-Savvy Traveler
# CAPTCHA


CAPTCHA (Completely Automated Public Turing test to tell Computers and Humans Apart) is a security technique used on websites to distinguish human users from automated bots.

Many bots try to automatically create accounts, submit spam, or overload websites. CAPTCHA prevents this by giving the user a task that is easy for humans but difficult for automated programs.

Common CAPTCHA tasks include:
- identifying objects in images
- typing distorted text
- solving simple puzzles

If the user solves the challenge correctly, the system assumes the user is **human** and allows access.

## Basic Architecture of a CAPTCHA System

A simple CAPTCHA system can be designed using a **simple reflex agent architecture**, where the system generates a challenge and verifies the user's response.

### Main Components

#### 1. CAPTCHA Generator
Creates a challenge for the user.

Examples:
- distorted text
- image selection
- simple math puzzle


#### 2. User Interface
Displays the CAPTCHA challenge to the user and collects the user's response.


#### 3. Verification Module
Checks whether the user's response matches the correct answer.


#### 4. Decision Module
Determines the result based on verification.

- If correct → allow access  
- If incorrect → deny access or generate another CAPTCHA


## System Workflow

User Requests Access

↓

CAPTCHA Generator

↓

Display Challenge (User Interface)

↓

User Enters Response

↓

Verification Module

↓

Decision Module

↓

Human/ Bot

## Summary

CAPTCHA systems help protect websites from automated bots by presenting challenges that humans can solve easily but machines find difficult.

By combining a challenge generator, user interface, verification module, and decision system, the CAPTCHA system can effectively distinguish between human users and automated programs.

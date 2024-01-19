# Modified Dining Philosophers Problem
## Operating Systems Assignment
Wrote the C code for the modified Dining Philosophers Problem, the details of which are mentioned below.

## Problem Statement

### Modified Dining Philosophers Problem (60 points)

The dining philosophers problem involves five philosophers sitting around a round table, each capable of two actions - eat and think. Eating requires two forks, one placed beside each philosopher. Unrestricted access to forks can lead to deadlock situations. The objective is to write a program to simulate the philosophers using threads and forks using global variables. Deadlock resolution is to be achieved through two techniques: (a) strict ordering of resource requests, and (b) utilization of semaphores to access resources.

### Part (a)

1. **Task Description:** Create a program to simulate philosophers using threads, with forks represented by global variables. Resolve deadlock using strict ordering of resource requests and semaphores.

2. **Evaluation Criteria:**
   - Creating threads and shared variables [5 * 2 = 10 points].
   - Two variants of the program (a) [10 * 2 = 20 points].
   - Full compilation and correct functionality of all programs (20 points).
   - Program compiles successfully but doesn’t meet all functionality requirements (15 points).
   - Program doesn’t compile, even if program logic seems correct (0 points).

### Part (b)

1. **Task Description:** Repeat the system using semaphores in a scenario where there are two sauce bowls. To eat, the user needs access to one of the two sauce bowls and can access any one of them at any time.

2. **Evaluation Criteria:**
   - Two variants of the program (b) [10 * 2 = 20 points].
   - Full compilation and correct functionality of all programs (20 points).
   - Program compiles successfully but doesn’t meet all functionality requirements (15 points).
   - Program doesn’t compile, even if program logic seems correct (0 points).

### General Evaluation

1. **Task Description:** Include a proper makefile building all the source files [5 points].
2. **Task Description:** Provide a README file with a short explanation of the resources and primitives used [5 points].


# Dining Philosophers Simulation

## Overview

This repository contains implementations of the Dining Philosophers problem using threads in C. The goal is to model philosophers as threads and forks (or chopsticks) as global resources using various synchronization mechanisms to avoid deadlocks.

### General Approach

All implementations follow a similar structure where philosophers (threads) are started in parallel, and rules are established for resource allocation to avoid deadlocks.

### 1) Dining Philosophers Simulation with Strict Resource Ordering

#### Resources Used:

In this simulation, philosophers are represented by threads, and forks/chopsticks are represented using global variables—an array of `pthread_mutex_t`. The key strategy involves starting all threads in parallel and enforcing a rule where philosophers always reach for the lower-numbered fork/chopstick first. Once successfully acquired, they attempt to grab the higher-numbered fork/chopstick. This strict ordering of resource allocation, coupled with the use of `pthread_mutex`, ensures deadlock prevention.

#### Primitives Used:

- **Variables:** Two integers, `i` and `j`, are used for various purposes such as loop control, thread creation/joining, and mutex creation/destruction.
- **Pointer:** A `void*` pointer named `msg` is utilized to store the exit status of threads after calling `pthread_join`. While not required in this case due to the use of `pthread_mutexes`, it can be used for error checking and handling.
- **Sleep Function:** `sleep()` function simulates the eating process.

### 2) Dining Philosophers Simulation with Semaphores

#### Resources Used:

This simulation employs threads to represent philosophers, and forks/chopsticks are modeled using global variables—an array of `pthread_mutex_t`. The approach involves starting all threads in parallel, with a rule specifying that philosophers always go for the left fork first using semaphores. After obtaining the left fork, they can proceed to attempt to grab the right fork/chopstick. The use of semaphores ensures proper resource allocation, preventing deadlock scenarios.

#### Primitives Used:

- **Variable:** The integer `i` is employed for loop control in thread creation/joining and mutex creation/destruction.
- **Sleep Function:** `sleep()` function simulates the eating process.
- **Semaphores:** `sem_wait` and `sem_post` are utilized to wait for and signal the end of semaphore use, respectively.

### 3) Dining Philosophers Simulation with Semaphores and Sauce Bowls

#### Resources Used:

Similar to the previous simulation, philosophers are represented by threads, and forks/chopsticks are modeled using global variables—an array of `pthread_mutex_t`. Philosophers follow a rule of going for the left fork first, facilitated by semaphores. Additionally, semaphores are used for two sauce bowls, ensuring only two philosophers can access them simultaneously, preventing potential deadlocks.

#### Primitives Used:

- **Variables:** The integer `i` is used for loop control in thread creation/joining and mutex creation/destruction.
- **Sleep Function:** `sleep()` function simulates the eating process.
- **Semaphores:** `sem_wait` and `sem_post` are employed for waiting and signaling, respectively. Three semaphores are used for forks, room access, and sauce bowl access.

### 4) Dining Philosophers Simulation with Strict Resource Ordering and Sauce Bowls

#### Resources Used:

In this scenario, philosophers and forks/chopsticks are represented by threads and global variables—an array of `pthread_mutex_t` for forks and a separate array for two sauce bowls. The approach is to start all threads in parallel and enforce a rule of grabbing lower-numbered forks/chopsticks first. After acquiring them, philosophers attempt to grab higher-numbered forks and immediately move on to grab a sauce bowl if available. The strict resource ordering, coupled with `pthread_mutex`, ensures deadlock prevention.

#### Primitives Used:

- **Variables:** Three integers, `i`, `j`, and `k`, are employed for loop control in thread creation/joining and mutex creation/destruction.
- **Pointer:** A `void*` pointer named `msg` stores the exit status of threads after calling `pthread_join`. While not strictly required, it can be used for error checking and handling.
- **Sleep Function:** `sleep()` function simulates the eating process.

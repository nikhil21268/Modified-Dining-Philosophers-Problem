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

## Implementation 1

### Primitives Used

- Two integers (`i` and `j`) for loop control and thread-related operations.
- A `void*` pointer named `msg` to store exit statuses of threads.
- `pthread_mutex_t` for representing forks/chopsticks.
- `sleep()` function for simulating eating.

### Algorithmic Approach

Philosophers follow a strict order in grabbing forks/chopsticks to prevent deadlocks. Mutexes ensure exclusive access to shared resources.

## Implementation 2

### Primitives Used

- Integer `i` for loop control and thread-related operations.
- `sem_wait` and `sem_post` for semaphore operations.
- `sleep()` function for simulating eating.

### Algorithmic Approach

This implementation uses semaphores to allocate resources, ensuring philosophers grab the left fork first, preventing deadlocks.

## Implementation 3

### Primitives Used

- Integer `i` for loop control and thread-related operations.
- `sem_wait` and `sem_post` for semaphore operations.
- Three semaphores (`forks`, `room`, and `sauce`) to manage resource access.
- `sleep()` function for simulating eating.

### Algorithmic Approach

Similar to Implementation 2, but with an additional semaphore for sauce bowls. The `room` semaphore prevents deadlocks.

## Implementation 4

### Primitives Used

- Three integers (`i`, `j`, and `k`) for loop control and thread-related operations.
- `void*` pointer named `msg` to store exit statuses of threads.
- `pthread_mutex_t` for forks/chopsticks and sauce bowls.
- `sleep()` function for simulating eating.

### Algorithmic Approach

Philosophers follow a strict order in grabbing forks/chopsticks and sauce bowls, preventing deadlocks. Mutexes ensure exclusive access to shared resources.

---

Feel free to explore each implementation for a detailed look at the code and the specific algorithmic approaches employed.

# Scheduling-Algorithms-Operating-System-Project

This project is for the Operating System course. It was required to implement a CPU scheduler which determines an order for the execution of its scheduled
processes. It decides which process will run according to a certain data structure that keeps track of the processes in the system and their status.
A process, upon creation, has one of the three states: Running, Ready, Blocked (doing I/O, using other resources than CPU or waiting on an unavailable
resource).

Objectives
----------
* Evaluating different scheduling algorithms.
* Practice the use of IPC techniques.
* Best usage of algorithms, and data structures.

Platform: Linux
Language: C

Assumptions: Consider a machine with 1-CPU and infinite memory. 
It is required to make a scheduler with its complementary components as sketched in the following diagrams.
![image](https://user-images.githubusercontent.com/82734074/216735644-dfc99e41-f465-4325-864e-77b8a6cf5fff.png)

Process Generator (process_generator.c)
----------------------------------------
The process generator should simulate a real operating systems as follows:
---
* It reads the input files containing the information about processes (check the input/output section below).\n
* It gets the chosen scheduling algorithm and its parameters, if any, as command line arguments. These arguments are specified after the name of the program in the system command line, and their values are passed to the program during execution. \n
* It initiates and creates the scheduler and clock processes. \n
* It creates a data structure for processes and fills it with its parameters (e.g. arrival time, running time, etc.)\n
* It sends the information to the scheduler at the appropriate time (when a process arrives), so that the scheduler places it correctly in its turn among the existing processes. A process should not be sent to the scheduler until it arrives to the system.\n
* At the end of simulation, the process generator should clear all IPC resources.\n

Clock (clk.c)
--------------
The clock module is used to emulate an integer time clock 

Scheduler (scheduler.c)
------------------------
It should keep track of the processes and their states and it decides - based on the used algorithm - which process will run and for how long.

The Scheduling Algorithms:
---------------------------
1. Shortest Job First (SJF)
2. Preemptive Highest Priority First (HPF)
3. Round Robin (RR)
4. Multiple level Feedback Loop

The Scheduler is used to:
1.Start a new process whenever it arrives. (Fork it and give it its parameters)
2.Switch between two processes according to the scheduling algorithm. (stop the old process and save its state and start/resume another one.)
3.Keep a process control block (PCB) for each process in the system. A PCB should keep track of the state of a process; running/waiting, execution time, remaining time, waiting time, etc.
4.Delete the data of the process when it finishes its job. The scheduler knows that a process has finished if its remaining time reaches zero. Note that the scheduler does NOT terminate the process. It just deletes its data from the process control block and its data structures.


Calculations
-------------
1) CPU utilization.
2) Average Weighted Turnaround Time
3) Average Waiting Time


Process (process.c)
--------
Each process acts as if it is CPU-bound.
When a process finishes, the scheduler does not terminate (kill) the process. It terminates by itself.


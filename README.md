# Process Scheduling Algorithms

This project provides implementations of various CPU scheduling algorithms in C++ to simulate and analyze process scheduling. The following algorithms are included:

- **First-Come, First-Served (FCFS)**
- **Shortest Job First (SJF)**
- **Round Robin (RR)**

## Project Structure

- **`main.cpp`**: Entry point of the application where the user can select the scheduling algorithm and provide input for processes.
- **`algos.h`**: Header file with the `ProcData` structure definition and algorithm function prototypes.
- **`fcfsAlgo.cpp`**: Contains the implementation of the FCFS scheduling algorithm.
- **`sjfAlgo.cpp`**: Contains the implementation of the SJF scheduling algorithm.
- **`rrAlgo.cpp`**: Contains the implementation of the RR scheduling algorithm.

## How to Run

To compile and execute the project on your local machine, follow these steps:

1. **Compile the Code**:
   Use a C++ compiler like `g++` to compile the source files. Open your terminal and navigate to the directory containing the source files. Run the following command:

   ```sh
   g++ -o scheduling main.cpp fcfsAlgo.cpp sjfAlgo.cpp rrAlgo.cpp
   ```

2. **Run the Executable**:
   After compilation, execute the program using the following command:

   ```sh
   ./scheduling
   ```

3. **Provide Input**:
   - Enter the number of processes when prompted.
   - For each process, input the arrival time and burst time.
   - Select the scheduling algorithm by entering the corresponding number (1 for FCFS, 2 for SJF, and 3 for RR).

## Dependencies

- A C++ compiler (e.g., `g++`)
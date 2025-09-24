✈️ Airport Fleet Management in C
📌 Project Overview

This project is a console-based C application designed to manage an airport and its fleet of airplanes.
It allows users to perform essential operations such as adding, modifying, deleting, and displaying airplanes, managing airport details, searching, sorting, and calculating statistics such as fleet occupation rate.

The project has been developed as part of a learning exercise to strengthen programming skills in C language, focusing on data structures, algorithms, and problem-solving.

🎯 Features
✈️ Airplane Management

Add one or multiple airplanes.

Modify airplane details (model, capacity, status).

Delete airplanes.

Display the complete fleet.

Search airplanes (by ID or model).

Sort airplanes (by capacity, alphabetical model, or entry date).

🏢 Airport Management

Initialize an airport with its name.

Display airport information and fleet statistics.

📅 Date Management (Bonus)

Associate an entry date with each airplane.

Sort airplanes by date of entry.

📊 Statistics

Total number of airplanes.

Number of airplanes per status: Available, In Maintenance, In Flight.

Total passenger capacity of the fleet.

Airplane with the largest and smallest capacity.

📈 Fleet Occupation Coefficient

The application calculates:

Coefficient = (Available airplanes / Total airplanes) × 100


This indicates the availability rate of the fleet.

🛠️ Technical Requirements

Language: C

Data Structures:

Structures for Airplane, Airport, Date.

Arrays (static or dynamic) for storing collections.

Algorithms:

Sequential search.

Sorting (Selection Sort, Bubble Sort, etc.).

User Interface: Console menu (user always returns to the main menu after each operation).

📂 Project Structure
📦 Airport-Fleet-Management
 ┣ 📜 main.c          # Entry point of the program
 ┣ 📜 airport.h       # Header files (structs and function prototypes)
 ┣ 📜 airport.c       # Implementation of airport-related functions
 ┣ 📜 airplane.c      # Implementation of airplane-related functions
 ┣ 📜 date.c          # Implementation of date-related functions
 ┣ 📜 utils.c         # Helper functions (search, sorting, etc.)
 ┗ 📜 README.md       # Project documentation

🚀 How to Run

Clone the repository:

Navigate to the project folder:

cd Airport-Fleet-Management


Compile the program:

gcc main.c airport.c airplane.c date.c utils.c -o airport_app


Run the application:

./airport_app

🎓 Learning Objectives

This project helps to practice:

Structs in C.

Array management (static and dynamic).

Algorithmic problem-solving (search & sorting).

Menu-driven console applications.

Project organization (multiple files, modular design).

📌 Future Improvements

Add file persistence (save/load data).

Add advanced sorting algorithms (QuickSort, MergeSort).

Support for multiple airports.

Add graphical interface (using C graphics library or GUI frameworks).

🤝 Contributing

Contributions are welcome! Please feel free to fork this repository, submit issues, or create pull requests.

# Fitness_Nutrition_Tracker
#  FitTrack C++: Dynamic Fitness & Nutrition Engine

A robust, terminal-based fitness and nutrition tracking system built entirely in C++. This project serves as the backend logic engine for a comprehensive health app, utilizing core Object-Oriented Programming (OOP) principles to dynamically calculate metabolic needs, track macros, and recommend workouts.

##  Key Features

* **Dynamic Calorie Engine:** Calculates Basal Metabolic Rate (BMR) using the Mifflin-St Jeor equation and dynamically adjusts daily caloric targets based on real-time workout data.
* **Polymorphic Workout Tracking:** Logs different exercise types (Strength Training vs. Cardio) using dynamic binding to accurately calculate varying calorie expenditure rates.
* **Smart Nutrition Database:** Utilizes a C++ Hash Map (`std::unordered_map`) for $O(1)$ retrieval of food macros. Pre-configured with common meals (like Rice, Dal, and Oats) for quick logging without manual macro entry.
* **Recommendation AI:** Evaluates user BMI and weekly workout frequency to suggest specific bulking/cutting phases, auto-adjusting protein and carbohydrate targets.
* **Gamification:** Tracks consecutive login days to build user consistency and discipline.
* **Terminal UI:** Features a custom ASCII-based protein progress bar directly in the command line.

##  Software Architecture & OOP Concepts

This project is structured with a clear separation of concerns, paving the way for a future Model-View-Controller (MVC) web/app implementation:

* **Encapsulation:** User health metrics (weight, streaks) are strictly protected and only accessible via validated getter/setter methods to prevent data corruption.
* **Inheritance & Polymorphism:** A base `Activity` class acts as a blueprint, with `StrengthTraining` and `Cardio` derived classes implementing their own overridden methods for accurate calorie math.
* **Virtual Destructors:** Ensures safe memory cleanup and prevents memory leaks when managing lists of generic activity pointers.
* **Memory Management:** Utilizes modern C++ `std::unique_ptr` inside vectors for automated, leak-free object lifetimes.

##  Tech Stack
* **Language:** C++14 / C++17
* **Environment:** Linux (Developed on Linux Mint)
* **Compiler:** GCC (`g++`)

##  Installation & Usage

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/yourusername/fittrack-cpp.git](https://github.com/yourusername/fittrack-cpp.git)
   cd fittrack-cpp

  ##Future Roadmap

  [ ] Implement File I/O (fstream) for persistent data storage using JSON.

  [ ] Build an interactive Command Line Interface (CLI) menu system.

  [ ] Wrap the C++ engine in a lightweight web framework (e.g., Crow) to serve as a backend API.

  [ ] Develop a frontend web interface using HTML, CSS, and JavaScript.

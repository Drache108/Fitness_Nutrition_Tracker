#ifndef FITNESS_H
#define FITNESS_H

#include<bits/stdc++.h>
using namespace std;

// --- 1. USER CLASS ---
class User {
private:
    string name;
    double weightKG;
    double heightCM;
    int age;
    int dailyCalorieTarget;
    int loginStreak;

public:
    // Constructor
    User(string n, double w, double h, int a) 
        : name(n), weightKG(w), heightCM(h), age(a), dailyCalorieTarget(2000), loginStreak(0) {}

    // Encapsulation: Getters and Setters
    string getName() const { return name; }
    double getWeight() const { return weightKG; }
    
    void updateWeight(double newWeight) {
        if (newWeight > 0) {
            weightKG = newWeight;
            cout << "Weight updated to " << weightKG << " kg.\n";
        }
    }

    void incrementStreak() {
        loginStreak++;
        cout << "Streak updated! You're on a " << loginStreak << "-day roll.\n";
    }

    // Basic BMR Calculation
    double calculateBMR() const {
        return (10 * weightKG) + (6.25 * heightCM) - (5 * age) + 5;
    }

    void displayProfile() const {
        cout << "\n--- Profile: " << name << " ---" << endl;
        cout << "Weight: " << weightKG << " kg | Height: " << heightCM << " cm" << endl;
        cout << "Est. BMR: " << calculateBMR() << " kcal/day" << endl;
        cout << "Current Streak: " << loginStreak << " days" << endl;
        cout << "-----------------------" << endl;
    }
};

// --- 2. ACTIVITY HIERARCHY (Polymorphism) ---

// Abstract Base Class
class Activity {
protected:
    string date;
    int durationMinutes;

public:
    Activity(string d, int dur) : date(d), durationMinutes(dur) {}
    virtual ~Activity() = default; // Virtual destructor for safe memory cleanup

    // Pure virtual function makes this an abstract class
    virtual void displayWorkout() const = 0; 
    virtual double calculateCaloriesBurned() const = 0; 
};

// Derived Class: Strength Training
class StrengthTraining : public Activity {
private:
    string exerciseName;
    int sets;
    int reps;
    double weightUsed;

public:
    StrengthTraining(string d, int dur, string ex, int s, int r, double w)
        : Activity(d, dur), exerciseName(ex), sets(s), reps(r), weightUsed(w) {}

    void displayWorkout() const override {
        cout << "[Strength] " << date << ": " << exerciseName 
             << " - " << sets << "x" << reps << " @ " << weightUsed << "kg (" 
             << durationMinutes << " mins)" << endl;
    }

    double calculateCaloriesBurned() const override {
        // Rough estimate: ~3-6 calories per minute of weightlifting
        return durationMinutes * 4.5; 
    }
};

// Derived Class: Cardio
class Cardio : public Activity {
private:
    string cardioType;
    double distanceKM;

public:
    Cardio(string d, int dur, string type, double dist)
        : Activity(d, dur), cardioType(type), distanceKM(dist) {}

    void displayWorkout() const override {
        cout << "[Cardio]   " << date << ": " << cardioType 
             << " - " << distanceKM << "km in " << durationMinutes << " mins" << endl;
    }

    double calculateCaloriesBurned() const override {
        // Rough estimate: ~10 calories per minute of moderate cardio
        return durationMinutes * 10.0; 
    }
};


#endif
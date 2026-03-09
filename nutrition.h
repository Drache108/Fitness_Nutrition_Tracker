#ifndef NUTRITION_H
#define NUTRITION_H

#include<bits/stdc++.h>
using namespace std;

// Struct to hold macro data for 100g of a food item
struct FoodItem {
    double calories;
    double protein;
    double carbs;
    double fats;
};

// Enum for the user's current goal
enum Goal { CUTTING, MAINTENANCE, BULKING };

// --- 2. NUTRITION CLASS ---
class Nutrition {
private:
    // The Database: Key is food name, Value is the FoodItem struct
    unordered_map<string, FoodItem> foodDatabase;
    
    // Daily Totals
    double totalCalories = 0;
    double totalProtein = 0;
    double totalCarbs = 0;
    double totalFats = 0;

public:
    Nutrition() {
        // Pre-loading the database (per 100g raw/cooked depending on preference)
        foodDatabase["Rice"] = {130.0, 2.7, 28.0, 0.3}; 
        foodDatabase["Dal"] = {116.0, 9.0, 20.0, 0.4}; // Standard yellow dal
        foodDatabase["Chicken Breast"] = {165.0, 31.0, 0.0, 3.6};
        foodDatabase["Oats"] = {389.0, 16.9, 66.3, 6.9};
    }

    // Function to log food by generic name and grams consumed
    void logFood(string foodName, double grams) {
        if (foodDatabase.find(foodName) != foodDatabase.end()) {
            double multiplier = grams / 100.0;
            FoodItem item = foodDatabase[foodName];

            totalCalories += item.calories * multiplier;
            totalProtein += item.protein * multiplier;
            totalCarbs += item.carbs * multiplier;
            totalFats += item.fats * multiplier;

            cout << "Logged: " << grams << "g of " << foodName << " (" 
                 << item.calories * multiplier << " kcal)\n";
        } else {
            cout << "Error: '" << foodName << "' not found in database.\n";
        }
    }

    double getConsumedCalories() const { return totalCalories; }
    double getConsumedProtein() const { return totalProtein; }

    // Visual Protein Meter
    void displayProteinMeter(double targetProtein) const {
        cout << "\n--- Protein Goal ---" << endl;
        double percentage = (totalProtein / targetProtein) * 100.0;
        if (percentage > 100.0) percentage = 100.0;

        int barWidth = 20;
        int filledWidth = (percentage / 100.0) * barWidth;

        cout << "[";
        for (int i = 0; i < barWidth; ++i) {
            if (i < filledWidth) cout << "O"; // Filled part
            else cout << "-";                 // Empty part
        }
        cout << "] " << fixed << setprecision(1) << totalProtein 
             << "g / " << targetProtein << "g (" << int(percentage) << "%)\n";
    }
};

#endif
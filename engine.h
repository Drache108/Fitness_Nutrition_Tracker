#ifndef ENGINE_H
#define ENGINE_H

#include <bits/stdc++.h>
using namespace std;

class RecommendationEngine {
public:
    // 1. Calculate BMI
    static double calculateBMI(double weightKG, double heightCM) {
        double heightM = heightCM / 100.0;
        return weightKG / (heightM * heightM);
    }

    // 2. Generate Weekly Nutrition & Macro Plan
    static void generateMacroPlan(double weightKG, double heightCM, double bmr, double caloriesBurnedToday) {
        double bmi = calculateBMI(weightKG, heightCM);
        
        // 1. Baseline TDEE (Sedentary lifestyle: BMR + basic daily movement)
        double baselineTDEE = bmr * 1.2; 
        
        // 2. Dynamic Total Burn (Baseline + Today's Gym Session)
        double actualCaloriesBurned = baselineTDEE + caloriesBurnedToday;
        
        double targetCalories = actualCaloriesBurned;
        string goalPhase = "";

        // Adjust calories based on BMI category
        if (bmi < 18.5) {
            targetCalories += 400; // Surplus
            goalPhase = "Bulking (Muscle Gain)";
        } else if (bmi >= 25.0) {
            targetCalories -= 400; // Deficit
            goalPhase = "Cutting (Fat Loss)";
        } else {
            goalPhase = "Maintenance (Body Recomposition)";
        }

        // Calculate Macros based on body weight
        double proteinGrams = weightKG * 2.0;
        double fatGrams = weightKG * 0.8;
        
        // Calories from protein and fats (Protein = 4 kcal/g, Fat = 9 kcal/g)
        double usedCalories = (proteinGrams * 4) + (fatGrams * 9);
        
        // Remaining calories go to carbs (Carbs = 4 kcal/g)
        double carbGrams = (targetCalories - usedCalories) / 4.0;

        cout << "\n=== WEEKLY MACRO RECOMMENDATION ===" << endl;
        cout << "Current BMI: " << bmi << " -> Phase: " << goalPhase << endl;
        cout << "Target Calories: " << targetCalories << " kcal/day" << endl;
        cout << "Protein: " << proteinGrams << "g | Fats: " << fatGrams << "g | Carbs: " << carbGrams << "g" << endl;
        
        // Practical tip for a hostel setting
        cout << "\nTip: Hitting exactly " << carbGrams << "g of carbs from mess food (rice/dal) is hard. "
             << "Focus purely on hitting your " << proteinGrams << "g protein target first, then eat until satisfied!" << endl;
        cout << "===================================" << endl;
    }

    // 3. Generate Weekly Workout Plan
    static void generateWorkoutPlan(double bmi, int weeksConsistent) {
        cout << "\n=== WEEKLY WORKOUT RECOMMENDATION ===" << endl;
        
        if (bmi < 18.5) {
            cout << "- Focus heavily on Compound Lifts (Squats, Bench, Deadlifts)." << endl;
            cout << "- Keep cardio to a minimum (1-2x a week) to avoid burning surplus calories." << endl;
        } else if (bmi >= 25.0) {
            cout << "- Keep lifting heavy to preserve muscle mass while in a deficit." << endl;
            cout << "- Add 20-30 mins of low-intensity steady-state (LISS) cardio after every session." << endl;
        } else {
            cout << "- Standard split: 4 days lifting, 2 days moderate cardio." << endl;
        }

        // Adjust advice based on how long they've been going to the gym
        if (weeksConsistent <= 4) {
             cout << "- Note: You are still in the beginner phase! Don't ego lift. Focus entirely on form and consistency over weight." << endl;
        } else {
             cout << "- Note: You've built a solid habit. Start pushing for Progressive Overload (add 2.5kg to your main lifts this week)." << endl;
        }
        cout << "=====================================" << endl;
    }
};

#endif
#include <bits/stdc++.h>
#include "fitness.h"
#include "nutrition.h"
#include "engine.h"

using namespace std;

int main() {
    cout << "\n=========================================\n";
    cout << "      FITNESS & NUTRITION TRACKER        \n";
    cout << "=========================================\n";

    // 1. Initialize User Profile (Name, Weight in kg, Height in cm, Age)
    User myProfile("Student", 72.5, 175.0, 19); 
    myProfile.incrementStreak();
    myProfile.displayProfile();

    // 2. Log Today's Workout using Polymorphism
    vector<unique_ptr<Activity>> todaysWorkout;
    
    // Pushing a mix of strength and cardio for March 9, 2026
    todaysWorkout.push_back(make_unique<StrengthTraining>("2026-03-09", 45, "Bench Press", 4, 8, 60.0));
    todaysWorkout.push_back(make_unique<StrengthTraining>("2026-03-09", 30, "Squats", 3, 10, 80.0));
    todaysWorkout.push_back(make_unique<Cardio>("2026-03-09", 20, "Campus Jog", 3.0));

    double gymCaloriesBurned = 0;
    cout << "\n--- Workout Log ---" << endl;
    for (const auto& exercise : todaysWorkout) {
        exercise->displayWorkout(); // Dynamic binding automatically formats the output
        gymCaloriesBurned += exercise->calculateCaloriesBurned();
    }
    cout << "Total Active Burn: " << gymCaloriesBurned << " kcal\n";

    // 3. Log Today's Nutrition (Using the Hash Map)
    Nutrition dailyDiet;
    cout << "\n--- Meal Log ---" << endl;
    dailyDiet.logFood("Oats", 80);            // Breakfast
    dailyDiet.logFood("Rice", 250);           // Mess Lunch
    dailyDiet.logFood("Dal", 150);            // Mess Lunch
    dailyDiet.logFood("Chicken Breast", 200); // Dinner

    // 4. Run the Recommendation Engine
    double currentBMR = myProfile.calculateBMR();
    
    // Feed the dynamic data (BMR + Gym Burn) into the engine
    RecommendationEngine::generateMacroPlan(
        myProfile.getWeight(), 
        175.0, // Height in cm
        currentBMR, 
        gymCaloriesBurned
    );

    // 5. Display Visual Progress
    // The engine sets protein at 2.0g per kg of body weight (72.5 * 2 = 145g)
    dailyDiet.displayProteinMeter(145.0);

    cout << "\n=========================================\n";
    cout << "        END OF DAY SUMMARY               \n";
    cout << "=========================================\n\n";

    return 0;
}
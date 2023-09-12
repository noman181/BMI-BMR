#include <stdio.h>

float calculateBMI(float weight, float height) {
    return weight / (height * height);
}


float calculateBMR(float weight, float height, int age, char gender) {
    if (gender == 'M') {
        return 88.362 + (13.397 * weight) + (4.799 * height * 100) - (5.677 * age);
    } else if (gender == 'F') {
        return 447.593 + (9.247 * weight) + (3.098 * height * 100) - (4.330 * age);
    } else {
        return -1; 
    }
}


float calculateCalories(float bmr, char activityLevel) {
    switch (activityLevel) {
        case 'S': 
            return bmr * 1.2;
        case 'L': 
            return bmr * 1.375;
        case 'M': 
            return bmr * 1.55;
        case 'V': 
            return bmr * 1.725;
        case 'E': 
            return bmr * 1.9;
        default:
            return -1; 
    }
}

int main() {
    float weight, height;
    int age;
    char gender, activityLevel;

    printf("Enter your weight (kg): ");
    scanf("%f", &weight);

    printf("Enter your height (m): ");
    scanf("%f", &height);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    printf("Enter your activity level (S/L/M/V/E): ");
    scanf(" %c", &activityLevel);

    float bmi = calculateBMI(weight, height);
    float bmr = calculateBMR(weight, height, age, gender);

    if (bmi != -1 && bmr != -1) {
        printf("Your BMI: %.2f\n", bmi);
        printf("Your BMR: %.2f calories/day\n", bmr);

        float calories = calculateCalories(bmr, activityLevel);
        if (calories != -1) {
            printf("Your daily calorie needs: %.2f calories/day\n", calories);
        } else {
            printf("Invalid activity level.\n");
        }
    } else {
        printf("Invalid gender.\n");
    }

    return 0;
}

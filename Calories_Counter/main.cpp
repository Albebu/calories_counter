#include <iostream>	
#include <fstream>
#include <cstdlib>
#include "Users\calories.h"

// Functions
void recomended_calories();
void data_to_file();

// User creation 
CaloriesCounter::User user;

// Calories creation
CaloriesCounter::Calories calories;

int main() {

	std::cout << "This program helps you calculating the calories burned in a training session \n";

	while (true) {

		std::system("cls");

		user.set_basic_data();

		std::cout << "Welcome " << user.get_name() << ", you are " << user.get_age() << " years old, you weight " << user.get_weight() << " kg and you are " << user.get_height() << " cm tall \n";

		// Ask for the exercise
		calories.fill_vector_exercises();
		calories.fill_vector_mets();

		calories.ask_exercise();
		calories.ask_duration();
		calories.calculate_calories(user.get_weight());

		recomended_calories();

		data_to_file();

		std::system("pause");

	}

	return 0;

}

void recomended_calories() {

	float rcb = 0;

	// Get the RCB of the user depending of his gender
	if (user.get_gender() == 1) {
		rcb = 66 + (13.7 * user.get_weight()) + ((5 * user.get_height()) - 6.8 * user.get_age());
	}
	else {
		rcb = 655 + (9.6 * user.get_weight()) + ((1.8 * user.get_height()) - 4.7 * user.get_age());
	}

	int activity = 0;

	do
	{
		std::cout << "Your daily activity is: 1. Sedentary 2. Light 3. Moderated 4. Active 5. Super active";
		std::cin >> activity;

	} while (activity != 1 && activity != 2 && activity != 3 && activity != 4 && activity != 5);

	// Calculate the recomended calories based on the activity 
	switch (activity)
	{
	case 1:
		std::cout << "You should consume " << rcb * 1.2 << " calories per day \n";
		calories.set_calories_recomended(rcb * 1.2);
		break;
	case 2:
		std::cout << "You should consume " << rcb * 1.375 << " calories per day \n";
		calories.set_calories_recomended(rcb * 1.375);
		break;
	case 3:
		std::cout << "You should consume " << rcb * 1.55 << " calories per day \n";
		calories.set_calories_recomended(rcb * 1.55);
		break;
	case 4:
		std::cout << "You should consume " << rcb * 1.725 << " calories per day \n";
		calories.set_calories_recomended(rcb * 1.725);
		break;
	case 5:
		std::cout << "You should consume " << rcb * 1.9 << " calories per day \n";
		calories.set_calories_recomended(rcb * 1.9);
		break;
	}
}

void data_to_file() {

	// Oper file to write the data

	std::ofstream file("data.txt", std::ios::out | std::ios::app);

	if (file.is_open()) {

		file << "Name: " << user.get_name() << "\n";
		file << "Age: " << user.get_age() << "\n";
		file << "Weight: " << user.get_weight() << "\n";
		file << "Height: " << user.get_height() << "\n";
		file << "Calories burned: " << calories.get_calories_burned() << "\n";
		file << "Recomended calories: " << calories.get_calories_recomended() << "\n";

	}
	else
	{
		std::cout << "Error opening the file \n";
	}
}
#include <iostream>
#include <vector>
#include "calories.h"

namespace CaloriesCounter {

	// Getters
	std::string Calories::get_exercise() {
		return exercise;
	}

	int Calories::get_duration() {
		return duration;
	}

	float Calories::get_calories_burned() {
		return calories_burned;
	}

	float Calories::get_calories_recomended() {
		return calories_recomented;
	}

	// Setters
	void Calories::set_exercise(std::string p_exercise) {
		exercise = p_exercise;
	}

	void Calories::set_duration(int p_duration) {
		duration = p_duration;
	}

	void Calories::set_calories_burned(float p_calories_burned) {
		calories_burned = p_calories_burned;
	}

	void Calories::set_calories_recomended(float p_calories_recomended) {
		calories_recomented = p_calories_recomended;
	}

	// Functions

	// Fill the vector with the exercises
	void Calories::fill_vector_exercises() {
		exercises.push_back("Running");
		exercises.push_back("Swimming");
		exercises.push_back("Cycling");
		exercises.push_back("Walking");
		exercises.push_back("Jump on a rope");
		exercises.push_back("Weight");
	}

	// Fill the vector with the mets of every exercise
	void Calories::fill_vector_mets() {
		mets.push_back(8);
		mets.push_back(6);
		mets.push_back(6);
		mets.push_back(4);
		mets.push_back(8);
		mets.push_back(5);
	}

	void Calories::ask_exercise() {

		bool validExercise = false;

		do {
			std::cout << "Please introduce the exercise on the following list you have done: ";
			for (int i = 0; i < exercises.size(); i++) {
				std::cout << exercises[i] << " ";
			}
			std::cin >> exercise;

			for (int i = 0; i < exercises.size(); i++) {
				if (exercise == exercises[i]) {
					validExercise = true;
				}
			}

		} while (!validExercise);

	}

	void Calories::ask_duration() {

		bool validTime = false;
		do {
			std::cout << "How many time have you been doing this exercise in minutes? ";
			std::cin >> duration;

			if (duration <= 0) {
				std::cout << "Please introduce a valid time \n";
			}
			else {
				validTime = true;
			}
		} while (!validTime);

	}

	void Calories::calculate_calories(int p_weight) {

		int index = 0;
		for (int i = 0; i < exercises.size(); i++) {
			if (exercise == exercises[i]) {
				index = i;
			}
		}

		// Formula to calculate the calories burned
		calories_burned = (mets[index] * p_weight * (duration / 60));

		std::cout << "You burned " << calories_burned << " calories \n";

	}

	// Getters
	std::string User::get_name() {
		return name;
	}

	int User::get_gender() {
		return gender;
	}

	int User::get_age() {
		return age;
	}

	float User::get_weight() {
		return weight;
	}

	float User::get_height() {
		return height;
	}

	// Setter

	void User::set_name(std::string p_name) {
		name = p_name;
	}

	void User::set_gender(int p_gender) {
		gender = p_gender;
	}

	void User::set_age(int p_age) {
		age = p_age;
	}

	void User::set_weight(float p_weight) {
		weight = p_weight;
	}

	void User::set_height(float p_height) {
		height = p_height;
	}

	// Functions

	// Ask for the basic data
	void User::set_basic_data() {
		std::cout << "Please introduce your name: ";
		std::cin >> name;

		std::cout << "Your gender is: 1. Male 2. Female ";
		std::cin >> gender;

		std::cout << "Please introduce your age: ";
		std::cin >> age;

		std::cout << "Please introduce your weigth in kg: ";
		std::cin >> weight;

		std::cout << "Please introduce your height in cm: ";
		std::cin >> height;
	}
}

#pragma once
#include <iostream>
#include <vector>

namespace CaloriesCounter {


	class Calories {
	private:

		std::vector<std::string> exercises;
		std::vector<int> mets;
		std::string exercise;
		float duration;
		float calories_burned;
		float calories_recomented;

	public:

		// Getters
		std::string get_exercise();
		int get_duration();
		float get_calories_burned();
		float get_calories_recomended();

		// Setters
		void set_exercise(std::string p_exercise);
		void set_duration(int p_duration);
		void set_calories_burned(float p_calories_burned);
		void set_calories_recomended(float p_calories_recomended);

		// Functions
		void ask_exercise();
		void ask_duration();
		void calculate_calories(int p_weight);
		void fill_vector_exercises();
		void fill_vector_mets();
	};

	class User {
	private:
		std::string name;
		int gender;
		int age;
		float weight;
		float height;

	public:
		// Getters
		std::string get_name();
		int get_gender();
		int get_age();
		float get_weight();
		float get_height();

		// Setters
		void set_name(std::string p_name);
		void set_gender(int p_gender);
		void set_age(int p_age);
		void set_weight(float p_weight);
		void set_height(float p_height);

		// Functions
		void set_basic_data();

	};
}
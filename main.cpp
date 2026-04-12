#include <fstream>
#include <iostream>
#include <vector>

#include "Ingredient.h"

namespace
{
	std::string trim(const std::string& s)
	{
		const size_t start = s.find_first_not_of(' ');
		if (start == std::string::npos) return "";

		const size_t end = s.find_last_not_of(' ');
		return s.substr(start, end - start + 1);
	}

	std::vector<Ingredient> readFile(const std::string& filename)
	{
		std::ifstream file(filename);

		if (!file.is_open())
		{
			throw std::runtime_error("Could not open file: " + filename);
		}

		std::vector<Ingredient> ingredients;

		std::string line;
		while (std::getline(file, line))
		{
			Ingredient ingredient(
				trim(line.substr(0, 17)),
				trim(line.substr(17, 14)),
				std::stod(trim(line.substr(31, 10))),
				std::stod(trim(line.substr(41, 10))),
				std::stod(trim(line.substr(51, 8))),
				trim(line.substr(59, line.length() - 59))
			);

			ingredients.push_back(ingredient);
		}

		file.close();

		return ingredients;
	}

	void searchByCategory(const std::vector<Ingredient>& ingredients, const std::string& category)
	{
		int count = 0;
		std::cout << "\n\nIngredient   Category   Quantity   Price/lb   Reorder Point   Supplier\n";
		for (const auto& ingredient : ingredients)
		{
			if (ingredient.getCategory() == category)
			{
				ingredient.printAll();
				count++;
			}
		}

		if (count == 0)
		{
			std::cout << "Sorry, no " << category << " in inventory.\n\n";
		}
	}

	void listReorders(const std::vector<Ingredient>& ingredients)
	{
		int count = 0;
		std::cout << "\n\nIngredient   Category   Quantity   Price/lb   Reorder Point   Supplier\n";
		for (const auto& ingredient : ingredients)
		{
			if (ingredient.needsReorder())
			{
				ingredient.printAll();
				count++;
			}
		}

		if (count == 0)
		{
			std::cout << "All ingredients are sufficiently stocked.\n\n";
		}
	}
}

int main()
{
	std::vector<Ingredient> ingredients;

	try
	{
		ingredients = readFile("ingredients.csv");
	}
	catch (const std::runtime_error& ex)
	{
		std::cerr << ex.what() << '\n';
		return 1;
	}

	std::string category;

	bool isRunning = true;
	while (isRunning)
	{
		std::cout << "\n\nSmoothie Shop Inventory Management\n";
		std::cout << "1. Search by Category\n";
		std::cout << "2. List Ingredients Below Reorder Point\n";
		std::cout << "3. Exit Program\n";
		std::cout << "Please enter your choice (1-3): ";

		std::string choice;
		std::cin >> choice;

		switch (choice[0])
		{
		case '1':
			std::cout << "Enter a category to search: ";
			std::cin.ignore();
			std::getline(std::cin, category);
			searchByCategory(ingredients, category);
			break;

		case '2':
			listReorders(ingredients);
			break;

		case '3':
			isRunning = false;
			break;

		default:
			std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
			break;
		}
	}
}

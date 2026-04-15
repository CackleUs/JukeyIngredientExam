#include <fstream>
#include <iostream>
#include <vector>

#include "Ingredient.h"
#include "JukeyException.h"

namespace
{
	std::vector<Ingredient> readFile(const std::string& filename)
	{
		std::ifstream file(filename);

		if (!file.is_open())
		{
			throw std::runtime_error("Could not open file: " + filename);
		}

		std::string ingredient;
		std::string category;
		int qty;
		double pricePerLb;
		int reorderPoint;
		std::string supplier;

		std::vector<Ingredient> ingredients;

		while (file >> ingredient >> category >> qty >> pricePerLb >> reorderPoint >> supplier)
		{
			ingredients.push_back(Ingredient(ingredient, category, qty, pricePerLb, reorderPoint, supplier));
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
		ingredients = readFile("ingredients.txt");
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
			std::cin >> category;
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

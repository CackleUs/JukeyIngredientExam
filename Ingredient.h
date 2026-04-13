#pragma once
#include <string>

class Ingredient
{
private:
	std::string m_ingredient;
	std::string m_category;
	int m_quantity;
	double m_pricePerLb;
	int m_reorderPoint;
	std::string m_supplier;

public:
	std::string getIngredient() const;
	std::string getCategory() const;
	int getQuantity() const;
	double getPricePerLb() const;
	int getReorderPoint() const;
	std::string getSupplier() const;

	void setIngredient(const std::string& ingredient);
	void setCategory(const std::string& category);
	void setQuantity(const int& quantity);
	void setPricePerLb(const double& pricePerLb);
	void setReorderPoint(const int& reorderPoint);
	void setSupplier(const std::string& supplier);

	Ingredient(std::string ingredient, std::string category, int quantity, double pricePerLb, int reorderPoint, std::string supplier);

	double totalCost() const;
	bool needsReorder() const;

	void printAll() const;
};


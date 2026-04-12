#pragma once
#include <string>

class Ingredient
{
private:
	std::string m_ingredient;
	std::string m_category;
	double m_quantity;
	double m_pricePerLb;
	double m_reorderPoint;
	std::string m_supplier;

public:
	std::string getIngredient() const;
	std::string getCategory() const;
	double getQuantity() const;
	double getPricePerLb() const;
	double getReorderPoint() const;
	std::string getSupplier() const;

	void setIngredient(const std::string& ingredient);
	void setCategory(const std::string& category);
	void setQuantity(const double& quantity);
	void setPricePerLb(const double& pricePerLb);
	void setReorderPoint(const double& reorderPoint);
	void setSupplier(const std::string& supplier);

	Ingredient(std::string ingredient, std::string category, double quantity, double pricePerLb, double reorderPoint, std::string supplier);

	double totalCost() const;
	bool needsReorder() const;

	void printAll() const;
};


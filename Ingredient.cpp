#include "Ingredient.h"

#include <iomanip>
#include <iostream>

Ingredient::Ingredient(std::string ingredient, std::string category, int quantity, double pricePerLb, int reorderPoint,
                       std::string supplier)
{
	this->m_ingredient = ingredient;
	this->m_category = category;
	this->m_quantity = quantity;
	this->m_pricePerLb = pricePerLb;
	this->m_reorderPoint = reorderPoint;
	this->m_supplier = supplier;
}

std::string Ingredient::getIngredient() const
{
	return m_ingredient;
}

std::string Ingredient::getCategory() const
{
	return m_category;
}

int Ingredient::getQuantity() const
{
	return m_quantity;
}

double Ingredient::getPricePerLb() const
{
	return m_pricePerLb;
}

int Ingredient::getReorderPoint() const
{
	return m_reorderPoint;
}

std::string Ingredient::getSupplier() const
{
	return m_supplier;
}

void Ingredient::setIngredient(const std::string& ingredient)
{
	this->m_ingredient = ingredient;
}

void Ingredient::setCategory(const std::string& category)
{
	this->m_category = category;
}

void Ingredient::setQuantity(const int& quantity)
{
	this->m_quantity = quantity;
}

void Ingredient::setPricePerLb(const double& pricePerLb)
{
	this->m_pricePerLb = pricePerLb;
}

void Ingredient::setReorderPoint(const int& reorderPoint)
{
	this->m_reorderPoint = reorderPoint;
}

void Ingredient::setSupplier(const std::string& supplier)
{
	this->m_supplier = supplier;
}

double Ingredient::totalCost() const
{
	return m_quantity * m_pricePerLb;
}

bool Ingredient::needsReorder() const
{
	return m_quantity <= m_reorderPoint;
}

void Ingredient::printAll() const
{
	std::cout << std::left
		<< std::setw(13) << m_ingredient
		<< std::setw(11) << m_category
		<< std::fixed << std::setprecision(1) << std::setw(11) << m_quantity
		<< '$' << std::fixed << std::setprecision(2) << std::setw(10) << m_pricePerLb
		<< std::fixed << std::setprecision(1) << std::setw(16) << m_reorderPoint
		<< std::setw(21) << m_supplier
		<< '\n';
}

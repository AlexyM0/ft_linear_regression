#include <iostream>
#include <fstream>

double theta0 = 0;
double theta1 = 0;

void loadThetas()
{
    std::ifstream file("../02/thetas.txt");

    if (file.is_open())
    {
        file >> theta0 >> theta1;
        file.close();
        std::cout << "Loaded trained thetas.\n";
    }
    else
    {
        std::cout << "No trained thetas found.\n";
    }
}

double estimatePrice(double mileage)
{

    double price = theta0 + (theta1 * mileage);

    return price;
}

int main()
{
    loadThetas();

    double mileage;

    while (1)
    {
        std::cout << "Enter mileage: ";
        if (!(std::cin >> mileage))
        {
            std::cout << "Invalid input. Exiting." << std::endl;
            break;
        }

        std::cout << "Estimated price for " << mileage
                  << " is " << estimatePrice(mileage) << std::endl;
    }
}
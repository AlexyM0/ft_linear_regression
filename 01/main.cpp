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
        std::cout << "No trained thetas found. Using default (0, 0).\n";
    }
}

double estimatePrice(double mileage)
{
    // NORMALISATION (comme dans training)
    mileage /= 100000.0;

    double price = theta0 + (theta1 * mileage);

    // DENORMALISATION
    price *= 1000.0;

    return price;
}

int main()
{
    loadThetas(); // 🔥 important

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
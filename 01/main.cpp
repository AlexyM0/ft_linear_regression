#include <iostream>

double estimatePrice(double mileage)
{
    double theta0 = 0;
    double theta1 = 0;

    double price = theta0 + (theta1 * mileage);

    return price;

}

int main()
{
    double mileage;

    while(1)
    {
        std::cout << "Enter mileage: ";
        if (!(std::cin >> mileage))
        {
            std::cout << "Invalid input. Exiting." << std::endl;
                break;
        };
        std::cout << "The estimade price for: " << mileage << " is " << estimatePrice(mileage) << std::endl;
    }
}
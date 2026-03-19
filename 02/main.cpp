#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "calcul.hpp"

int main() 
{
    try
    {
        Calcul calcul("data.csv");
        calcul.train();
        calcul.save();
    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    
}
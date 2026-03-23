#ifndef CALCUL_H
#define CALCUL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Calcul
{
    private:

        std::vector<double> _km, _price;
        std::string _file;
        size_t count_line;
        double theta0 = 0;
        double theta1 = 0;
        double learningRate = 0.01;
        int iterations = 1000; 

    public:

        Calcul(std::string file) : _file(file)
        {
            std::ifstream f(_file);
            if(!f.is_open())
                throw "Invalide data file";
            std::string line;

            if (!std::getline(f, line))
                throw "File is empty";

            while (std::getline(f, line))
            {
                std::stringstream ss(line);
                std::string token;
                double k, p;

                std::getline(ss, token, ',');
                k = std::stod(token);

                std::getline(ss, token, ',');
                p = std::stod(token);

                _km.emplace_back(k);
                _price.emplace_back(p);
            }
            count_line = _km.size();
            if (count_line == 0)
                throw "No data in file";
            for (size_t i = 0; i < _km.size(); i++)
                _km[i] /= 100000.0;
            for (size_t i = 0; i < _price.size(); i++)
                _price[i] /= 1000.0;
        }

    void train()
    {
        for (int it = 0; it < iterations; it++)
        {
            double sum0 = 0;
            double sum1 = 0;

            for (size_t i = 0; i < count_line; i++)
            {
                double prediction = theta0 + theta1 * _km[i];
                double error = prediction - _price[i];

                sum0 += error;
                sum1 += error * _km[i];
            }

            double tmp0 = learningRate * sum0 / count_line;
            double tmp1 = learningRate * sum1 / count_line;

            theta0 = theta0 - tmp0;
            theta1 = theta1 - tmp1;
        }

        std::cout << "Training finished\n";
        std::cout << "theta0 = " << theta0 << std::endl;
        std::cout << "theta1 = " << theta1 << std::endl;
    }
    void save()
    {
        std::ofstream file("thetas.txt");
        if (!file.is_open())
            throw "Cannot open file to save thetas";

        file << theta0 << " " << theta1;
        file.close();
    }

};
#endif
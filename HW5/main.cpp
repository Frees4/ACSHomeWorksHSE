#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <iomanip>


void appendPortion(double portion, double &sumOfPortions) {
    sumOfPortions += portion;
}

void appendChildPortions(double portion1, double portion2, double &sumOfPortions) {
    std::thread *threads[2];
    threads[0] = new std::thread{appendPortion, portion1, std::ref(sumOfPortions)};
    threads[1] = new std::thread{appendPortion, portion2, std::ref(sumOfPortions)};

    threads[0]->join();
    delete threads[0];

    threads[1]->join();
    delete threads[1];
}

void appendDadPortions(double portion1, double portion2, double portion3, double portion4, double &sumOfPortions) {
    std::thread *threads[2];
    threads[0] = new std::thread{appendChildPortions, portion1, portion2, std::ref(sumOfPortions)};
    threads[1] = new std::thread{appendChildPortions, portion3, portion4, std::ref(sumOfPortions)};

    threads[0]->join();
    delete threads[0];

    threads[1]->join();
    delete threads[1];
}

int main() {
    std::vector<double> childrenPortions;
    std::string str;
    double sumOfPortions = 0;
    int sumOfWill;

    std::cout << "Enter int value - amount of a will " << "\n";
    std::cin >> str;
    try {
        sumOfWill = stoi(str);
    } catch (const std::exception &) {
        std::cout << "Incorrect input amount of a will, it should be integer" << "\n";
        return 0;
    }
    if (sumOfWill <= 0) {
        std::cout << "Incorrect input amount of a will, it should be positive" << "\n";
        return 0;
    }

    std::cout << "Enter the portion of the great-grandchildren:" << "\n";
    for (int i = 0; i < 8; ++i) {
        std::cin >> str;
        try {
            childrenPortions.push_back(std::stod(str));
        } catch (const std::exception &) {
            std::cout << "Incorrect input of portions values, it should be double" << "\n";
            return 0;
        }
    }

    std::thread *threads[2];
    threads[0] = new std::thread{appendDadPortions, childrenPortions[0], childrenPortions[1],
                                 childrenPortions[2], childrenPortions[3], std::ref(sumOfPortions)};
    threads[1] = new std::thread{appendDadPortions, childrenPortions[4], childrenPortions[5],
                                 childrenPortions[6], childrenPortions[7], std::ref(sumOfPortions)};

    threads[0]->join();
    delete threads[0];

    threads[1]->join();
    delete threads[1];

    double epsilon = 0.000000001;
    if (sumOfPortions < 1.0+epsilon && sumOfPortions > 1.0-epsilon) {
        std::cout << "The lawyer didn't cheated you for" << "\n";
    } else if (sumOfPortions >= 0 && sumOfPortions < 1.0){
        std::cout << "The lawyer cheated you for: ";
        std::cout << std::fixed << std::setprecision(2) << (1 - sumOfPortions) * sumOfWill;
        std::cout << "$" << "\n";
    } else {
        std::cout << "Incorrect input: sum of portions should be in [0, 1]" << "\n";
        return 0;
    }

    return 0;
}
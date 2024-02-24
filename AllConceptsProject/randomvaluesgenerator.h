#ifndef RANDOMVALUESGENERATOR_H
#define RANDOMVALUESGENERATOR_H
#include <random>

class RandomValuesGenerator
{
public:
    static RandomValuesGenerator& getInstance();
     RandomValuesGenerator(const RandomValuesGenerator&) = delete;
     void operator=(const RandomValuesGenerator&) = delete;
     int generateRandomInt(int min, int max);
     double generateRandomReal(double min, double max);
private:
    RandomValuesGenerator();
    std::mt19937 m_rng;

};

#endif // RANDOMVALUESGENERATOR_H

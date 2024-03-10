#include "randomvaluesgenerator.h"

RandomValuesGenerator::RandomValuesGenerator () : m_rng(std::random_device{}())
{

}
RandomValuesGenerator &RandomValuesGenerator::getInstance()
{
    static RandomValuesGenerator instance;
    return instance;
}



int RandomValuesGenerator::generateRandomInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(m_rng);
}

double RandomValuesGenerator::generateRandomReal(double min, double max)
{
    std::uniform_real_distribution<double> dist(min, max);
    return dist(m_rng);
}

QString RandomValuesGenerator::generateRandomString(int strLength)
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString randomString;
    for(int i = 0; i < strLength; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}

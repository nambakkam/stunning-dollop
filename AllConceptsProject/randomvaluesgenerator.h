#ifndef RANDOMVALUESGENERATOR_H
#define RANDOMVALUESGENERATOR_H
#include <QObject>
#include <QRandomGenerator>
#include <QString>
#include <QtQml>
#include <random>

inline constexpr int kSmallSize = 10000;
inline constexpr int kMediumSize = 50000;
inline constexpr int kLargeSize = 100000;
inline constexpr int kLowerLimit = 10;
inline constexpr int kUpperLimit = 1000;

/**
 * @brief The RandomValuesGenerator class provides functionality to generate
 * random values.
 *
 * This class provides methods to generate random integers, real numbers, and
 * strings.
 */
class RandomValuesGenerator : public QObject {
  Q_OBJECT
public:
  /**
   * @brief sizeEnum Enum defining the size options for generating random
   * values.
   */
  enum sizeEnum { SMALL = 1, MEDIUM, LARGE };
  Q_ENUM(sizeEnum)
  /**
   * @brief getInstance Gets the singleton instance of RandomValuesGenerator.
   *
   * @return A reference to the singleton instance of RandomValuesGenerator.
   */
  static RandomValuesGenerator &getInstance();
  /**
   * @brief generateRandomInt generates a random integer within the specified
   * range.
   *
   * @param min The minimum value of the range.
   * @param max The maximum value of the range.
   * @return The generated random integer.
   */
  int generateRandomInt(int min, int max);
  /**
   * @brief generateRandomReal generates a random real number within the
   * specified range.
   *
   * @param min The minimum value of the range.
   * @param max The maximum value of the range.
   * @return The generated random real number.
   */
  double generateRandomReal(double min, double max);
  /**
   * @brief generateRandomString generates a random string with the specified
   * length.
   *
   * @param strLength The length of the random string to generate.
   * @return The generated random string.
   */
  QString generateRandomString(int strLength);

private:
  RandomValuesGenerator(QObject *parent = nullptr);
  std::mt19937
      m_rng; /**< Mersenne Twister pseudo-random number generator engine. */
};

#endif // RANDOMVALUESGENERATOR_H

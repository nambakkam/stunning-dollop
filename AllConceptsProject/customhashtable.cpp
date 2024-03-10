#include "customhashtable.h"
#include <QDebug>
#include "randomvaluesgenerator.h"

CustomHashTable::CustomHashTable(QObject *parent, int size)
    : QObject{parent}, m_size{size}, data{size}
{
    createHashtable(SMALLSIZE);
    displayData();
    qDebug() << "hashTable created " << get_displayData();
    set();
    displayData();
    qDebug() << "new Key added " << get_displayData();
    qDebug()<< "get Value " << get();
    qDebug() << "All keys " <<getAllKeys();
    removeKey();
    displayData();
    qDebug() << "key Removed " << get_displayData();
}

void CustomHashTable::set()
{
    QString key = RandomValuesGenerator::getInstance().generateRandomString(LOWERLIMIT);
    int value = RandomValuesGenerator::getInstance().generateRandomInt(LOWERLIMIT,UPPERLIMIT);
    int hashValue = hash(key);
    keyValuePair pair;
    pair.key = key;
    pair.value = value;
    QVector<QString> keys = getAllKeys();
    if(!keys.contains(key)){
       data[hashValue].push_back(pair);
    }
    else{
        qDebug() << "Value for the key " << key << " is already set";
    }
}

int CustomHashTable::get()
{
    QVector<QString> keys = getAllKeys();
    int index = RandomValuesGenerator::getInstance().generateRandomInt(0,keys.length());
    QString key = keys[index];
    qDebug() << "key " << key;
    int hashValue = hash(key);
    int value = 0;
    for(int i=0; i< data[hashValue].length();i++){
        if(data[hashValue].at(i).key == key){
            value = data[hashValue].at(i).value;
            break;
        }
    }
    return value;
}
void CustomHashTable::removeKey(){
        QVector<QString> keys = getAllKeys();
        int index = RandomValuesGenerator::getInstance().generateRandomInt(0,keys.length());
        QString key = keys[index];
    int hashValue = hash(key);
    for(int i=0; i< data[hashValue].length();i++){
        if(data[hashValue].at(i).key == key){
            data[hashValue].removeAt(i);
            break;
        }
    }
    qDebug() << "The key " << key  << " doesn't exist ";
}

QVector<QString> CustomHashTable::getAllKeys()
{
    QVector<QString> keys;
    for(int i=0; i< data.length(); i++){
        for(int j=0; j< data.at(i).length(); j++){
            keys.append(data.at(i).at(j).key);
        }
    }
    return keys;
}

int CustomHashTable::hash(const QString &key)
{
    int hash = 0;
    for (int i = 0; i < key.length(); ++i) {
        hash = (hash + key.at(i).unicode() * i) % m_size;
    }
    return hash;
}

void CustomHashTable::createHashtable(int size){
    data.clear();
    data.resize(size);
    m_size = size;
    for(int i = 0; i< size ; i++){
        set();
    }
}

void CustomHashTable::displayData(){
    QString result;
    for (int i = 0; i< data.length(); i++) {
        QVector<keyValuePair>& innerVector = data[i];
        for (const keyValuePair& pair : innerVector) {
            result.append("Key: ").append(pair.key).append(" Value: ").append(QString::number(pair.value)).append("\n");
        }
        result.append("-----\n"); // Separate inner vectors for better readability
    }
    set_displayData(result);
}





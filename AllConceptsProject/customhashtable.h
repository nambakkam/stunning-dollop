#ifndef CUSTOMHASHTABLE_H
#define CUSTOMHASHTABLE_H

#include <QObject>

class CustomHashTable : public QObject
{
    Q_OBJECT
public:
    explicit CustomHashTable(QObject *parent = nullptr);

signals:

};

//class HashTable {
//  constructor(size){
//    this.data = new Array(size);
//  }

//  _hash(key) {
//    let hash = 0;
//    for (let i =0; i < key.length; i++){
//        hash = (hash + key.charCodeAt(i) * i) % this.data.length
//    }
//    return hash;
//  }

//  set(key,value){
//    let index = this._hash(key);

//    if(!this.data[index])
//    {
//    this.data[index] = [];
//    }

//    this.data[index].push([key,value]);
//  }
//  get(key)
//  {
//   let index = this._hash(key);
//   const current_bucket = this.data[index];
//   let current_item = [];
//   for(let i =0; i < current_bucket.length; i++)
//   {
//     current_item = current_bucket[i];
//     if(current_item[0] === key)
//     {
//       console.log(current_item[1]);
//     }
//   }
//  }

//  keys()
//  {
//    const keysArray = [];
//    for(let i=0; i<this.data.length;i++)
//    {
//      if(this.data[i]){
//        keysArray.push(this.data[i][0][0]);
//      }
//    }
//    return keysArray;
//  }
//}

#endif // CUSTOMHASHTABLE_H

#ifndef UNSORTEDARRAYDICTIONARY_H
#define UNSORTEDARRAYDICTIONARY_H

#include <stdexcept>
#include <iostream>

#include "Dictionary.h"
#include "ArrayList.h"
#include "DLinkedList.h"
#include "KVPair.h"


using std::runtime_error;
using std::cout;
using std::cin;

template <typename K, typename V>
class UnsortedArrayDictionary : public Dictionary<K, V> {
private:
    ArrayList<KVPair<K, V>> *pairs;

    void checkNotExisting(K key){
        KVPair<K, V> p(key);
        if (pairs->contains(p))
            throw runtime_error("Duplicated key.");
    }
    void checkExisting(K key){
        KVPair<K, V> p(key);
        if(!pairs->contains(p))
            throw runtime_error("Key not found");
    }
public:
    UnsortedArrayDictionary(int max = DEFAULT_MAX_SIZE){
        pairs = new ArrayList<KVPair<K, V>>(max);
    }
    ~UnsortedArrayDictionary(){
        delete pairs;
    }
    void insert(K key, V value){
        checkNotExisting(key);
        KVPair<K, V> p(key, value);
        pairs->append(p);
    }
    V remove(K key){
        checkExisting(key);
        KVPair<K, V> p(key);    //el profe en check existing queda en la posición q hay que eliminar
        pairs->goToPos(pairs->indexOf(p));
        p = pairs->remove();
        return p.value;
    }
    V getValue(K key){
        checkExisting(key);
        KVPair<K, V> p(key);
        pairs->goToPos(pairs->indexOf(p));
        p = pairs->getElement();
        return p.value;
    }
    void setValue(K key, V value){
        checkExisting(key);
        KVPair<K, V> p(key, value);
        pairs->goToPos(pairs->indexOf(p));
        pairs->remove();
        pairs->append(p);
    }
    bool contains(K key){
        KVPair<K, V> p(key);
        return pairs->contains(p);
    }
    List<K>* getKeys(){
        DLinkedList<K> *keys = new DLinkedList<K>(); //en memoria dinamica sino devolvemos algo que se destruye cuando termina de ejecutar
        for(pairs->goToStart(); !pairs->atEnd(); pairs->next()){
            auto p = pairs->getElement();
            keys->append(p.key);
        }
        return keys;
    }
    List<V>* getValues(){
        DLinkedList<V> * values = new DLinkedList<V>();
        for(pairs->goToStart(); !pairs->atEnd(); pairs->next()){
            auto p = pairs->getElement();
            values->append(p.value);
        }
        return values;
    }
    int getSize(){
        return pairs->getSize();
    }
    void print(){
        cout << "[ ";
        for(pairs->goToStart(); !pairs->atEnd(); pairs->next()){
            auto p = pairs->getElement();
            cout << p.key << ": " << p.value << " ";
        }
        cout << "]";
    }
};

#endif // UNSORTEDARRAYDICTIONARY_H

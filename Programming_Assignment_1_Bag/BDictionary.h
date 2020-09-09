/* BDicionary.h 
	
	Author: Cameron Burkholder
	Created on 09/09/2020

*/

#include "ABag.h"
#include "kvpair.h"
#include "dictionaryADT.h"
#include <memory>

#pragma once
template <typename Key, typename V>
class BDictionary : public Dictionary<Key, V> {
private:
    ABag<KVpair<Key, V>>* bag;
public:
    BDictionary<Key, V>(int size = defaultSize) {
        bag = new ABag<KVpair<Key, V>>(size);
    }  
    ~BDictionary() {
        delete bag;
    }

    // Reinitialize dictionary
    void clear() {
        bag->emptyBag();
    }

    // Insert a record
    // k: The key for the record being inserted.
    // v: The record being inserted.
    // Return true if insert is successful and false otherwise
    bool insert(const Key& k, const V& v) {
        std::unique_ptr<KVpair<Key, V>> temp = std::make_unique<KVpair<Key, V>>(k, v);
        return bag->addItem(*temp);
    }

    
    // Looks for a record using the key and if found does the following:
    // - updates the V& rtnVal
    // - removes the record from the dictionary
    // - returns true
    // If the record is not found the function returns false.
    bool remove(const Key& k, V& rtnVal) {
        std::unique_ptr<KVpair<Key, V>> temp = std::make_unique<KVpair<Key, V>>(k, rtnVal);
        bool isFound = bag->remove(*temp);
        if (isFound) {
            rtnVal = temp->value();
        }
        return isFound;
    }

    // Takes an arbitrary record from the dictionary and does the following:
    // - updates the V& returnValue
    // - removes the record from the dictionary
    // - returns true
    // If the dictionary is empty the function returns false.
    bool removeAny(V& returnValue) {
        std::unique_ptr<KVpair<Key, V>> temp = std::make_unique<KVpair<Key, V>>();
        bool isRemoved = bag->removeTop(*temp);
        if (isRemoved) {
            returnValue = temp->value();
        }
        return isRemoved;
    }

    // Looks for a record using the key and if found does the following:
    // - updates the V& returnValue
    // - returns true
    // If the record is not found the function returns false.
    bool find(const Key& k, V& returnValue) const {
        std::unique_ptr<KVpair<Key, V>> temp = std::make_unique<KVpair<Key, V>>(k, returnValue);
        bool isFound = bag->find(*temp);
        if (isFound) {
            returnValue = temp->value();
        }
        return isFound;
    }

    // Return the number of records in the dictionary.
    int size() {
        return bag->size();
    }
};
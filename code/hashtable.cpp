#include "hashtable.h"

hashTable::hashTable(int capacity)
{
    size = 0;
    this->capacity = capacity;
    buckets = new sortedLinkedList[capacity];
}

hashTable::~hashTable()
{
    delete [] buckets;
}

// initializes the capacity of the hash table with the use of prime numbers
int hashTable::initialize(int newSize)
{
    delete [] buckets;

    static int primes[] = {71, 173, 281, 349, 463, 541, 601, 733, 809, 863, 941, 1583,
                           2423, 3181, 3257, 3331, 4139, 4409, 4831, 4937, 5003, 6793,
                           8017, 9439, 10177, 11003, 12791, 13339, 14503, 15187, 16811,
                           17971, 18749, 19991, 20897, 21841, 22391, 23017, 24413, 25247,
                           26801, 27947, 28579, 29443, 30059, 32063, 36559, 38461, 43789, 
                           45943, 49801, 52963, 55541, 59351, 62501, 65147, 70729, 76961,
                           78041, 80051, 84299, 87181, 93481, 96787, 99881, 102161, 104059};

    capacity = primes[0];

    for(int i = 0; i < (sizeof(primes) / sizeof(primes[0])) - 1; i++)
    {
        if(newSize > primes[i])
        {
            capacity = primes[i + 1];
        }

        else
        {
            break;
        }
    }
    
    size = 0;
    buckets = new sortedLinkedList[capacity];
}

int hashTable::getSize()
{
    return size;
}

int hashTable::getCapacity()
{
    return capacity;
}


double hashTable::getLoadFactor()
{
    return size / (double) capacity;
}

void hashTable::insert(int key, int value)
{
    int h = hashKey(key);

    buckets[h].insert(key,value);
    size++;
}

void hashTable::insert(linkedListNode* newNode)
{
    int h = hashKey(newNode->key);

    buckets[h].insert(newNode);
    size++;
}

bool hashTable::search(int key)
{
    int h = hashKey(key);

    return buckets[h].search(key);
}

bool hashTable::find(int key, int &value)
{
    int h = hashKey(key);

    return buckets[h].find(key,value);
}
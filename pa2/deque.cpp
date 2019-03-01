/**
 * @file deque.cpp
 * Implementation of the Deque class.
 *
 */

/* Constructor for the Deque class */
template <class T>
Deque<T>::Deque(){
    //data = new vector<T>;
    k1 = 0; //index of first data element
    k2 = 0; //number of elements in the vector 
}

/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
 */
template <class T>
void Deque<T>::pushR(T const& newItem){
    data.push_back(newItem);
    k2++;
}

/**
 * Removes the object at the left of the Deque, and returns it to the
 * caller.
 *
 * See .h file for implementation notes. 
 *
 * @return The leftmost item of the Deque.
 */
template <class T>
T Deque<T>::popL(){
    T temp = data[k1];
    if (k2 == 1) {
        data = *(new vector<T>);
        k1 = 0;
        k2 = 0;
        return temp;
    }
    k1++;
    k2--;

   // if amount of stuff is half the size of vector, resize
   if(k2 <= k1){
       vector<T> oldData = data;
       data = *(new vector<T>);

        for(int i = k1; i < k2+k1; i++){ 
            data.push_back(oldData[i]); 
        }

        k1 = 0;
   }
    return temp;
}
/**
 * Removes the object at the right of the Deque, and returns it to the
 * caller.
 *
 * @return The rightmost item of the Deque.
 */
template <class T>
T Deque<T>::popR(){
    T temp = data.back();
    data.pop_back();
    k2 --;

    return temp;
}

/**
 * Finds the object at the left of the Deque, and returns it to the
 * caller. Unlike popL(), this operation does not alter the deque.
 *
 * @return The item at the left of the deque.
 */
template <class T>
T Deque<T>::peekL(){
    return data.at(k1);
}

/**
 * Finds the object at the right of the Deque, and returns it to the
 * caller. Unlike popR(), this operation does not alter the deque.
 *
 * @return the value of The item at the right of the deque.
 */
template <class T>
T Deque<T>::peekR(){
    return data.back();
}

/**
 * Determines if the Deque is empty.
 *
 * @return bool which is true if the Deque is empty, false otherwise.
 */
template <class T>
bool Deque<T>::isEmpty() const {
    return k2 == 0;
}



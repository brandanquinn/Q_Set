#ifndef Q_SET
#define Q_SET

#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>

using namespace std;

class Q_Set {
    private:
        vector<string> elements;
        string type_of;
        int index_to_remove;
        // These functions below convert string vector to vectors of various types.
        vector<int> get_int_vec();
        vector<char> get_char_vec();
        vector<double> get_double_vec();
        vector<float> get_float_vec();
        vector<long> get_long_vec();
        vector<long long> get_long_long_vec();
        vector<short> get_short_vec();

    public:
        /**
         * NAME: Q_Set() 
         *
         * PURPOSE: Constructor for Q_Set class.
         * 
         * PARAMS:
         *  - vector<T,A> const& vec
         *      - const templated vector, can be of any primitive C++ type, used to initialize set.
         * 
         * DESCRIPTION:
         *  - If vector provided is empty, print error and terminate program.
         *  - Get type of vector by checking first element using typeid (typeinfo library)
         *  - Using if statement chain, update member variable type_of with proper type of set.
         *      - Currently only applies to basic primitive data types
         *  - Currently converts each element to a string to be stored in vector container.
         * 
         * RETURNS:
         *  None.
         * 
         * AUTHOR:
         * -Brandan Quinn
         * 
         * DATE:
         *  2/26/19 12:55pm
         *  
         **/
        template<typename T, typename A>
        Q_Set(vector<T,A> const& vec) {
            // Variable to get index of element to remove in function defined below, set to -1 by default.
            this->index_to_remove = -1;
            // MUST ACCOUNT FOR EMPTY VEC
            if (vec.empty()) {
                cout << "Cannot initialize empty set. Try again." << endl;
                terminate(); 
            }
            string vec_type(typeid(vec[0]).name());
            cout << "Type of set: " << vec_type << endl;

            if (vec_type == "i") {
                // int
                this->type_of = "int";
            } else if (vec_type == "c") {
                // char
                this->type_of = "char";
            } else if (vec_type == "d") {
                // double
                this->type_of = "double";
            } else if (vec_type == "f") {
                // float
                this->type_of = "float";
            } else if (vec_type == "l") {
                // long int
                this->type_of = "long";
            } else if (vec_type == "x") {
                // long long
                this->type_of = "long long";
            } else if (vec_type == "s") {
                // short
                this->type_of = "short";
            } else {
                // string
                throw "Q_Set does not accept strings.";
                terminate();
            }

            if (this->type_of == "char") {
                for (int i = 0; i < vec.size(); i++) {
                    string s;
                    s.push_back(vec[i]);
                    cout << s << " added to set." << endl;
                    this->elements.push_back(s);
                }
            } else {
                // Convert each element to string.
                for (int i = 0; i < vec.size(); i++) {
                    this->elements.push_back(to_string(vec[i]));
                    // cout << to_string(vec[i]) << " added to set." << endl;
                }
            }
        }

        /**
         * NAME: add()
         * 
         * PURPOSE: Add element to existing set with type checking and uniqueness.
         * 
         * PARAMS:
         *  - T element, templated element to add to set - can be of any of the basic primitive types (int, char, double, float)
         * 
         * DESCRIPTION:
         *  - Get type of element being added.
         *  - If type is not the same as set, print error and return false.
         *  - Else:
         *      - Get properly typed vector of elements in set and check to see if element to add is already in set.
         *      - If it is found, print error and return false.
         *  - Add element to set, print confirmation and return true.
         * 
         *  RETURNS:
         *  - Boolean value representing whether or not element was added to the set.
         * 
         * AUTHOR:
         *  - Brandan Quinn
         * 
         * DATE:
         *  2/26/19 3:33pm
         **/
        template<typename T>
        bool add(T element) {
            string element_type(typeid(element).name());

            if (element_type[0] != this->type_of[0]) {
                cout << "Element is of different type, cannot be added." << endl;
                return false;
            } else {
                // Must check uniqueness.

                if (this->type_of == "int") {
                    vector<int> elem_vec = get_int_vec();
                    for (int i = 0; i < elem_vec.size(); i++) {
                        if (elem_vec[i] == element) {
                            cout << "Element already exists in set, cannot be added." << endl;
                            return false;
                        }
                    }
                }
                else if (this->type_of == "char") {
                    vector<char> elem_vec = get_char_vec();
                    for (int i = 0; i < elem_vec.size(); i++) {
                        if (elem_vec[i] == element) {
                            cout << "Element already exists in set, cannot be added." << endl;
                            return false;
                        }
                    }
                }
                else if (this->type_of == "double") {
                    vector<double> elem_vec = get_double_vec();
                    for (int i = 0; i < elem_vec.size(); i++) {
                        if (elem_vec[i] == element) {
                            cout << "Element already exists in set, cannot be added." << endl;
                            return false;
                        }
                    }
                }
                else if (this->type_of == "float") {
                    vector<float> elem_vec = get_float_vec();
                    for (int i = 0; i < elem_vec.size(); i++) {
                        if (elem_vec[i] == element) {
                            cout << "Element already exists in set, cannot be added." << endl;
                            return false;
                        }
                    }
                } else if (this->type_of == "long") {
                    vector<long> elem_vec = get_long_vec();
                    for (int i = 0; i < elem_vec.size(); i++) {
                        if (elem_vec[i] == element) {
                            cout << "Element already exists in set, cannot be added." << endl;
                            return false;
                        }
                    }
                } else if (this->type_of == "long long") {
                    vector<long long> elem_vec = get_long_long_vec();
                    for (int i = 0; i < elem_vec.size(); i++) {
                        if (elem_vec[i] == element) {
                            cout << "Element already exists in set, cannot be added." << endl;
                            return false;
                        }
                    }
                } else if (this->type_of == "short") {
                    vector<short> elem_vec = get_short_vec();
                    for (int i = 0; i < elem_vec.size(); i++) {
                        if (elem_vec[i] == element) {
                            cout << "Element already exists in set, cannot be added." << endl;
                            return false;
                        }
                    }
                }

                this->elements.push_back(to_string(element));
                cout << element << " has been added to your set." << endl;
                return true;
            }
        }
        /**
         * NAME: remove()
         * 
         * PURPOSE:
         *  - Remove given element from set with type checking.
         * 
         * PARAMS:
         *  - T element, Templated element to be removed from set.
         * 
         * DESCRIPTION:
         *  - Get type of element to remove.
         *  - If type is not the same as current set, print error and return false.
         *  - Else, get typed vector and iterate through each element in vector.
         *      - If element found is equal to element to remove, remove element at index, print confirmation and return true.
         *  - Print element not found error and return false.
         * 
         * RETURNS:
         *  - Boolean value representing whether or not element was removed.
         * 
         * AUTHOR:
         *  - Brandan Quinn
         * 
         * DATE:
         *  2/26/19 3:47pm
         * 
         **/ 
        template<typename T>
        bool remove(T element) {
            string element_type(typeid(element).name());

            if (element_type[0] != this->type_of[0]) {
                cout << "Element is of different type, cannot be removed." << endl;
                return false;
            } else {
                // Check to see if element exists, if found - remove it.
                if (contains(element)) {
                    cout << "Element found, removing from set." << endl;
                    if (this->index_to_remove == -1) {
                        cout << "Index to remove not properly set, aborting." << endl;
                        terminate();
                    }
                    this->elements.erase(this->elements.begin() + this->index_to_remove);

                    return true;
                }

                cout << element << " was not found in your set." << endl;
                return false;
            }
        }
        // Getter for type_of attribute.
        // Defined in cpp.
        string get_type_of();

        // Computes size by getting size of vector element container and returns it as integer.
        // Defined in cpp.
        int size();

        /**
         * NAME: contains()
         * 
         * PURPOSE: Check to see if set contains an element, if found return true and set index_to_remove for the remove() function.
         * 
         * PARAMS:
         *  - T element, Templated element - handled differently depending on type.
         * 
         * DESCRIPTION:
         *  - Get properly typed vector of elements.
         *  - Iterate through vector and if element in question is found, set index_to_remove private member var and return true.
         *  - Return false.
         * 
         * RETURNS:
         *  - Boolean value determining whether or not element was contained in set.
         * 
         * AUTHOR:
         *  - Brandan Quinn
         * 
         * DATE:
         *  2/27/19 5:04pm
         **/
        template<typename T>
        bool contains(T element) {
            // If element is found in container, return true. Else return false.
            if (this->type_of == "int") {
                vector<int> elem_vec = get_int_vec();
                for (int i = 0; i < elem_vec.size(); i++) {
                    if (elem_vec[i] == element) {
                        this->index_to_remove = i;
                        return true;
                    }
                }
            } else if (this->type_of == "char") {
                vector<char> elem_vec = get_char_vec();
                for (int i = 0; i < elem_vec.size(); i++) {
                    if (elem_vec[i] == element) {
                        this->index_to_remove = i;
                        return true;
                    }
                }
            } else if (this->type_of == "double") {
                vector<double> elem_vec = get_double_vec();
                for (int i = 0; i < elem_vec.size(); i++) {
                    if (elem_vec[i] == element) {
                        this->index_to_remove = i;
                        return true;
                    }
                }
            } else if (this->type_of == "float") {
                vector<float> elem_vec = get_float_vec();
                for (int i = 0; i < elem_vec.size(); i++) {
                    if (elem_vec[i] == element) {
                        this->index_to_remove = i;
                        return true;
                    }
                }
            } else if (this->type_of == "long") {
                vector<long> elem_vec = get_long_vec();
                for (int i = 0; i < elem_vec.size(); i++) {
                    if (elem_vec[i] == element) {
                        this->index_to_remove = i;
                        return true;
                    }
                }
            } else if (this->type_of == "long long") {
                vector<long long> elem_vec = get_long_long_vec();
                for (int i = 0; i < elem_vec.size(); i++) {
                    if (elem_vec[i] == element) {
                        this->index_to_remove = i;
                        return true;
                    }
                }
            } else if (this->type_of == "short") {
                vector<short> elem_vec = get_short_vec();
                for (int i = 0; i < elem_vec.size(); i++) {
                    if (elem_vec[i] == element) {
                        this->index_to_remove = i;
                        return true;
                    }
                }
            }

            return false;
        }

        /**
         * NAME: set_union()
         * 
         * PURPOSE: 
         *  - Perform union on self with other set passed as parameter.
         * 
         * PARAMS:
         *  Q_Set s, Other set to union with current set.
         * 
         * DESCRIPTION:
         *  - If types differ, print error message and make no changes to set.
         *  - Else:
         *      - Init element_found flag to false.
         *      - For each element x in other set, compare with each element y in primary set.
         *      - If x == y, set element_found flag to true.
         *      - After iterating through primary set, if element_found is true: add x to primary set.
         * 
         * RETURNS: None
         * 
         * AUTHOR:
         *  - Brandan Quinn
         * 
         * DATE:
         *  2/27/19 5:09pm
         **/
        void set_union(Q_Set s);

        /**
         * NAME: set_intersection()
         * 
         * PURPOSE:
         *  - Perform intersection on self with other set passed as parameter.
         * 
         * PARAMS:
         *  Q_Set s, Other set to intersect with current set.
         * 
         * DESCRIPTION:
         *  - If types differ, print error message and empty current set (intersection of set with empty set is empty set)
         *  - Else:
         *      - Init new string vector to add intersecting elements to.
         *      - For each element x in primary set, compare to element y in other set.
         *      - If x == y, add x to vector of intersecting elements and break out of current loop.
         *  - Set elements of current set to vector of intersecting elements.
         * 
         * RETURNS: None
         * 
         * AUTHOR:
         *  - Brandan Quinn
         * 
         * DATE:
         *  2/27/19 5:16pm
         **/ 
        void set_intersection(Q_Set s);

        /**
         * NAME: empty()
         * 
         * PURPOSE: Empty set of all elements.
         * 
         * PARAMS: None
         * 
         * DESCRIPTION:
         *  - Call clear() on vector of elements contained in set.
         * 
         * RETURNS: None
         * 
         * AUTHOR:
         *  - Brandan Quinn
         * 
         * DATE:
         *  2/27/19 5:19pm
         **/
        void empty();

        /**
         * NAME: display()
         * 
         * PURPOSE: Display elements of current set.
         * 
         * PARAMS: None
         * 
         * DESCRIPTION:
         *  - Iterate through elements in set and print each element within brackets.
         * 
         * RETURNS: None
         * 
         * AUTHOR:
         *  - Brandan Quinn
         * 
         * DATE:
         *  2/27/19 5:17pm
         **/ 
        void display();



        
};

#endif
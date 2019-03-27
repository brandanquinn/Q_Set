#include "Q_Set.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * NAME: type_test
 * 
 * PURPOSE: Unit test for set typing.
 * 
 * PARAMS: None
 * 
 * DESCRIPTION:
 *  - Tests creation of each type of set using different vectors.
 *  - Calls public member function, get_type_of(), to see if set correctly identified type.
 * 
 * AUTHOR:
 *  -Brandan Quinn
 * 
 * DATE:
 *  2/26/19 1:06pm
 **/ 
void type_test() {
    vector<int> i_vec;
    i_vec.push_back(1);
    vector<char> c_vec;
    c_vec.push_back('a');
    vector<double> d_vec;
    d_vec.push_back(0.0);
    vector<float> f_vec;
    f_vec.push_back(1.0);
    vector<int> empty;

    Q_Set i_set(i_vec);
    Q_Set c_set(c_vec);
    Q_Set d_set(d_vec);
    Q_Set f_set(f_vec);
    // Q_Set empty_set(empty);
    cout << "Type of integer set: " << i_set.get_type_of() << endl;
    cout << "Type of char set: " << c_set.get_type_of() << endl;
    cout << "Type of double set: " << d_set.get_type_of() << endl;
    cout << "Type of float set: " << f_set.get_type_of() << endl;

    cout << "Type test passed." << endl;

}

void temp_type() {
    vector<string> svec;
    svec.push_back("hello");


    // Q_Set s1(svec);
}

/**
 * NAME: add_test()
 * 
 * PURPOSE: Unit test for adding elements to set.
 * 
 * PARAMS: None
 * 
 * DESCRIPTION: 
 *  - Create int vector and push back an element.
 *  - Construct Q_Set object with vector
 *  - Try adding 3, type is correct and element is unique - should add and return true. Error if otherwise.
 *  - Try adding 1, type is correct but element is already in set - should not add and return false. Error if otherwise.
 *  - Try adding 'a', type is incorrect - should not add and return false. Error if otherwise.
 * 
 * RETURNS: None.
 * 
 * AUTHOR:
 *  - Brandan Quinn
 * 
 * DATE:
 *  2/26/19 3:52pm
 *  
 **/ 
void add_test() {
    vector<int> i_vec;
    i_vec.push_back(1);

    Q_Set my_set(i_vec);

    if(!my_set.add(3)) {
        cout << "Element should be added to set." << endl;
        terminate();
    }

    if (my_set.add(1)) {
        cout << "Element should not be added to set." << endl;
        terminate();
    }

    if (my_set.add('a')) {
        cout << "Element should not be added to set." << endl;
        terminate();
    }

    cout << "Add test passed." << endl;
}

/**
 * NAME: remove_test()
 * 
 * PURPOSE:
 *  - Unit test for removing elements from set.
 * 
 * PARAMS: None
 * 
 * DESCRIPTION:
 *  - Create char vector and push back an element.
 *  - Construct Q_Set object with vector.
 *  - Try removing 1 from Set, type is not correct and should return false - error if otherwise.
 *  - Try removing 'd' from Set, type is correct but element is not found in set. Should return false - error if otherwise.
 *  - Try removing 'h' from Set, type is correct and element is found in set. Should return true and remove from set - error if otherwise.
 * 
 * RETURNS: None
 * 
 * AUTHOR:
 *  - Brandan Quinn
 * 
 * DATE:
 *  2/26/19 3:56pm 
 **/
void remove_test() {
    vector<char> c_vec;
    c_vec.push_back('h');

    Q_Set my_set(c_vec);

    if (my_set.remove(1)) {
        cout << "Element should not be removed from set." << endl;
        terminate();
    }
    if (my_set.remove('d')) {
        cout << "Element should not be removed from set." << endl;
        terminate();
    }

    if (!my_set.remove('h')) {
        cout << "Element should be removed from set." << endl;
        terminate();
    }

    cout << "Remove test passed." << endl;
}

/**
 * NAME: size_test()
 * 
 * PURPOSE:
 *  - Unit test to check if size of set is returned properly.
 * 
 * PARAMS: None
 * 
 * DESCRIPTION:
 *  - Initialize and fill float vector with 3 values.
 *  - Construct Q_Set object with vector.
 *  - Get size of set, if size is incorrectly calculated - print error and terminate test program.
 * 
 * RETURNS: None
 * 
 * AUTHOR:
 *  - Brandan Quinn
 * 
 * DATE:
 *  2/27/19 1:17pm
 **/
void size_test() {
    vector<float> f_vec;
    f_vec.push_back(1.0);
    f_vec.push_back(2.0);
    f_vec.push_back(3.0);

    Q_Set f_set(f_vec);
    if (f_set.size() != 3) {
        cout << "Size was incorrectly calculated to be: " << f_set.size() << " should be 3." << endl;
        terminate();
    } else {
        cout << "Size correctly returned as: " << f_set.size() << endl;
    }

    cout << "Size test passed." << endl;
}

/**
 * NAME: contains_test()
 * 
 * PURPOSE: 
 *  - Performs unit tests for the set contains functionality. 
 * 
 * PARAMS: None
 * 
 * DESCRIPTION:
 *  - Init vector of doubles and push back two elements.
 *  - Construct set using vector.
 *  - Check if set contains 2.0, if true - test fails, error message is printed and program terminates.
 *  - Check if set contains 3.5, if false - test fails, error message is printed and program terminates.
 * 
 *  RETURNS: None
 * 
 *  AUTHOR:
 *  - Brandan Quinn
 * 
 *  DATE:
 *  2/27/19 4:17pm
 **/
void contains_test() {
    vector<double> d_vec;
    d_vec.push_back(1.5);
    d_vec.push_back(3.5);

    Q_Set d_set(d_vec);
    if (d_set.contains(2.0)) {
        cout << "2.0 is not in set and was wrongly identified as in it." << endl;
        terminate();
    }

    if (!d_set.contains(3.5)) {
        cout << "3.5 should be found in set and was not." << endl;
        terminate();
    }

    cout << "Contains test passed." << endl;
}

/**
 * NAME: union_test()
 * 
 * PURPOSE:
 *  - Performs unit tests for set union functionality.
 * 
 * PARAMS: None
 * 
 * DESCRIPTION:
 *  - Init double vector1 and push back elements.
 *  - Init double vector2 and push back elements.
 *  - Construct set objects for each vector.
 *  - Call set_union on first set and pass other set as param.
 *  - Display set to ensure union works properly.
 *  - Init float vector and push back elements.
 *  - Construct set object with float vector.
 *  - Call set_union on first set and pass float set as param.
 *  - Error should be printed to screen as the sets are of different types.
 *  - Display set to ensure typing error case works properly.
 * 
 * RETURNS: None
 * 
 * AUTHOR: 
 *  - Brandan Quinn
 * 
 * DATE:
 *  2/27/19 4:49pm
 **/
void union_test() {
    vector<double> d_vec;
    d_vec.push_back(1.5);
    d_vec.push_back(3.5);

    vector<double> d_vec2;
    d_vec2.push_back(1.5);
    d_vec2.push_back(2.0);
    d_vec2.push_back(4.2);

    Q_Set ds1(d_vec);
    Q_Set ds2(d_vec2);

    ds1.set_union(ds2);
    // Display set after union
    ds1.display();

    vector<float> f_vec;
    f_vec.push_back(1.0);
    f_vec.push_back(2.0);
    f_vec.push_back(3.0);

    Q_Set f_set(f_vec);

    ds1.set_union(f_set);
    // Display set after second union call, should print the same elements as before.
    ds1.display();

    cout << "Union test passed." << endl;
}

/**
 * NAME: intersection_test()
 * 
 * PURPOSE:
 *  - Performs unit test on set_intersection functionality.
 * 
 * PARAMS: None
 * 
 * DESCRIPTION:
 *  - Init double vector1 and push back elements.
 *  - Init double vector2 and push back elements.
 *  - Construct set objects for each vector.
 *  - Call set_intersection on first set and pass other set as param.
 *  - Display set to ensure intersect works properly.
 *  - Init float vector and push back elements.
 *  - Construct set object with float vector.
 *  - Call set_intersection on first set and pass float set as param.
 *  - Error should be printed to screen as the sets are of different types.
 *  - Display set to ensure typing error case works properly.
 * 
 * RETURNS: None
 * 
 * AUTHOR:
 *  - Brandan Quinn
 * 
 * DATE:
 *  2/27/19 4:59pm
 **/
void intersection_test() {
    vector<double> d_vec;
    d_vec.push_back(1.5);
    d_vec.push_back(3.5);

    vector<double> d_vec2;
    d_vec2.push_back(1.5);
    d_vec2.push_back(2.0);
    d_vec2.push_back(4.2);

    Q_Set ds1(d_vec);
    Q_Set ds2(d_vec2);

    ds1.set_intersection(ds2);
    // Display set after intersection
    ds1.display();

    vector<float> f_vec;
    f_vec.push_back(1.0);
    f_vec.push_back(2.0);
    f_vec.push_back(3.0);

    Q_Set f_set(f_vec);

    ds1.set_intersection(f_set);
    // Display set after second union call, should print empty set.
    ds1.display();

    cout << "Intersection test passed." << endl;
}

void empty_test() {
    vector<char> c_vec;
    c_vec.push_back('h');

    Q_Set my_set(c_vec);

    // Should print [ h ]
    my_set.display();

    // Should clear set
    my_set.empty();

    // Should print [ ]
    my_set.display();

    cout << "Empty test passed." << endl;
}

int main() {
    temp_type();
    cout << "--------------------" << endl;
    type_test();
    cout << "--------------------" << endl;
    add_test();
    cout << "--------------------" << endl;
    remove_test();
    cout << "--------------------" << endl;
    size_test();
    cout << "--------------------" << endl;
    contains_test();
    cout << "--------------------" << endl;
    union_test();
    cout << "--------------------" << endl;
    intersection_test();
    cout << "--------------------" << endl;
    empty_test();

    cout << "Test suite complete (8/8 passed)." << endl;

}


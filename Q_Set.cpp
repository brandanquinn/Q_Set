#include "Q_Set.h"

#include <vector>

using namespace std;

vector<int> Q_Set::get_int_vec() {
    vector<int> i_elem;

    for (int i = 0; i < this->elements.size(); i++) {
        i_elem.push_back(stoi(this->elements[i]));
    }

    return i_elem;
}

vector<char> Q_Set::get_char_vec() {
    vector<char> c_elem;

    for (int i = 0; i < this->elements.size(); i++) {
        c_elem.push_back(this->elements[i][0]);
    }

    return c_elem;
}

vector<double> Q_Set::get_double_vec() {
    vector<double> d_elem;

    for (int i = 0; i < this->elements.size(); i++) {
        d_elem.push_back(stod(this->elements[i]));
    }

    return d_elem;
}

vector<float> Q_Set::get_float_vec() {
    vector<float> f_elem;

    for (int i = 0; i < this->elements.size(); i++) {
        f_elem.push_back(stof(this->elements[i]));        
    }

    return f_elem;
}

vector<long> Q_Set::get_long_vec() {
    vector<long> l_elem;
    for (int i = 0; i < this->elements.size(); i++) {
        l_elem.push_back(stol(this->elements[i]));
    }

    return l_elem;
}

vector<long long> Q_Set::get_long_long_vec() {
    vector<long long> ll_elem;
    for (int i = 0; i < this->elements.size(); i++) {
        ll_elem.push_back(stoll(this->elements[i]));
    }

    return ll_elem;
}

vector<short> Q_Set::get_short_vec() {
    vector<short> s_elem;
    for (int i = 0; i < this->elements.size(); i++) {
        int x = stoi(this->elements[i]);
        if (x < SHRT_MIN || x > SHRT_MAX) {
            throw range_error("Value out of range of short type.");
        } else {
            s_elem.push_back(stoi(this->elements[i]));
        }
    
    }

    return s_elem;
}

string Q_Set::get_type_of() {
   return this->type_of;
}

int Q_Set::size() {
    return this->elements.size();
}

void Q_Set::set_union(Q_Set s) {
    // Make sure types are the same, else return first set.
    if (this->get_type_of() != s.get_type_of()) {
        cout << "Sets are of different types, cannot compute union." << endl;
    } else {
        // Unique combine sets 1 and 2
        for (int i = 0; i < s.elements.size(); i++) {
            bool element_found = false;
            for (int j = 0; j < this->elements.size(); j++) {
                if (s.elements[i] == this->elements[j])
                    element_found = true;
            }
            if (!element_found)
                this->elements.push_back(s.elements[i]);
        }
    }
}

void Q_Set::set_intersection(Q_Set s) {
    // Make sure types are the same, else return first set.
    if (this->get_type_of() != s.get_type_of()) {
        cout << "Sets are of different types, cannot compute intersection." << endl;
        this->elements.clear();
    } else {
        // Combine same elements of sets 1 and 2
        vector<string> intersection;
        for (int i = 0; i < this->elements.size(); i++) {
            for (int j = 0; j < s.elements.size(); j++) {
                if (this->elements[i] == s.elements[j]) {
                    intersection.push_back(this->elements[i]);
                    break;
                }
            }
        }

        this->elements = intersection;
    }
}

void Q_Set::empty() {
    this->elements.clear();
}

void Q_Set::display() {
    cout << "[ ";
    for (int i = 0; i < this->elements.size(); i++) {
        cout << this->elements[i] << " ";
    }
    cout << "]" << endl;
}
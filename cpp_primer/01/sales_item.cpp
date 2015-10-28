#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class Sales_item {
public:
    friend istream & operator>> (istream &, Sales_item&);
    friend ostream & operator<< (ostream &, const Sales_item&);
    string get_isbn() const { return isbn; }
    Sales_item &operator+=(const Sales_item &rhs) {
        this->num_sold += rhs.num_sold;
        return *this;
    }
    double avg_price() const {
        if (num_sold) {
            return earn / num_sold;
        } else {
            return 0.;
        }
    }
private:
    string isbn;
    unsigned num_sold = 0;
    double earn = 0.0;
};

istream & operator>> (istream &is, Sales_item& si) {
    is >> si.isbn >> si.num_sold;
    return is;
}

ostream & operator<< (ostream &os, const Sales_item& si) {
    os << si.isbn << ": " << si.num_sold;
    return os;
}

int main() {
    Sales_item base;
    if (cin >> base) {
        Sales_item next;
        while (cin >> next) {
            if (base.get_isbn() == next.get_isbn()) {
                base += next;
            } else {
                cout << base << endl;
                base = next;
            }
        }
    } else {
        cout << "No data" << endl;
        return 1;
    }
}


#include "str_blob.hpp"

using namespace std;

str_blob_t::str_blob_t() : data(make_shared<vector<string>>()) {
}

str_blob_t::str_blob_t(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {
}

void str_blob_t::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

string &str_blob_t::front() {
    check(0, "front on empty str_blob_t");
    return data->front();
}

string &str_blob_t::back() {
    check(0, "back on empty str_blob_t");
    return data->back();
}

void str_blob_t::pop_back() {
    check(0, "pop_back on empty str_blob_t");
    data->pop_back();
}

int main() {
    return 0;
}

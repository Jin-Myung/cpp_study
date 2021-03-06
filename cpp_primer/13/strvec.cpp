#include <string>
#include <memory>

class str_vec_t {
public:
    str_vec_t() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    str_vec_t(const str_vec_t &s) {
        auto newdata = alloc_n_copy(s.begin(), s.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    }
    str_vec_t &operator=(const str_vec_t &rhs) {
        auto data = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }
    ~str_vec_t() {
        free();
    }
    
    void push_back(const std::string &s) {
        chk_n_alloc();
        alloc.construct(first_free++, s);
    }
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
private:
    std::allocator<std::string> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string *b, const std::string *e) {
        auto data = alloc.allocate(e - b);
        return {data, uninitialized_copy(b, e, data)};
    }
    void free() {
        if (elements) {
            for (auto p = first_free; p != elements;) {
                alloc.destroy(--p);
            }
            alloc.deallocate(elements, cap-elements);
        }
    }
    void reallocate() {
        auto newcapacity = size() ? 2 * size() : 1;
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        first_free = dest;
        cap = elements+newcapacity;
    }
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

int main() {
    return 0;
}

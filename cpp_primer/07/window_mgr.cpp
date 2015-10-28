#include <vector>
#include <iostream>

using namespace std;

class Screen {
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { }
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline
Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline
char Screen::get(pos ht, pos wd) const {
    return contents[ht*width + wd];
}

class Window_mgr {
public:
    int &operator[](const size_t idx) {
        return arr[idx];
    }
private:
    vector<int> arr{1, 2, 3};
};

int main() {
    Window_mgr wm;
    cout << wm[0] << endl;
    return 0;
}


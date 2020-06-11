#ifndef ERRORS_H
#define ERRORS_H
#include <exception>
#include <string>
#include <ostream>

struct base_error : public std::exception {
    std::string _message;

    explicit base_error(std::string m)
    : _message(std::move(m)) {
    }

    const char *what() const noexcept override {
        return _message.c_str();
    }

    virtual void print(std::ostream &os) const {
        os << what() << std::endl;
    }
    // overloading the << operator for printing the object of struct base_error
    friend std::ostream &operator<<(std::ostream &os, const base_error &el) {
        el.print(os);
        return os;
    }
};

#endif //ERRORS_H 

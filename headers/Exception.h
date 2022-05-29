#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H
#include <exception>
#include <stdexcept>

class AppError : public std::runtime_error {
public:
    explicit AppError(const std::string &arg) : runtime_error(arg) {}
};

class FileError : public AppError {
public:
    explicit FileError(const std::string &arg = "") : AppError(arg) {}
};

class PlayerOutOfBounds : public AppError {
public:
    explicit PlayerOutOfBounds(const std::string &arg = "") : AppError(arg) {}
};

#endif //OOP_EXCEPTION_H

//
// Created by user on 16.05.2022.
//

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
    FileError(const std::string &arg = "") : AppError(arg) {}
};

#endif //OOP_EXCEPTION_H

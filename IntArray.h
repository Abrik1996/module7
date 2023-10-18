#pragma once
#include <iostream>
#include <limits.h>
#include <exception>
class IntArray
{
public:
    ~IntArray()
    {
        std::cout << "Class deleted" << std::endl;
    }
    IntArray(int size);
    void resize(int size);
    void show();
    void show_index(int index);
    IntArray(IntArray* B);
    void erase();
    int get_length() { return m_length; }
    int* get_date() { return m_data; }
    void add_toend(int number);
    void add_tostart(int number);
    void del_index(int index);
private:
    int m_length;
    int* m_data;
};

class BadLength : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad length for array!";
    }
};
class BadRange : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad range!";
    }
};

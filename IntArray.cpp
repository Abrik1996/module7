#include "IntArray.h"
IntArray::IntArray(int size)
{
    m_length = size;
    try
    {
        int* tmp = new int[m_length];
        for (int i = 0; i < m_length; i++)
            tmp[i] = 0;
        m_data = tmp;
    }
    catch (std::bad_alloc& ba)
    {
        delete[] m_data;
        std::cout << "bad_alloc caught! Can't create such big array " << std::endl;
        std::cout << ba.what() << std::endl;
    }
}
void IntArray::resize(int size)
{
    if (size == m_length) return;
    if (size > m_length)
    {
        try
        {
            int* tmp = new int[size];
            for (int i = 0; i < m_length; i++)
                tmp[i] = m_data[i];
            for (int i = m_length; i < size; i++)
                tmp[i] = 0;
            delete[] m_data;
            m_data = tmp;
            m_length = size;
        }
        catch (std::bad_alloc& ba)
        {
            std::cout << "bad_alloc caught! Can't create such big array " << std::endl;
            std::cout << ba.what() << std::endl;
        }
    }
    else
    {
        try
        {
            int* tmp = new int[size];
            for (int i = 0; i < size; i++)
                tmp[i] = m_data[i];
            delete[] m_data;
            m_data = tmp;
            m_length = size;
        }
        catch (std::bad_alloc& ba)
        {
            std::cout << "bad_alloc caught! Can't create array " << std::endl;
            std::cout << ba.what() << std::endl;
        }
    }
}
void IntArray::show()
{
    std::cout << "Array : ";
    for (int i = 0; i < m_length; i++)
        std::cout << m_data[i] << " ";
    std::cout << std::endl;
    return;
}
void IntArray::show_index(int index)
{
    index--;
    try
    {
        if (index >= m_length)
            throw BadRange();
        if (index < 0)
            throw BadRange();
        std::cout << "element " << (index + 1) << " = " << m_data[index] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
IntArray::IntArray(IntArray* B)
{
    try
    {
        this->m_length = B->m_length;
        int* m_data = new int[m_length];
        for (int i = 0; i < m_length - 1; i++)
            m_data[i] = B->get_date()[i];
    }
    catch (std::bad_alloc& ba)
    {
        std::cout << "bad_alloc caught! Can't create array " << std::endl;
        std::cout << ba.what() << std::endl;
    }
}



void IntArray::erase()
{
    try
    {
        if (!m_length)
            throw BadLength();
        delete[] m_data;
        m_length = 0;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
void IntArray::add_toend(int number)
{
    try
    {
        m_length++;
        if (m_length < 0)
        {
            m_length--;
            throw BadLength();
        }
        int* tmp = new int[m_length];
        tmp[m_length - 1] = number;
        for (int i = 0; i < m_length - 1; i++)
            tmp[i] = m_data[i];
        delete[] m_data;
        m_data = tmp;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
void IntArray::add_tostart(int number)
{
    try
    {
        m_length++;
        if (m_length < 0)
        {
            m_length--;
            throw BadLength();
        }
        int* tmp = new int[m_length];
        for (int i = m_length - 1; i > 0; i--)
            tmp[i] = m_data[i - 1];
        tmp[0] = number;
        delete[] m_data;
        m_data = tmp;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
void IntArray::del_index(int index)
{
    try
    {
        std::cout << "delete element " << index << std::endl;
        if (index > m_length)
            throw BadRange();
        if (index < 0)
            throw BadRange();
        int* tmp = new int[m_length - 1];
        for (int i = 0; i < index - 1; i++)
            tmp[i] = m_data[i];
        for (int i = index - 1; i < m_length - 1; i++)
            tmp[i] = m_data[i + 1];
        delete[] m_data;
        m_length--;
        m_data = tmp;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
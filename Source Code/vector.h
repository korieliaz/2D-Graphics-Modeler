/*!
 * \class   vector
 * \brief   The class managing a custom vector.
*/

#ifndef VECTOR_H_
#define VECTOR_H_

//! Allows use of std::copy
#include <algorithm>
using std::copy;

/*! \namespace myVector
 * \brief Wraps the entire custom vector in a custom namespace so as to differentiate it from the std::vector */
namespace myVector
{

/*! \brief This is a vector much like the stl vector container.
 * \brief NOTE: elem[n] is a vector component n for all n >= 0 AND n < size_v.
 * \brief size_v = the number of items stored in the vector.
 * \brief space = the available storage capacity of the vector where size_v <= space.
 * \brief if size_v < space there is space for (space - size_v) items after elem[size_v - 1].
 */
template <class T>
class vector
{
    int size_v;   /*!< the size of the vector */
    T *elem;      /*!< the pointer to the elements (or 0) */
    int space;    /*!< the number of elements plus the number of free slots */

public:
    //! Default constructor
    vector() : size_v{0}, elem{nullptr}, space{0} {}

    //! Alternate constructor
    /*! Elements are initialized */
    explicit vector(int s) : size_v{s}, elem{new T[s]}, space{s}
    {
        for (int i = 0; i < size_v; ++i)
            elem[i] = 0;
    }

    //! Copy constructor
    /*! Copies elements using the std::copy() algorithm
     * \param src the vector to be copied into the invoking vector, passed by constant reference */
    vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space}
    {
        copy(src.elem, src.elem + size_v, elem);
    }

    //! Overloaded copy assignment operator
    /*! \param src the vector to be assigned into the invoking vector, passed by constant reference */
    vector &operator=(const vector &src)
    {
        /*! \brief Allocates new space */
        T *p = new T[src.size_v];

        /*! \brief Copies elements using the std::copy() algorithm */
        copy(src.elem, src.elem + src.size_v, p);

        /*! \brief Deallocates old space */
        delete[] elem;

        /*! \brief Resets elem */
        elem = p;
        size_v = src.size_v;

        /*! \brief Returns a self-reference */
        return *this;
    }

    //! Destructor
    ~vector() {
        /*! \brief Frees dynamic data allocation */
        delete[] elem;
    }

    //! Overloaded subscript operator
    T &operator[](int n) {
        /*! \brief Access: return reference */
        return elem[n];
    }

    //! Overloaded constant subscript operator
    const T &operator[](int n) const {
        return elem[n];
    }

    //! Returns the size of the vector
    int size() const {
        return size_v;
    }

    //! Returns the capacity of the vector
    int capacity() const {
        return space;
    }

    //! Resizes the vector
    /*! \brief Makes the vector have an amount of elements equal to the passed in value.
     * \brief Initializes each new element with the default value 0.
     * \param newsize the amount of elements the resized vector should have
     */
    void resize(int newsize)
    {
        reserve(newsize);

        /*! \brief Initializes new elements */
        for (int i = size_v; i < newsize; ++i)
            elem[i] = 0;

        size_v = newsize;
    }

    //! Adds a new element to the vector
    /*! Increases the vector size by one; initializes the new element with the passed in element
     * \param d the element to be added to the vector
     */
    void push_back(T d)
    {
        /*! \brief Starts with space for 8 elements.
         * \brief If this is not enough space, gets more space.
         */
        if (space == 0)
            reserve(8);
        else if (size_v == space)
            reserve(2 * space);

        /*! \brief Adds the passed in value to the vector after resizing it. */
        elem[size_v] = d;

        /*! \brief Increases the size (size_v is the number of elements) */
        ++size_v;
    }

    //! Reserves more space on the heap for the vector
    /*! Never decreases allocation, just allocates new space
     * \param newalloc the amount of space to be reserved on the heap */
    void reserve(int newalloc)
    {
        T *p = new T[newalloc];

        /*! \brief Copies old elements */
        copy(elem, elem + size_v, p);

        /*! \brief Deallocates old space */
        delete[] elem;

        elem = p;
    }

    using iterator = T *;
    using const_iterator = const T *;

    //! Defines the iterator begin - points to the first element
    /*! \brief Read/Write */
    iterator begin() // points to first element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    //! Defines the constant iterator begin - points to the first element
    /*! \brief Read Only */
    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    //! Defines the iterator end - points to one beyond the last element
    /*! \brief Read/Write */
    iterator end()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    //! Defines the constant iterator end - points to one beyond the last element
    /*! \brief Read Only */
    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    //! Inserts a new element before the location of the passed in iterator
    /*! \param p the iterator location
     * \param val the value to be inserted at p
     */
    iterator insert(iterator p, const T &val)
    {
        /*! \brief Ensures there is space to add
         * \brief If there is not enough space, resizes the vector
         */
        if(space <= size_v)
        {
            resize(size_v + 1);
        }

        T tempAr[space];
        int count = 0;

        /*! \brief For loop to get the values from the right side of p (including p) */
        for(int i = p; i < size_v; ++i)
        {
            tempAr[count] = elem[i];
            count++;
        }

        /*! \brief Inserts new value into p */
        elem[p] = val;

        count = 0;

        /*! \brief For loop adds the old elements after p */
        for(int i = p + 1; i < size_v; ++i)
        {
            elem[i] = tempAr[count];
            count++;
        }

        return p;
    }

    //! Erases a value at a specified location.
    /*! \param p the iterator location */
    iterator erase(iterator p)
    {
        if (p == end())
            return p;

        /*! \brief Copies the element one position to the left for the entire vector*/
        for (iterator pos = p + 1; pos != end(); ++pos)
            *(pos - 1) = *pos;

        /*! \brief Decrements the size of the vector */
        --size_v;

        return p;
    }
};
}

#endif /* VECTOR_H_ */

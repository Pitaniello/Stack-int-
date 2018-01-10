#include <cassert>
#include <string>

#include "stack.h"


#ifdef _DEBUG
const int S_EMPTY_TOKEN = 0xFFFFFFFF;
#endif


Stack_Int::Stack_Int() : _m_p_stackArray( nullptr ), 
                            _m_topPos( static_cast< size_t >( -1 ) ), 
                            _m_size( static_cast< size_t >( -1 ) )
{
    // nothing to do
}

Stack_Int::Stack_Int( const Stack_Int &other )
{
    // deep copy
    this->_m_topPos = other._m_topPos;
    this->_m_size = other._m_size;
}


Stack_Int & Stack_Int::operator=( const Stack_Int & rhs )
{
    // deep copy
    this->_m_topPos = rhs._m_topPos;
    this->_m_size = rhs._m_size;

    return *this;
}


Stack_Int::~Stack_Int()
{
    _free_stack( &_m_p_stackArray );
}


//  bool empty() const;
// Returns whether the stack is empty: i.e. whether its size is zero.
// This member function effectively calls member empty of the underlying container object.
// Complexity - Constant(calling empty on the underlying container).
// Exception safety - Provides the same level of guarantees as the operation performed on the container(no - throw guarantee for standard container types).
bool Stack_Int::empty()
{
    return !static_cast< bool >( _m_size );
}


//  size_type size() const;
// Returns the number of elements in the stack.
// This member function effectively calls member size of the underlying container object.
// Complexity - Constant(calling size on the underlying container).
// Exception safety - Provides the same level of guarantees as the operation performed on the container(no - throw guarantee for standard container types).
size_t Stack_Int::size()
{
    return _m_size;
}


//        value_type& top();
//  const value_type& top() const;
// Returns a reference to the top element in the stack. 
// Since stacks are last - in first - out containers, the top element is the last element inserted into the stack.
// This member function effectively calls member back of the underlying container object.
// Complexity - Constant(calling back on the underlying container).
// Exception safety - Provides the same level of guarantees as the operation performed on the container(no - throw guarantee for standard non - empty containers).
int Stack_Int::top()
{
    return 0;
}


//  void push (const value_type& val);
// Inserts a new element at the top of the stack, above its current top element. The content of this new element is initialized to a copy of val.
// This member function effectively calls the member function push_back of the underlying container object.
// Complexity - One call to push_back on the underlying container.
// Exception safety - Provides the same level of guarantees as the operation performed on the underlying container object.
void Stack_Int::push( int value )
{
    // If _m_size <= _m_topPos, grow the stack. 
    if ( _m_size <= _m_topPos )
    {
        int *newStack = nullptr;
        int newSize = _m_size * 2;

        _alloc_stack( &newStack, newSize );

        _m_size = newSize;
    }

    // Set the stack at _m_topPos position equal to the given value .
    _m_p_stackArray[_m_topPos] = value;

    // advance top pointer
    ++_m_topPos;
}


//  template <class... Args> void emplace (Args&&... args);
// Adds a new element at the top of the stack, above its current top element. This new element is constructed in place passing args as the arguments for its constructor.
// This member function effectively calls the member function emplace_back of the underlying container, forwarding args.
// Complexity - One call to emplace_back on the underlying container.
// Exception safety - Provides the same level of guarantees as the operation performed on the underlying container object.
void Stack_Int::emplace()
{

}


//  void pop();
// Removes the element on top of the stack, effectively reducing its size by one.
// The element removed is the latest element inserted into the stack, whose value can be retrieved by calling member stack::top.
// This calls the removed element's destructor.
// This member function effectively calls the member function pop_back of the underlying container object.
// Complexity - Constant(calling pop_back on the underlying container).
// Exception safety - Provides the same level of guarantees as the operation performed on the underlying container object.
int Stack_Int::pop()
{
    return 0;
}


//  void swap (stack& x) noexcept(/*see below*/);
// Exchanges the contents of the container adaptor (*this) by those of x.
// This member function calls the non - member function swap(unqualified) to swap the underlying containers.
// The noexcept specifier matches the swap operation on the underlying container.
// Complexity - Constant.
// Exception safety - Provides the same level of guarantees as the operation performed on the underlying container objects.
void Stack_Int::swap()
{
}


void Stack_Int::_alloc_stack( int **stack_chunk, size_t size )
{
    assert( stack_chunk && 
                "Stack_Int::_alloc_stack( int **, size_t ) was given nullptr as an argument." );

    assert( !*stack_chunk &&
                "Stack_Int::_alloc_stack( int **, size_t ) was given a pointer to already allocated memory." );
    
    // TODO: What if new fails?
    *stack_chunk = new int[size];

#ifdef _DEBUG
    std::memset( *stack_chunk, S_EMPTY_TOKEN, size );
#endif
}


void Stack_Int::_free_stack( int **stack_chunk )
{
    assert( stack_chunk && 
            "Stack_Int::_alloc_stack( int **, size_t ) was given nullptr as an argument." );

    if ( *stack_chunk )
    {
        delete [] *stack_chunk;
        *stack_chunk = nullptr;
    }
}

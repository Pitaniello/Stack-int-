#pragma once

class Stack_Int
{
	public:
        Stack_Int();
        Stack_Int( const Stack_Int & );
        Stack_Int & operator=( const Stack_Int & );

        ~Stack_Int();

        bool empty();

        size_t size();
        int top();

        void push( int );
        void emplace();
        int pop();
        void swap();

	private:
        void _alloc_stack( int **, size_t );
        void _free_stack( int ** );

        int * _m_p_stackArray;
        size_t _m_topPos;
        size_t _m_size;
};

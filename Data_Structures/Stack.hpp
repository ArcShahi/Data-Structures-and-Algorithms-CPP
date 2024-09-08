#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include <iostream>
#include <iomanip>

///////////////////////////////////////////////////////////
///   STACK ( USING DYNAMIC ARRAY )     	       ///
/////////////////////////////////////////////////////////

namespace xe
{


	template <typename type>
	class Stack
	{

	public:

		Stack(size_t s)
			:stack{ std::make_unique<type[]>(s) }, size{ s },
			index{ -1 }
		{}


		void push(type value);

		void pop();

		constexpr type top()const;

		constexpr type bottom()const;

		constexpr bool isFull()const;

		constexpr bool isEmpty() const;

		size_t ssize() const;

		constexpr type* rsp()const;

		constexpr type* rbp() const;

		void display()const;






	private:

		std::unique_ptr<type[]> stack;
		size_t size;
		int index{};


	};


/////////////////////////////////////////////////////////////////////////////
// CLASS TEMPLATE DEFINITION 						///
//////////////////////////////////////////////////////////////////////////

	template<typename type>
	void Stack<type>::push(type value)
	{
		if (isFull())
		{

			std::cerr << "Stack OverFlow\n";
			return;
		}
		stack[++index] = value;
		++size;
	}

	template<typename type>
	void Stack<type>::pop()
	{
		if (isEmpty())
		{
			std::cerr << "Stack Underflow\n";
			return;
		}
		// Remove Last Index ( Automatically Gets Freed )
		--index;
		--size;
	}

	template<typename type>
	constexpr type Stack<type>::top() const
	{
		return stack[index];
	}

	template<typename type>
	constexpr type Stack<type>::bottom() const
	{
		return stack[0];
	}

	template<typename type>
	constexpr bool Stack<type>::isFull() const
	{
		return index == size - 1;
	}

	template<typename type>
	constexpr bool Stack<type>::isEmpty() const
	{
		return index + 1 >= size;
	}

	template<typename type>
	size_t Stack<type>::ssize() const
	{
		return size;
	}

	template<typename type>
	constexpr type* Stack<type>::rsp() const
	{
		return &stack[index];
	}

	template<typename type>
	constexpr type* Stack<type>::rbp() const
	{
		return &stack[0];
	}



	template<typename Type>
	void Stack<Type>::display() const
	{

		if (isEmpty())
		{
			std::cerr << "EMPTY STACK\n";
		}

		std::cout << "Stack ( Bottom to Top):\n\n";
		for (int i = 0; i <= index; i++)
		{
			std::cout << "[" << std::setw(8) << stack[i] << " ] ";
			if (i == index)
			{
				std::cout << "<-- RSP: 0x" <<
					reinterpret_cast<uintptr_t>(&stack[index]) << std::dec << "\n";;
			}
			std::cout << "\n";
		}



	}




}


#endif // !STACK_HPP


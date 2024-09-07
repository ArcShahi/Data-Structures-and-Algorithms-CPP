#ifndef DOUBLE_LINKED_LIST_HPP
#define DOULBE_LINKED_LIST_HPP


#include <memory>


///////////////////////////////////////////////////////////////////////////////////////////////////
///			DOUBLE LINKED LIST													///
/////////////////////////////////////////////////////////////////////////////////////////////////

template <typename type>
class List
{
public:
	List() {}


	bool isEmpty() const;

	void push_back(type value);

	void push_front(type value);

	void pop_back();

	void display()const;

private:
	struct Node
	{
		explicit Node(type value)
			: data{ value }, next{ nullptr }, prev{ nullptr }
		{}

		type data{};
		std::shared_ptr<Node> next{};
		std::shared_ptr<Node> prev{};

	};

private:

	// Initialize Head & Tail with nullptr

	std::shared_ptr<Node> head{};
	std::shared_ptr<Node> tail{};

	size_t size{};

};

#endif // !DOUBLE_LINKED_LIST_HPP



///////////////////////////////////////////////////////////////////////////////////////////////////
///					TEMPLATE DEFINITION											///
/////////////////////////////////////////////////////////////////////////////////////////////////


template<typename type>
bool List<type>::isEmpty() const
{
	return head == nullptr;
}

template<typename type>
void List<type>::push_back(type value)
{
	auto newNode = std::make_shared<Node>(value);
	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	++size;
}

template<typename type>
void List<type>::push_front(type value)
{
	auto newNode = std::make_shared<Node>(value);
	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	++size;
}
template<typename type>
void List<type>::pop_back()
{
	if (isEmpty())
	{
		std::cerr << "ERROR: Attempt to call 'pop_back()' on empty list\n";
		return;
	}
	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		tail = tail->prev;
		tail->next = nullptr;
	}
	--size;
}

template<typename type>
void List<type>::display() const
{

	if (isEmpty())
	{
		std::cout << "EMPTY LIST\n";
		return;
	}
	for (auto itr = head; itr != nullptr; itr = itr->next)
	{
		std::cout << '-' << itr->data;
	}
	std::cout << "-\n";
}







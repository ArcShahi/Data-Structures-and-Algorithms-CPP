#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>
#include <stdexcept>


///////////////////////////////////////////////////////////////////////////////////////////////////
///					SINGLY LINKED LIST ( FORWARD LIST )							///
////////////////////////////////////////////////////////////////////////////////////////////////


template<typename type>
class Linked_List
{
public:
	Linked_List() {}

	bool isEmpty() const;


	void push_back(type value);

	void push_front(type value);

	void pop_back();

	void pop_front();

	void display() const;

	size_t ssize();

	type back()const;

	type front()const;

	void clear();

	// void erase(type value );

	bool search(const type value)const;

	void replace(const type value, const type newValue);



private:

	struct  Node
	{
		explicit Node(type value) :data{ value }, next{ nullptr } {}
		type data{};
		std::shared_ptr<Node> next{};
	};

private:

	// Initalizes both Head & tail with nullptr.
	std::shared_ptr<Node> head{};
	std::shared_ptr<Node> tail{};

	size_t size{};
};





///////////////////////////////////////////////////////////////////////////////////////////////////
///						TEMPLATE DEFINITION										///
/////////////////////////////////////////////////////////////////////////////////////////////////



template<typename type>
bool Linked_List<type>::isEmpty() const
{
	return head == nullptr;
}

template<typename type>
void Linked_List<type>::push_back(type value)
{
	auto newNode = std::make_shared<Node>(value);
	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	++size;
}

template<typename type>
void Linked_List<type>::push_front(type value)
{
	auto newNode = std::make_shared<Node>(value);

	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		// newNode should point to Head ( First Element in List )
		newNode->next = head;
		// Set Head to newNode ( Now the First Element in List)
		head = newNode;
	}
	++size;
}

template<typename type>
void Linked_List<type>::pop_back()
{
	if (isEmpty())
	{
		throw std::out_of_range("ERROR: Attempt to call 'pop_back() on empty list");
	}
	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		auto current = head;
		// Traverse to Second Last Node
		while (current->next != tail) {
			current = current->next;
		}
		// Remove current-> next ( last element )
		current->next = nullptr;

		// Set Pointer Tail to Current ( Second last element )
		tail = current;
	}
	--size;
}

template<typename type>
void Linked_List<type>::pop_front()
{
	if (isEmpty())
	{
		throw std::out_of_range("ERROR: Attempt to call 'pop_front() on empty list");
	}

	// Set Head Pointer to Point at Second Node
	head = head->next;



	if (head == nullptr)
	{
		tail = nullptr;
	}

	--size;
}

template<typename type>
void Linked_List<type>::display() const
{
	if (isEmpty())
	{
		std::cout << "EMPTY LIST\n";
		return;
	}
	for (auto itr = head; itr != nullptr; itr = itr->next)
	{
		std::cout << itr->data << ' ';
	}
	std::cout << '\n';
}

template<typename type>
size_t Linked_List<type>::ssize()
{
	return size;
}

template<typename type>
type Linked_List<type>::back() const
{
	if (isEmpty())
	{
		throw std::out_of_range("ERROR: Attempt to access 'back()' on empty List\n");

	}
	return tail->data;
}

template<typename type>
type Linked_List<type>::front() const
{
	if (isEmpty())
	{
		throw std::out_of_range("ERROR: Attempt to access 'front()' on empty List\n");
	}
	return head->data;
}

template<typename type>
void Linked_List<type>::clear()
{
	// set Head and Tail to nullptr and reset size
	head = tail = nullptr;
	size = 0;
}

// Checks Wheter an Value exists in List
template<typename type>
bool Linked_List<type>::search(const type value)const
{
	if (isEmpty())
	{
		throw std::out_of_range("ERROR: Attemp to call 'search()' on empty List");
	}

	for (auto itr = head; itr != nullptr; itr = itr->next)
	{
		if (itr->data == value)
		{
			return true;
		}
	}
	return false;
}

template<typename type>
void Linked_List<type>::replace(const type value, const type newValue)
{
	if (isEmpty())
	{
		throw std::out_of_range("ERROR: Attemp to call 'replace()' on empty List");
	}

	for (auto itr = head; itr != nullptr; itr = itr->next)
	{
		if (itr->data == value)
		{
			itr->data = newValue;
			break;
		}
	}
}






#endif // !LINKED_LIST_HPP



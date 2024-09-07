#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>



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

	type& back()const;

	type& front()const;

	void clear();

	void yeet(type value);

	void reverse();

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
		std::cerr << "ERROR: Attempt to call 'pop_back() on empty list\n";
		return;
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
		std::cerr << "ERROR: Attempt to call 'pop_front() on empty list\n";
		return;
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
		std::cout << itr->data << "->";
	}
	std::cout << '\n';
}

template<typename type>
size_t Linked_List<type>::ssize()
{
	return size;
}

template<typename type>
type& Linked_List<type>::back() const
{
	return tail->data;
}

// Invokes UB when called on Empty list
template<typename type>
type& Linked_List<type>::front() const
{
	return head->data;
}

// Invokes UB when called on Empty list
template<typename type>
void Linked_List<type>::clear()
{
	// set Head and Tail to nullptr and reset size
	head = tail = nullptr;
	size = 0;
}

// Removes the First occurence of Value
template<typename type>
void Linked_List<type>::yeet(type value)
{
	if (isEmpty())
	{
		std::cerr << "LIST IS EMPTY\n";
		return;

	}

	// If  the value is in the head node
	if (value == head->data)
	{
		pop_front();
		return;
	}

	// If the value is in the tail node
	if (value == tail->data)
	{
		pop_back(); // Use the existing pop_back() method
		return;
	}



	auto itr = head;

	// Find the the Previous Node of the Element to Remove ( Making sure it's Not null )
	while (itr->next != nullptr && itr->next->data != value)
	{
		itr = itr->next;
	}
	// Now, itr->next points to the node that needs to be removed
	if (itr->next == nullptr)
	{
		std::cerr << value << " Not Found in List\n";
		return;
	}
	// Remove the node by linking to the next one
	itr->next = itr->next->next;


	--size;
}


// Using Two-Pointer Approach Time O(N) , Space O(1)
template<typename type>
void Linked_List<type>::reverse()
{

	std::shared_ptr<Node> pvs = nullptr;

	auto itr{ head };

	while (itr != nullptr)
	{
		auto temp = itr->next;
		itr->next = pvs;
		pvs = itr;
		itr = temp;

	}
	head = pvs;

}

// Checks Whether an Value exists in List
template<typename type>
bool Linked_List<type>::search(const type value)const
{
	if (isEmpty())
	{

		return false;
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
		std::cout << "ERROR: Attemp to call 'replace()' on empty List\n";
		return;
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



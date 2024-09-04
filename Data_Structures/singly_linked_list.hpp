#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>
#include <stdexcept>

template<typename type>
class Linked_List
{
public:
	Linked_List() {}

	bool isEmpty()const
	{
		return head == nullptr;
	}

	void push_back(type value)
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

	void push_front(type value)
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
	void display() const
	{
		if (isEmpty())
		{
			std::cout << "EMPTY LIST\n";
			return;
		}
		for (auto current = head; current != nullptr; current = current->next)
		{
			std::cout << current->data << ' ';
		}
		std::cout << '\n';
	}

	size_t ssize()
	{
		return size;
	}

	const type back()const
	{
		if (isEmpty())
		{
			throw std::out_of_range("ERROR: Attempt to access 'back()' on empty List\n");

		}
		return tail->data;


	}

	const type front()const
	{

		if (isEmpty())
		{
			throw std::out_of_range("ERROR: Attempt to access 'back()' on empty List\n");
		}
		return head->data;

	}

	void clear()
	{
		// set Head and Tail to nullptr and reset size
		head = tail = nullptr;
		size = 0;
	}
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
#endif // !LINKED_LIST_HPP


#include"ReverseLinkedListRecursive.cpp"

template<typename T>
void set_a_next_b_advance_a(shared_ptr<Node<T>> & a, shared_ptr<Node<T>> & b)
{
	if (a && b)
	{
		shared_ptr<Node<T>> temp = a->next;
		a->next = b;
		a = temp;
	
	}

}

template<typename T>
void zipList(const shared_ptr<Node<T>> & root)
{
	//find the middle of list
	shared_ptr<Node<T>> slow = root, fast = root;

	do {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			cout << "Cycle detected" << endl;
			return;
		}

	} while (!fast || !fast->next);
		if (!slow)
		{
			cout << "Only 1 element" << endl;
			return;
		}
		shared_ptr<Node<T>> halfList = slow->next , cur = root;
		slow->next = nullptr;
	//slow is at mid point, reverse the nexthalf
		shared_ptr<Node<T>> reverseList = reverse(halfList);
		while (cur &&  reverseList)
		{
			set_a_next_b_advance_a(cur, reverseList);
			if(reverseList)
				set_a_next_b_advance_a(reverseList, cur);
		}




}


int main()
{

	{
		shared_ptr<Node<int>> root = make_shared<Node<int>>(1);
		root->next = make_shared<Node<int>>(2);
		root->next->next = make_shared<Node<int>>(3);
		root->next->next->next = make_shared<Node<int>>(4);
		root->next->next->next->next = make_shared<Node<int>>(5);
		root->next->next->next->next->next = make_shared<Node<int>>(6);
		root->next->next->next->next->next->next = make_shared<Node<int>>(7);
		root->next->next->next->next->next->next->next = make_shared<Node<int>>(8);
		print(root);
		zipList(root);
		print(root);
		


	}
	_CrtDumpMemoryLeaks();
	return 0;
}
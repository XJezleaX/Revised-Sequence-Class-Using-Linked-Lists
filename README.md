# Revised-Sequence-Class-Using-Linked-Lists

Your sequence class for this assignment will differ from the your previous sequence in the following ways:

The sequence’s items are now stored on a linked list. The head pointer of the linked list is a private member variable of the sequence class. I suggest that you also have a tail pointer as an additional private member variable of the sequence class. The reason for the tail pointer is explained in Section 5.4 of the textbook.
Because you are dynamically allocation memory within your sequence class, you will need to define a copy constructor, an assignment operator, and a destructor. You need to pay special attention to the value semantics of your new sequence class – you need not only to make a copy of the linked list, but also need to place the node pointers correctly. Please refer to page 260 for more detailed discussions on the value semantics.
Start by declaring the new sequence’s private member variables in sequence3.h. You might try declaring these variables yourself, and then compare your solution with the suggestion in Section 5.4.

Once again, do your work in small pieces. For example, my first version of the sequence had only a constructor, start, insert, advance, and current. My other member functions started out as stubs.

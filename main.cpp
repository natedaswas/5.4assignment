//MAIN STUFF:


#include "header.h"


//node class
node::node(const value_type& init_data,node* init_link)
{
  cout << "Making a new node here. Value: " << init_data << endl;
  data_field = init_data;
  link_field = init_link;
}

void node::set_data(const double& new_data)
{
  data_field = new_data;
}

void node::set_link(node* new_link)
{
  link_field = new_link;
}

double node::data()
{
  return data_field;
}

node* node::link()
{
  return link_field;
}

size_t sequence::list_length()
{
  // Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: The value returned is the number of nodes in the linked list.
// Library facilities used: cstdlib

  node *cursor;
  size_t answer;
  answer = 0;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
  ++answer;
  return answer;

}


//sequence class
sequence::sequence()
{
  //sequence is called, everything initialized to 0 and null
  head_ptr = NULL;
  tail_ptr = NULL;
  current_node_ptr = NULL;
  previous_node_ptr = NULL;
  used = 0;
  current_index = 0;
}

//RESETS THE INDEX TO 0 SO YOU CAN START RETRIEVING THINGS
void sequence::start()
{
  if (!head_ptr)
  {
    cout << "Unable to start, no nodes created. Try insert or attach." << endl;
    return;
  }
  else
  {
  cout << "You are now working with the first element of the sequence." << endl;
  //incorrect pointer syntax?
  current_node_ptr = head_ptr;
  previous_node_ptr = NULL;
	//current_index = 0; Not needed???
	return;
  }
}

//INCREASES THE CURRENT INDEX BY 1!!! WOW!!!
void sequence::advance()
{
  if (!head_ptr)
  {
    cout << "Unable to advance, no nodes created. Try insert or attach." << endl;
    return;
  }
  else if (!current_node_ptr->link())
  {
    cout << "Nope, you've gone far enough." << endl;
    return;
  }
  //if the link function does not return NULL
  //change the previous node pointer so I dont lose it
  else if(current_node_ptr->link())
  {
  current_node_ptr = (current_node_ptr->link());
  previous_node_ptr = (previous_node_ptr->link());
  }
  else
  cout << "You have reached the end of the list" << endl;
	return;
}

//UMM IM GUESS WE INSERT A NEW THING AT THE CURRENT INDEX
void sequence::insert(const double& entry)
{
	//precondition (size < capacity)
  //double insert_value;
  //cout << "Value to be placed in new node: " << endl;
  //cin >> insert_value;

  //if head pointer is null then this is the first thing
  if (!head_ptr)
  {
    node* woohoo = new node(entry/* = value_type()*/,current_node_ptr);
    head_ptr = woohoo;
    tail_ptr = woohoo;
    current_node_ptr = woohoo;
  }

  //if this is true then this is the second thing
  else if (head_ptr == current_node_ptr)
  {
    node* woohoo = new node(entry/* = value_type()*/,current_node_ptr);
    head_ptr = woohoo;
    tail_ptr = current_node_ptr;
    previous_node_ptr = woohoo;
  }

  //and this covers everything else
  else
  {
    node* woohoo = new node(entry/* = value_type()*/,current_node_ptr);
    //need to set previous to this new one
    previous_node_ptr->set_link(woohoo);
    previous_node_ptr = woohoo;

  }

}

//YEAH NO CLUE
void sequence::attach(const double& entry)
{
  if (!head_ptr)
  {
    node* woohoo = new node(entry/* = value_type()*/,current_node_ptr);
    head_ptr = woohoo;
    tail_ptr = woohoo;
    current_node_ptr = woohoo;
  }

  //if this is true then this is the second thing
  //so if the current node pointer is not but its the last
  else if ((current_node_ptr) && (!current_node_ptr->link()))
  {
    node* woohoo = new node(entry/* = value_type()*/,NULL);
    tail_ptr = woohoo;
    current_node_ptr->set_link(woohoo);
  }

  //and this covers everything else
  else
  {
    node* woohoo = new node(entry/* = value_type()*/,current_node_ptr->link());
    current_node_ptr->set_link(woohoo);

  }

}

//MAYBE THIS ONE REMOVES THE CURRENT SOMETHING
void sequence::remove_current()
{
  if (!head_ptr)
  {
    cout << "nothing to remove." << endl;
    return;
  }
  else if ((current_node_ptr) && (!current_node_ptr->link()))
  {
    //set the previous nodes link to NULL
    previous_node_ptr->set_link(NULL);
    //set tail pointer to previous
    tail_ptr = previous_node_ptr;
    //we will need to use this loop to walk through and find the now previous thingy
    //otherwise we will lose it and screw everything up
    node *cursor;
    node *ahead_cursor;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    {
      ahead_cursor = cursor->link();
      if (ahead_cursor->link() = NULL)
      {
        previous_node_ptr = cursor;
        break;
      }
    }

  }
	return;
}

bool sequence::is_item() const
{
        //yeah I don't know
        return (current_node_ptr);
}

double sequence::current() const
{
        return current_node_ptr->data();
}

//THESE METHOD NAMES ARE AWFUL WHO WRITES THIS

//void statistician::next_number(double _next)

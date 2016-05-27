//MAIN STUFF:


#include "header.h"


//node class
node::node(const value_type& init_data = value_type( ),node* init_link = NULL)
{
  data_field = init_data;
  link_field = init_link;
}

void node::set_data(const value_type& new_data)
{
  data_field = new_data;
}

void node::set_link(node* new_link)
{
  link_field = new_link;
}

value_type node::data()
{
  return data_field;
}

node* node::link()
{
  return link_field;
}

size_t node::list_length()
{
  // Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: The value returned is the number of nodes in the linked list.
// Library facilities used: cstdlib

  const node *cursor;
  size_t answer;
  answer = 0;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
  ++answer;
  return answer;

}


//sequence class
sequence::sequence()
{
  used = 0;
  current_index = 0;
}

//RESETS THE INDEX TO 0 SO YOU CAN START RETRIEVING THINGS
void sequence::start()
{
  //incorrect pointer syntax?
  head_ptr = NULL;
  tail_ptr = NULL;
	current_index = 0;
	return;
}

//INCREASES THE CURRENT INDEX BY 1!!! WOW!!!
void sequence::advance()
{
	current_index++;
  cout << "index: " << current_index << endl;
	return;
}

//UMM IM GUESS WE INSERT A NEW THING AT THE CURRENT INDEX
void sequence::insert(const double& entry)
{
  cout << "we totally just got into the insert method" << endl;
	//precondition (size < capacity)
	if (current_index >= used)

  {cout << "looks like current index is at nothing so lets just set that number to the current index" << endl;
	data[current_index] = entry;}
	else
	{
	  for (int i = used; i > current_index; i--)
	  {
	  data[i] = data[i -1];
	  }
	data[current_index] = entry;
	}
	used++;
  cout << "incrementing the used variable to: " << used << endl;
  cout << "And now straight from the array: " << data[current_index] << endl;
}

//YEAH NO CLUE
void sequence::attach(const double& entry)
{
  cout << "woohoo totes the attach function" << endl;
	//precondition (size < capacity)
        if (current_index >= used)
        {
        data[current_index] = entry;
        cout << "Looks like this is the first thing to enter: " << entry << endl;
        }
        else
        {
          for (int i = used; i > (current_index + 1); i--)
          {
          data[i] = data[i -1];
          }
        data[current_index + 1] = entry;
        }
        used++;

        cout << "incrementing the used variable to: " << used << endl;
        cout << "And now straight from the array: " << data[current_index] << endl;
}

//MAYBE THIS ONE REMOVES THE CURRENT SOMETHING
void sequence::remove_current()
{
  if (!is_item())
  return;
  if (used > 0)
  {
    for (int i = current_index; i < used; i++)
    {
      data[i] = data[i + 1];
    }
    used--;
  }

	return;
}

//getter for the size of our sequence
size_t sequence::size() const
{
        return used;
}

bool sequence::is_item() const
{
        //yeah I don't know
        return (current_index < used);
}

double sequence::current() const
{
        return data[current_index];
}

//THESE METHOD NAMES ARE AWFUL WHO WRITES THIS

//void statistician::next_number(double _next)

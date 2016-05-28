//HEADER STUFF

//nathanael meyers
//alan dunn
//swag swag swag swag swag
//3.2 container project thingy

#include <iostream>
#include <cstdlib>  // Provides size_t
using namespace std;

class node
{
public:
  typedef double value_type;
  //this magic constructor below
  //if no args are passed this format sets the values to 0 and NULL respectively
  node(const value_type& init_data = value_type( ),const node* init_link = NULL);
  ~node();
  void set_data(const value_type& new_data);
  void set_link(node* new_link);

  value_type data();
  //this is the pointer to the next thing
  node* link();

  size_t list_length(const node* head_ptr);

private:
  value_type data_field;
  node *link_field;
};

class sequence
{
public:
// TYPEDEFS and MEMBER CONSTANTS
  typedef double value_type;
  typedef size_t size_type;
  static const size_type CAPACITY = 30;
// CONSTRUCTOR
  sequence( );
// MODIFICATION MEMBER FUNCTIONS
//SETTERS
  void start( );
  void advance( );
  void insert(const value_type& entry);
  void attach(const value_type& entry);
  void remove_current( );
// CONSTANT MEMBER FUNCTIONS
//GETTERS
  size_type size( ) const;
  bool is_item( ) const;
  value_type current( ) const;
private:
  node *head_ptr;
  node *tail_ptr;
  node *current_node_ptr;
  node *previous_node_ptr;
  value_type data[CAPACITY];
//used keeps track of how many spaces are currently being used
  size_type used;
  //current_index will increment to be the spot of the last item in sequence
  size_type current_index;
};

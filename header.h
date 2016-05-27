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
private:
  value_type data;
  node *link;
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
//bam heres the array of doubles
//AHHHHHHH
  node *head_ptr;
  node *tail_ptr
  value_type data[CAPACITY];
//used keeps track of how many spaces are currently being used
  size_type used;
  //current_index will increment to be the spot of the last item in sequence
  size_type current_index;
};

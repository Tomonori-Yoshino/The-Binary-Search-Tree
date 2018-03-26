#include "BinarySearchTree.h"

#include <stack>



/**
 * Adds a node with the given value to the binary search tree iteratively.
 *
 * @param[out]   new_city  the value initializing the new node
 */
void BinarySearchTree::add_iteratively (const CityStateZip& new_city)
{
    
    CSZNode* new_node = new CSZNode{ new_city };  //create a new node to be added
    if ( !root )  //if the tree is empty...
    {
        root = new_node;
    }
    else  //if the tree has one or more nodes...
    {
        CSZNode* current  = root;     //ptr for traversal
        CSZNode* previous = nullptr;  //this will be needed for later
        //find the location to insert the node
        while ( current )  //until current ptr encounters the nullptr...
        {
            previous = current;  //to remember where we are
            if ( *new_node < *current )
                current = current -> get_left();  //go to left subtree
            else
                current = current -> get_right();  //go to right subtree
        }
        //insert the node to the correct location
        if ( *new_node < *previous )
            previous -> set_left( new_node );
        else
            previous -> set_right( new_node );
    }
    
}



/**
 * Adds a node with the given value to the binary search tree recursively.
 *
 * @param[out]   new_city  the value initializing the new node
 */
void BinarySearchTree::add_recursively( const CityStateZip& new_city )
{
    
    CSZNode* new_node = new CSZNode{ new_city };  //create a new node to be added
    
    if ( !root )
        root = new_node;
    else
        add_recursively( new_node, root );  //call for recursive function
    
}


/**
 * Adds a node with the given value to the binary search tree recursively.
 *
 * @param[out]   new_node      the node to be added
 * @param[out]   current_root  ptr for traversal of the tree
 */
void BinarySearchTree::add_recursively( CSZNode* &new_node, CSZNode* &current_root )
{
    
    if ( !current_root )  //base condition
        current_root = new_node;  //add the node to the tree
    else if ( *current_root < *new_node )
        add_recursively( new_node, current_root -> get_left() );  //go left subtree
    else
        add_recursively( new_node, current_root -> get_right() );  //go right subtree
    
    
}



/**
 * Displays the values of the node in the tree recursively.
 *
 * @param[out]   new_node      the node to be added
 * @param[out]   current_root  ptr for traversal of the tree
 */
void BinarySearchTree::write_recursively( std::ostream& strm, CSZNode* current_root ) const
{
    
    //this is the inorder traversal...
    if ( current_root )
    {
        write_recursively( strm, current_root -> get_left() );  //keep going to left untill null
        strm << current_root -> get_data();
        write_recursively( strm, current_root -> get_right() );  //keep going to right untill null
    }
    
}



/**
 * Displays the values of the node in the tree iteratively.
 *
 * @param[out]   strm   the output stream to which the values are sent
 */
void BinarySearchTree::write_iteratively( std::ostream& strm ) const
{
    
    CSZNode* current = root;
    std::stack<CSZNode*>  data_stack;
    bool done = false;
    while ( !done )
    {
        if ( current )
        {
            data_stack.push( current );  //save the value in the stack
            current = current -> get_left();  //go to left subtree
        }
        else
        {
            if ( data_stack.empty() )
                done = true;
            else
            {
                strm << *data_stack.top();  //print the top value in the stack
                //go to the right subtree of what is just printed out
                current = data_stack.top() -> get_right();
                data_stack.pop();  //discard the top value in the stack
            }
        }
    }
}

/*
 1, create a current ptr and object of std::stack
 
 2, set current ptr to the root
 
 3, push current node to the stack and move the current to left
    untill it gets to the nullptr
 
 4, if the current is null ptr and the stack is not empty, then
        a, pop the top node from the stack
        b, print the poped node and set current to the right of poped node
        c, go to step 3
 
 5, if current is null ptr and the stack is empty, then we are done.
 
 */



/**
 * Erases all nodes in the tree recursively.
 *
 * @param     currentRoot    the node to be deleted
 */
void BinarySearchTree::erase_recursively( CSZNode* currentRoot )
{
    if ( currentRoot )  //if there are one or more nodes in the tree
    {
        if ( currentRoot -> get_left() )
            erase_recursively( currentRoot -> get_left() );
        if ( currentRoot -> get_right() )
            erase_recursively( currentRoot -> get_right() );
        delete currentRoot;
    }
    root = nullptr;  
}



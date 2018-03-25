#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "CSZNode.h"

class BinarySearchTree {
public:
    BinarySearchTree( ) = default;
    ~BinarySearchTree() { erase_recursively(); }
    void add_recursively( const CityStateZip& new_city );
    void add_iteratively( const CityStateZip& new_city );
    void write_recursively( std::ostream& strm ) const
    { write_recursively( strm, root ); }
    void write_iteratively( std::ostream& strm ) const;
    void erase_recursively() { erase_recursively( root ); }
    
private:
    // methods
    void add_recursively     // called by public version
    ( CSZNode* &new_node, CSZNode* &current_root );
    void write_recursively   // called by public version
    ( std::ostream& strm, CSZNode* current_root ) const;
    void erase_recursively(CSZNode* currentRoot);
    
    // attributes
    CSZNode* root = nullptr; // initially empty tree (null root)
    
    // disallow copy-ctor and assignment:
    BinarySearchTree( const BinarySearchTree& ) = delete;
    BinarySearchTree& operator=( const BinarySearchTree& rhs ) = delete;
};



#endif 

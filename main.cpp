#include "BinarySearchTree.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
#include <limits>




CityStateZip read_CityStateZip( std::istream& fin );

int main()
{
    /*
    std::ifstream fin{"city_list.txt"};
    if ( !fin ) {
        cout << "Error opening city_list.txt!\n";
        exit( 1 );
    }
    
    CSZNode n1{read_CityStateZip( fin )};
    CSZNode n2{read_CityStateZip( fin )};
    
    cout << "test CSZNodes:\n";
    cout << n1 << endl;
    cout << n2 << endl;
    cout << endl;
    
    
    //test for iterative adding
    cout << "Press  to continue...\n";
    cin.get();
    BinarySearchTree city_tree;
    fin.clear();   // restore stream state so I/O may proceed
    fin.seekg(0);  // seek "get" to file start (byte #0)
    while (fin.good())
        city_tree.add_iteratively(read_CityStateZip(fin));
    cout << "Recursive Tree Listing of Iterative Additions\n";
    city_tree.write_recursively(cout);
    
    //test for recursive adding
    cout << "Press  to continue...\n";
    cin.get();
    
    fin.clear();   // restore stream state so I/O may proceed
    fin.seekg(0);  // seek "get" to file start (byte #0)
    while (fin.good())
        city_tree.add_recursively(read_CityStateZip(fin));
    cout << "Iterative Tree Listing of Recursive Additions\n";
    city_tree.write_iteratively(cout);
    */
    
    
    std::ifstream fin{"city_list.txt"};
    if ( !fin ) {
        cout << "Error opening city_list.txt!\n";
        exit( 1 );
    }
    
    CSZNode n1{read_CityStateZip( fin )};
    CSZNode n2{read_CityStateZip( fin )};
    
    cout << "test CSZNodes:\n";
    cout << n1 << endl;
    cout << n2 << endl;
    cout << endl;
    
    
    
    cout << "Press <enter> to continue...\n";
    cin.get();
    BinarySearchTree city_tree;
    fin.clear();   // restore stream state so I/O may proceed
    fin.seekg(0);  // seek "get" to file start (byte #0)
    while (fin.good())
        city_tree.add_iteratively(read_CityStateZip(fin));
    cout << "Recursive Tree Listing of Iterative Additions\n";
    city_tree.write_recursively(cout);
    
    
    
    cout << "Press <enter> to continue...\n";
    cin.get();
    city_tree.erase_recursively();
    cout << "Iterative Tree Listing After Erase:\n";
    city_tree.write_iteratively(cout);
    cout << "<end of tree output>\n\n";
    
    fin.clear();    // restore stream state so I/O may proceed
    fin.seekg(0);   // seek "get" to file start (byte #0)
    
    while (fin.good())
        city_tree.add_recursively(read_CityStateZip(fin));  // recursive add
    cout << "Iterative Listing of Recursive Additions\n";
    city_tree.write_iteratively(cout);
    fin.close();
    
    return 0;
}



/**
 * Displays the values of the node in the tree recursively.
 *
 * @param[out]   fin  the input stream from which the values are read
 *
 * @returned  the object of the CityStateZip class
 */
CityStateZip read_CityStateZip( std::istream& fin ) {
    std::string  city, state;
    unsigned int zip = 0;
    getline( fin, city, ',' );
    getline( fin, state, ',' );
    fin >> zip;
    fin.ignore( std::numeric_limits<std::streamsize>::max( ), '\n' );
    CityStateZip new_csz{city, state, zip};
    return new_csz;
}

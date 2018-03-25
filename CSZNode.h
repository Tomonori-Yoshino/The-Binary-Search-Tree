#ifndef CSZNode_h
#define CSZNode_h


#include "CityStateZip.h"

class CSZNode {
public:
    CSZNode( const CityStateZip& data ) : payload{data} {};
    void          set_left( CSZNode* new_left ) { left = new_left; }
    void          set_right( CSZNode* new_right ) { right = new_right; }
    CityStateZip  get_data( ) const { return payload; }
    CSZNode*      get_left( ) const { return left; }
    CSZNode*      get_right( ) const { return right; }
    CSZNode*&     get_left( ) { return left; }
    CSZNode*&     get_right( ) { return right; }
    
    void write( std::ostream& fout ) const { fout << payload; }
    
    bool operator < (const CSZNode& op2) const { return payload.city() <= op2.payload.city(); }
    
private:
    CityStateZip payload;
    CSZNode*     left  = nullptr;
    CSZNode*     right = nullptr;
};

std::ostream& operator<<( std::ostream& fout, const CSZNode& n );




#endif 

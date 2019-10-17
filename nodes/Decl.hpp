#pragma once

//#include "boost/variant.hpp"

// #include "Enum.hpp"
// #include "Typedef.hpp"
// #include "Struct.hpp"
// #include "Fun.hpp"
// #include "Union.hpp"

#include "CXBase.hpp"
#include "utils.hpp"

namespace cimporter
{

class Decl : public CXBase
{

public:
	Decl(CXCursor cursor);
	
    declType getNodeType() const;

    virtual void parseDecl()                    = 0;
    virtual void accept(ICimpVisitor& visitor)  = 0;

protected:
    declType    _declType;

};

}


// std::shared_ptr<Enum> getEnum() const        { return boost::get<std::shared_ptr<Enum>>(_decl); }
// std::shared_ptr<Typedef> getTypedef() const  { return boost::get<std::shared_ptr<Typedef>>(_decl); }
// std::shared_ptr<Struct> getStruct() const    { return boost::get<std::shared_ptr<Struct>>(_decl); }
// std::shared_ptr<Fun> getFun() const          { return boost::get<std::shared_ptr<Fun>>(_decl); }
// std::shared_ptr<Union> getUnion() const      { return boost::get<std::shared_ptr<Union>>(_decl); }
    
//     boost::variant< std::shared_ptr<Enum>,
//                     std::shared_ptr<Typedef>,
//                     std::shared_ptr<Struct>,
//                     std::shared_ptr<Fun>,
//                     std::shared_ptr<Union> 
//                     > _decl;
// };
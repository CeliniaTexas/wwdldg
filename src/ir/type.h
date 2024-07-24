#ifndef TYPE_H
#define TYPE_H
#include <iostream>
#include <string>
#include <vector>

class Type {
public:
    enum TypeID {
        VoidTyID,      
        IntegerTyID,   
        FloatTyID,     
        FunctionTyID,  
        ArrayTyID,     
        PointerTyID,  
        LabelTyID, 
    };
    TypeID tid_;
    explicit Type(TypeID tid) : tid_(tid) {}
    ~Type() = default;
    virtual std::string print();
};


class IntegerType : public Type {
public:
    unsigned num_bits_;
    explicit IntegerType(unsigned num_bits) : Type(Type::IntegerTyID), num_bits_(num_bits) {}
    
};

//[2 x [3 x i32]]: num_elements_ = 2, contained_ = [3 x i32]

class ArrayType : public Type {
public:
    Type* contained_;        // The element type of the array.
    unsigned num_elements_;  // Number of elements in the array.
    ArrayType(Type* contained, unsigned num_elements) : Type(Type::ArrayTyID), num_elements_(num_elements), contained_(contained) {}
    
};

//[2 x [3 x i32]]*

class PointerType : public Type {
public:
    Type* contained_;  // The element type of the ptr. 
    PointerType(Type* contained) : Type(Type::PointerTyID), contained_(contained) {}
    
};

// declare i32 @putarray(i32, i32*)

class FunctionType : public Type {
public:
    Type* result_;
    std::vector<Type*> args_;

    FunctionType(Type* result, std::vector<Type*> params) : Type(Type::FunctionTyID) {
        result_ = result;
        for (Type* p : params) {
            args_.push_back(p);
        }
    }
    
};
#endif

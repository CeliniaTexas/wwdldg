#ifndef TYPE_H
#define TYPE_H
#include <iostream>
#include <string>
#include <vector>


class Type {
public:
    enum TypeID {
        VoidTyID,      // Void
        LabelTyID,     // Labels, e.g., BasicBlock
        IntegerTyID,   // Integers, include 32 bits and 1 bit
        FloatTyID,     // Floats, only 32 bits
        FunctionTyID,  // Functions
        ArrayTyID,     // Arrays
        PointerTyID,   // Pointer
    };
    explicit Type(TypeID tid) : tid_(tid) {}
    ~Type() = default;
    virtual std::string print();
    TypeID tid_;
};

class IntegerType : public Type {
public:
    explicit IntegerType(unsigned num_bits) : Type(Type::IntegerTyID), num_bits_(num_bits) {}
    unsigned num_bits_;
};

//[2 x [3 x i32]]: num_elements_ = 2, contained_ = [3 x i32]
class ArrayType : public Type {
public:
    ArrayType(Type* contained, unsigned num_elements) : Type(Type::ArrayTyID), num_elements_(num_elements), contained_(contained) {}
    Type* contained_;        // The element type of the array.
    unsigned num_elements_;  // Number of elements in the array.
};

//[2 x [3 x i32]]*
class PointerType : public Type {
public:
    PointerType(Type* contained) : Type(Type::PointerTyID), contained_(contained) {}
    Type* contained_;  // The element type of the ptr.
};

// declare i32 @putarray(i32, i32*)
class FunctionType : public Type {
public:
    FunctionType(Type* result, std::vector<Type*> params) : Type(Type::FunctionTyID) {
        result_ = result;
        for (Type* p : params) {
            args_.push_back(p);
        }
    }
    Type* result_;
    std::vector<Type*> args_;
};
#endif

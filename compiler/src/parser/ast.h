#ifndef WWDLDG_AST_H
#define WWDLDG_AST_H

#include <cassert>
#include <fstream>
#include <map>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

/#include <cassert>
#include <iostream>
#include <list>
#include <set>
#include <utility>
#include <algorithm>
#include <memory>

//可能要用到的
//#include <map>
//#include <set>
//#include <sstream>
//#include <string>
//#include <vector>

//#include <unordered_map>
//#include <unordered_set>

enum class IROp;//TODO

//------------------Type
class Type;
class IntType;
class ArrayType;
class PointerType;
class FunctionType;

//-----------------最基本的关系
class Value;
class Use;
class User;

//------------------继承自Value
class Constant;
class GlobalVariable;
class Instruction;
class BasicBlock;
class Argument;
class Function;

//-------------------指令
class UnaryInst;//单目操作
class BinaryInst;//二元操作
class ICmpInst;//Int比较
class FCmpInst;//Float比较
class FNegInst;//浮点数的取反操作
class ReturnInst;
class GetElementInst;
class LoadInst;
class StoreInst;
class AllocateInst;
class PhiInst;
class ZextInst;
class FpToSiInst;
class SiToFpInst;
class BitcastInst;//没看懂

//---------------------
class module;


class Type {
public:
    enum TypeID {
        IntegerTyID,   // Integer type
        PointerTyID,    // Pointer type
        ArrayTyID,
        FunctionTyID,
    };

    virtual TypeID getTypeID() const = 0;
    virtual std::string getTypeString() const = 0;
};

class IntegerType : public Type {
private:
    unsigned int BitWidth;

public:
    IntegerType(unsigned BitWidth) : BitWidth(BitWidth) {}

    TypeID getTypeID() const override { return IntegerTyID; }

    std::string getTypeString() const override {
        return "i" + std::to_string(BitWidth); // e.g., "i32", "i64"
    }
};


class PointerType : public Type {
private:
    Type *Ptr_;

public:
    PointerType(Type *Ptr) : Ptr_(Ptr) {}

    TypeID getTypeID() const override { return PointerTyID; }

    std::string getTypeString() const override {
        return Ptr_->getTypeString() + "*"; // e.g., "i32*", "i64*"
    }
};

class ArrayType : public Type{
private:
     Type *Ptr_;
     unsigned elements_;
public:
     ArrayType(Type*Ptr, unsigned elements): Ptr_(Ptr), elements_(elements) {}

     TypeID getTypeID() const override {return ArrayTyID;}
      std::string getTypeString() const override {
        return "[" + std::to_string(elements_) + " x " + Ptr_->getTypeString() + "]";
    }
};

class FunctionType :public Type{
//TODO
};

//-------------------------------------Value--------------------------------
class Value{
//TODO

};

//复制北航的
class User : public Value {
    //TODO


  protected:
    Use *OperandList;
    unsigned NumOperands;
};


class Use {
    //TODO
    Use *Next, **Prev;
    Value *Val;
    User *U;
};


#endif
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


#include <iostream>
#include <list>
#include <set>
#include <utility>
#include <algorithm>
#include <memory>
#include "instruction.h"
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

//-------------------指令instruction


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



//-----------------------------------------------Value-----------------------------------------------
class Value {
public:
  

};

//-----------------------------------------------Constant-----------------------------------------------
// 常量都是无名的(name=="")

//-----------------------------------------------Module-----------------------------------------------
class Module {

};

//-----------------------------------------------GlobalVariable-----------------------------------------------
//@c = global [4 x i32] [i32 6, i32 7, i32 8, i32 9]
//@a = constant [5 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4]
class GlobalVariable : public Value {

};

//-----------------------------------------------Function-----------------------------------------------

// 注：Argument的构造函数只由Function的构造函数调用，不单独调用！！
class Argument : public Value {

};

class Function : public Value {

};
//-----------------------------------------------BasicBlock-----------------------------------------------
// 注：BasicBlock一定是LabelTyID
class BasicBlock : public Value {

};

//-----------------------------------------------Instruction-----------------------------------------------
class Instruction : public Value {

//   // ↓↓↓↓↓↓↓↓--------增加快速类型判断
//   bool is_void() {
//     return ((op_id_ == Ret) || (op_id_ == Br) || (op_id_ == Store) ||
//             (op_id_ == Call && this->type_->tid_ == Type::VoidTyID));
//   }

//   bool is_phi() { return op_id_ == PHI; }
//   bool is_store() { return op_id_ == Store; }
//   bool is_alloca() { return op_id_ == Alloca; }
//   bool is_ret() { return op_id_ == Ret; }
//   bool is_load() { return op_id_ == Load; }
//   bool is_br() { return op_id_ == Br; }

//   bool is_add() { return op_id_ == Add; }
//   bool is_sub() { return op_id_ == Sub; }
//   bool is_mul() { return op_id_ == Mul; }
//   bool is_div() { return op_id_ == SDiv; }
//   bool is_rem() { return op_id_ == SRem; }

//   bool is_fadd() { return op_id_ == FAdd; }
//   bool is_fsub() { return op_id_ == FSub; }
//   bool is_fmul() { return op_id_ == FMul; }
//   bool is_fdiv() { return op_id_ == FDiv; }

//   bool is_cmp() { return op_id_ == ICmp; }
//   bool is_fcmp() { return op_id_ == FCmp; }

//   bool is_call() { return op_id_ == Call; }
//   bool is_gep() { return op_id_ == GetElementPtr; }
//   bool is_zext() { return op_id_ == ZExt; }
//   bool is_fptosi() { return op_id_ == FPtoSI; }
//   bool is_sitofp() { return op_id_ == SItoFP; }

//   bool is_int_binary() {
//     return (is_add() || is_sub() || is_mul() || is_div() || is_rem()) &&
//            (num_ops_ == 2);
//   }

//   bool is_float_binary() {
//     return (is_fadd() || is_fsub() || is_fmul() || is_fdiv()) &&
//            (num_ops_ == 2);
//   }

//   bool is_binary() { return is_int_binary() || is_float_binary(); }

//   bool isTerminator() { return is_br() || is_ret(); }

//   // ↑↑↑↑↑↑↑↑--------增加快速类型判断-

  
};

//%77 = add i32 %74, %76
//%10 = and i1 %7, %9
//%7 = xor i1 %6, true
//%13 = fmul float %12, 0x400921FB60000000
class BinaryInst : public Instruction {

};

//%8 = zext i1 %7 to i32
//%51 = fptosi float %50 to i32
//%4 = sitofp i32 %3 to float
//%8 = fneg float %7
//%3 = bitcast [4 x [2 x i32]]* %2 to i32*
class UnaryInst : public Instruction {

};

//%18 = icmp ne i32 %12, %17
class ICmpInst : public Instruction {

};

//%5 = fcmp olt float %4, 0.000000e+00
class FCmpInst : public Instruction {

};

//%111 = call i32 @QuickSort(i32* %108, i32 %109, i32 %110)
class CallInst : public Instruction {

};

// 注：br的返回值类型一定是VoidTyID
class BranchInst : public Instruction {

};

// ret i32 %4
// ret void
// 注：ret的返回值类型一定是VoidTyID
class ReturnInst : public Instruction {

};

//%1 = getelementptr [5 x [4 x i32]], [5 x [4 x i32]]* @a, i32 0, i32 2, i32 3
class GetElementPtrInst : public Instruction {

};

// store <ty> <value>, <ty>* <pointer>
// store i32 %57, i32* %55
// 注：store的返回值类型一定是VoidTyID
class StoreInst : public Instruction {

};

//<result> = load <ty>, <ty>* <pointer>
//%60 = load i32, i32* %59
class LoadInst : public Instruction {

};

//%8 = alloca i32
class AllocaInst : public Instruction {

};

class ZextInst : public Instruction {
public:
  virtual std::string print() override;
  Type *dest_ty_;

};

class FpToSiInst : public Instruction {
public:
  virtual std::string print() override;
  Type *dest_ty_;

};

class SiToFpInst : public Instruction {
public:
  virtual std::string print() override;
  Type *dest_ty_;

};

//%3 = bitcast [4 x [2 x i32]]* %2 to i32*
class Bitcast : public Instruction {
public:
  virtual std::string print() override;
  Type *dest_ty_;

};

//%4 = phi i32 [ 1, %2 ], [ %6, %5 ]
class PhiInst : public Instruction {
public:

  Value *l_val_;
};

//-----------------------------------------------IRStmtBuilder-----------------------------------------------
class IRStmtBuilder {

};

#endif



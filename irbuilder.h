#ifndef IRBUILDER_H
#define IRBUILDER_H
#include "ir.h"

class IRStmtBuilder;

class IRStmtBuilder {
public:
    BasicBlock* BB_;
    Module* m_;
    IRStmtBuilder(BasicBlock* bb, Module* m) : BB_(bb), m_(m){};
    ~IRStmtBuilder() = default;
    Module* get_module() { return m_; }
    BasicBlock* get_insert_block() { return this->BB_; }
    void set_insert_point(BasicBlock* bb) { this->BB_ = bb; }                                                                           
    CallInst* create_call(Value* func, std::vector<Value*> args) ;
    BranchInst* create_br(BasicBlock* if_true) ;
    BranchInst* create_cond_br(Value* cond, BasicBlock* if_true, BasicBlock* if_false) ;
    ReturnInst* create_ret(Value* val) ; 
    ReturnInst* create_void_ret() ;
    GetElementPtrInst* create_gep(Value* ptr, std::vector<Value*> idxs) ;
    StoreInst* create_store(Value* val, Value* ptr) ;
    LoadInst* create_load(Type* ty, Value* ptr) ;
    LoadInst* create_load(Value* ptr) ;
    AllocaInst* create_alloca(Type* ty) ;
    ZextInst* create_zext(Value* val, Type* ty) ;
    FpToSiInst* create_fptosi(Value* val, Type* ty) ;
    SiToFpInst* create_sitofp(Value* val, Type* ty) ;
    Bitcast* create_bitcast(Value *val, Type *ty) ;
    BinaryInst* create_iadd(Value* v1, Value* v2) ;
    BinaryInst* create_isub(Value* v1, Value* v2) ;
    BinaryInst* create_imul(Value* v1, Value* v2) ;
    BinaryInst* create_isdiv(Value* v1, Value* v2) ;
    BinaryInst* create_isrem(Value* v1, Value* v2) ;
    BinaryInst* create_fadd(Value* v1, Value* v2) ;
    BinaryInst* create_fsub(Value* v1, Value* v2) ;
    BinaryInst* create_fmul(Value* v1, Value* v2) ;
    BinaryInst* create_fdiv(Value* v1, Value* v2) ;
    ICmpInst* create_icmp_eq(Value* v1, Value* v2) ;
    ICmpInst* create_icmp_ne(Value* v1, Value* v2) ;
    ICmpInst* create_icmp_gt(Value* v1, Value* v2) ;
    ICmpInst* create_icmp_ge(Value* v1, Value* v2) ;
    ICmpInst* create_icmp_lt(Value* v1, Value* v2) ;
    ICmpInst* create_icmp_le(Value* v1, Value* v2) ;
    FCmpInst* create_fcmp_eq(Value* v1, Value* v2) ;
    FCmpInst* create_fcmp_ne(Value* v1, Value* v2) ;
    FCmpInst* create_fcmp_gt(Value* v1, Value* v2) ;
    FCmpInst* create_fcmp_ge(Value* v1, Value* v2) ;
    FCmpInst* create_fcmp_lt(Value* v1, Value* v2) ;
    FCmpInst* create_fcmp_le(Value* v1, Value* v2) ;
};

#endif
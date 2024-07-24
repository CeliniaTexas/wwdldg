#include "irbuilder.h"

BranchInst* IRStmtBuilder::create_br(BasicBlock* if_true) {
    return new BranchInst(if_true, this->BB_);
}
BranchInst* IRStmtBuilder::create_cond_br(Value* cond, BasicBlock* if_true, BasicBlock* if_false) {
    return new BranchInst(cond, if_true, if_false, this->BB_);
}
ReturnInst* IRStmtBuilder::create_ret(Value* val) {
    return new ReturnInst(val, this->BB_);
}
ReturnInst* IRStmtBuilder::create_void_ret() {
    return new ReturnInst(this->BB_);
}
GetElementPtrInst* IRStmtBuilder::create_gep(Value* ptr, std::vector<Value*> idxs) {
    return new GetElementPtrInst(ptr, idxs, this->BB_);
}
StoreInst* IRStmtBuilder::create_store(Value* val, Value* ptr) {
    return new StoreInst(val, ptr, this->BB_);
}
LoadInst* IRStmtBuilder::create_load(Type* ty, Value* ptr) {
    return new LoadInst(ptr, this->BB_);
}
LoadInst* IRStmtBuilder::create_load(Value* ptr) {
#ifdef DEBUG
    assert(ptr->get_type()->is_pointer_type() && "ptr must be pointer type");
#endif
    // return LoadInst::create_load(ptr->get_type()->get_pointer_element_type(), ptr, this->BB_);
    return new LoadInst(ptr, this->BB_);
}
AllocaInst* IRStmtBuilder::create_alloca(Type* ty) {
    return new AllocaInst(ty, this->BB_);
}
ZextInst* IRStmtBuilder::create_zext(Value* val, Type* ty) {
    return new ZextInst(Instruction::ZExt, val, ty, this->BB_);
}
FpToSiInst* IRStmtBuilder::IRStmtBuilder::create_fptosi(Value* val, Type* ty) {
    return new FpToSiInst(Instruction::FPtoSI, val, ty, this->BB_);
}
SiToFpInst* IRStmtBuilder::create_sitofp(Value* val, Type* ty) {
    return new SiToFpInst(Instruction::SItoFP, val, ty, this->BB_);
}
Bitcast* IRStmtBuilder::create_bitcast(Value *val, Type *ty) {
    return new Bitcast(Instruction::BitCast, val, ty, this->BB_);
}

CallInst* IRStmtBuilder::create_call(Value* func, std::vector<Value*> args) {
#ifdef DEBUG
        assert(dynamic_cast<Function*>(func) && "func must be Function * type");
#endif
        return new CallInst(static_cast<Function*>(func), args, this->BB_);
}

BinaryInst* IRStmtBuilder::create_iadd(Value* v1, Value* v2) { 
    return new BinaryInst(this->m_->int32_ty_, Instruction::Add, v1, v2, this->BB_); 
}
BinaryInst* IRStmtBuilder::create_isub(Value* v1, Value* v2) {
    return new BinaryInst(this->m_->int32_ty_, Instruction::Sub, v1, v2, this->BB_); 
}
BinaryInst* IRStmtBuilder::create_imul(Value* v1, Value* v2) {
    return new BinaryInst(this->m_->int32_ty_, Instruction::Mul, v1, v2, this->BB_); 
}
BinaryInst* IRStmtBuilder::create_isdiv(Value* v1, Value* v2) {
    return new BinaryInst(this->m_->int32_ty_, Instruction::SDiv, v1, v2, this->BB_); 
}
BinaryInst* IRStmtBuilder::create_isrem(Value* v1, Value* v2) {
    return new BinaryInst(this->m_->int32_ty_, Instruction::SRem, v1, v2, this->BB_); 
}
ICmpInst* IRStmtBuilder::create_icmp_eq(Value* v1, Value* v2) {
    return new ICmpInst(ICmpInst::ICMP_EQ, v1, v2, this->BB_); 
}
ICmpInst* IRStmtBuilder::create_icmp_ne(Value* v1, Value* v2) {
    return new ICmpInst(ICmpInst::ICMP_NE, v1, v2, this->BB_); 
}
ICmpInst* IRStmtBuilder::create_icmp_gt(Value* v1, Value* v2) {
    return new ICmpInst(ICmpInst::ICMP_SGT, v1, v2, this->BB_); 
}
ICmpInst* IRStmtBuilder::create_icmp_ge(Value* v1, Value* v2) {
    return new ICmpInst(ICmpInst::ICMP_SGE, v1, v2, this->BB_); 
}
ICmpInst* IRStmtBuilder::create_icmp_lt(Value* v1, Value* v2) {
    return new ICmpInst(ICmpInst::ICMP_SLT, v1, v2, this->BB_); 
}
ICmpInst* IRStmtBuilder::create_icmp_le(Value* v1, Value* v2) {
    return new ICmpInst(ICmpInst::ICMP_SLE, v1, v2, this->BB_); 
}
BinaryInst* IRStmtBuilder::create_fadd(Value* v1, Value* v2) {
    return new BinaryInst(this->m_->float32_ty_, Instruction::FAdd, v1, v2, this->BB_); 
}
BinaryInst* IRStmtBuilder::create_fsub(Value* v1, Value* v2) {
    return new BinaryInst(this->m_->float32_ty_, Instruction::FSub, v1, v2, this->BB_); 
}
BinaryInst* IRStmtBuilder::create_fmul(Value* v1, Value* v2) {
    return new BinaryInst(this->m_->float32_ty_, Instruction::FMul, v1, v2, this->BB_); 
}
BinaryInst* IRStmtBuilder::create_fdiv(Value* v1, Value* v2) {
    return new BinaryInst(this->m_->float32_ty_, Instruction::FDiv, v1, v2, this->BB_); 
}
FCmpInst* IRStmtBuilder::create_fcmp_eq(Value* v1, Value* v2) {
    return new FCmpInst(FCmpInst::FCMP_UEQ, v1, v2, this->BB_); 
}
FCmpInst* IRStmtBuilder::create_fcmp_ne(Value* v1, Value* v2) {
    return new FCmpInst(FCmpInst::FCMP_UNE, v1, v2, this->BB_); 
}
FCmpInst* IRStmtBuilder::create_fcmp_gt(Value* v1, Value* v2) {
    return new FCmpInst(FCmpInst::FCMP_UGT, v1, v2, this->BB_); 
}
FCmpInst* IRStmtBuilder::create_fcmp_ge(Value* v1, Value* v2) {
    return new FCmpInst(FCmpInst::FCMP_UGE, v1, v2, this->BB_); 
}
FCmpInst* IRStmtBuilder::create_fcmp_lt(Value* v1, Value* v2) {
    return new FCmpInst(FCmpInst::FCMP_ULT, v1, v2, this->BB_); 
}
FCmpInst* IRStmtBuilder::create_fcmp_le(Value* v1, Value* v2) {
    return new FCmpInst(FCmpInst::FCMP_ULE, v1, v2, this->BB_); 
}
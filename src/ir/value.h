#ifndef VALUE_H
#define VALUE_H
#include "type.h"

class Value;


struct Use {
    Value* val_;
    unsigned int arg_no_;  // 操作数的序号，如func(a,b)中a的序号为0，b的序号为1
    Use(Value* val, unsigned int no) : val_(val), arg_no_(no) {}
};

//-----------------------------------------------Type-----------------------------------------------

//-----------------------------------------------Value-----------------------------------------------
class Value {
public:
    explicit Value(Type* ty, const std::string& name = "") : type_(ty), name_(name) {}
    ~Value() = default;
    virtual std::string print() = 0;
    
    void remove_use(Value *val) {
        auto is_val = [val] (const Use &use) { return use.val_ == val; };
        use_list_.remove_if(is_val);
    }

    //******************************************************************
    std::list<Use>::iterator add_use(Value* val, unsigned arg_no) { 
        use_list_.emplace_back(Use(val, arg_no)); 
        std::list<Use>::iterator re = use_list_.end();
        return --re;
    }
    //删除迭代器指出的use
    void remove_use(std::list<Use>::iterator it) {
        use_list_.erase(it);
    }
    //user的第i个操作数准备不再使用this，因此删除this与user相关的use联系
    bool remove_used(Instruction* user,unsigned int i) ;


    //******************************************************************

    void replace_all_use_with(Value *new_val);
    Type* type_;
    std::string name_;
    std::list<Use> use_list_;  //所有引用该Value的Instruction的集合，以及该Value在该Instruction的第几个操作数位置被引用
};
#endif

#ifndef VALUE_H
#define VALUE_H
#include "type.h"

class Value;
class Instruction;

struct Use {
    Value* val_;
    unsigned int arg_no_; 
    Use(Value* val, unsigned int no) : val_(val), arg_no_(no) {}
};




class Value {
public:
    Type* type_;
    std::string name_;
    std::list<Use> use_list_;  

    explicit Value(Type* ty, const std::string& name = "") : type_(ty), name_(name) {}
    ~Value() = default;
    virtual std::string print() = 0;
    
    void remove_use(Value *val) {
        auto is_val = [val] (const Use &use) { return use.val_ == val; };
        use_list_.remove_if(is_val);
    }


    std::list<Use>::iterator add_use(Value* val, unsigned arg_no) { 
        use_list_.emplace_back(Use(val, arg_no)); 
        std::list<Use>::iterator re = use_list_.end();
        return --re;
    }
    
    void remove_use(std::list<Use>::iterator it) {
        use_list_.erase(it);
    }
    
    bool remove_used(Instruction* user,unsigned int i) ;


    void replace_all_use_with(Value *new_val);
    
};
#endif

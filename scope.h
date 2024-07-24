#ifndef SCOPE_H
#define SCOPE_H

#include "ir.h"

class Scope;

class Scope {
private:
    std::vector<std::map<std::string, Value *>> symbol;

public:
    // enter a new scope
    void enter() {
        symbol.push_back({});
    }

    // exit a scope
    void exit() {
        symbol.pop_back();
    }

    bool in_global() {
        return symbol.size() == 1;
    }

    // push a name to scope
    // return true if successful
    // return false if this name already exits
    // but func name could be same with variable name
    bool push(std::string name, Value *val) {
        bool result;
        result = (symbol[symbol.size() - 1].insert({name, val})).second;
        return result;
    }

    Value* find(std::string name) {
        for (auto s = symbol.rbegin(); s != symbol.rend(); s++) {
            auto iter = s->find(name);
            if (iter != s->end()) {
                return iter->second;
            }
        }
        return nullptr;
    } 

};

#endif
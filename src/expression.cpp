#include "expression.h"
#include <string>
#include <iostream>

namespace h10 {
        
    Constant::Constant(double val) : value(val) {}

    double Constant::evaluate() const {
        return this->value;
    }

    std::string Constant::toString() const{
        return std::to_string(this->value);
    }

    BinaryPlus::BinaryPlus(const Expression& m1, const Expression& m2) : member1(m1), member2(m2) {}

    double BinaryPlus::evaluate() const {
        return this->member1.evaluate() + this->member2.evaluate();
    }

    std::string BinaryPlus::toString() const {
        return "(" + this->member1.toString() + " + " + this->member2.toString() + ")";
    }

    void printExpression(const Expression& e) {
        std::cout << e.toString() << " = " << e.evaluate() << std::endl;
    }

    Constant::operator std::string() const {
        return this->toString();
    }

    BinaryPlus::operator std::string() const {
        return this->toString();
    }

    double Constant::setValue(double new_val) {
        this->value = new_val;
        return this->value;
    }

    void switchValue(Expression& e, double new_val) {
        try{
            Constant& c = dynamic_cast<Constant&>(e);
            c.setValue(new_val);
        } catch (std::bad_cast& e) {
            std::cerr << "Cannot switch value of non-constant expression" << std::endl;
        }
    }

}
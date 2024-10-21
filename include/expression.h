#pragma once
#include <string>

namespace h10 {

    /**
     * @brief Abstract class representing an expression
     */
    class Expression {
    public:

        /**
         * @brief Returns a string representation of the expression
         * @return std::string
         * @note Pure virtual function
         */
        virtual std::string toString() const = 0;

        /**
         * @brief Evaluates the expression
         * @return double
         * @note Pure virtual function
         */
        virtual double evaluate() const = 0;

        /**
         * @brief Conversion operator to std::string
         * @return std::string
         * @note Pure virtual function
         */
        virtual operator std::string() const = 0;
    };

    /**
     * @brief Class representing a constant expression
     */
    class Constant : public Expression{
        double value;

    public:

        /**
         * @brief Construct a new Constant object
         * 
         * @param val 
         */
        Constant(double val);

        /**
         * @brief Returns a string representation of the constant
         * @return std::string
         */
        std::string toString() const override;

        /**
         * @brief Evaluates the constant
         * @return double
         */
        double evaluate() const override;

        /**
         * @brief Conversion operator to std::string
         * @return std::string
         */
        operator std::string() const override;

        /**
         * @brief Set the value of the constant
         * @param new_val 
         * @return double
         */
        double setValue(double new_val);

    };

    /**
     * @brief Class representing a binary plus expression
     */
    class BinaryPlus : public Expression {
        const Expression& member1;
        const Expression& member2;

    public:

        /**
         * @brief Construct a new Binary Plus object
         * 
         * @param m1 
         * @param m2 
         */
        BinaryPlus(const Expression& m1, const Expression& m2);

        /**
         * @brief Evaluates the binary plus expression
         * @return double
         */
        double evaluate() const override;

        /**
         * @brief Returns a string representation of the binary plus expression
         * @return std::string
         */
        std::string toString() const override;

        /**
         * @brief Conversion operator to std::string
         * @return std::string
         */
        operator std::string() const override;
        
    };

    /**
     * @brief Prints the expression
     * 
     * @param e 
     */
    void printExpression(const Expression& e);

    /**
     * @brief Switches the value of the expression
     * 
     * @param e 
     * @param new_val 
     */
    void switchValue(Expression& e, double new_val);

}
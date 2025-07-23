#include <iostream>
#include <print>
#include <string>

namespace CxxCalc {
    std::string getInput(const std::string &prompt) {
        std::print("{}", prompt);
        std::string input;
        std::cin >> input;
        return input;
    }

    double getNumber(const std::string &prompt) {
        for (;;) {
            double value;
            {
                std::string input = getInput(prompt);
                try {
                    value = std::stod(input);
                } catch (...) {
                    std::println("Please Give A Number");
                    continue;
                }
            }
            return value;
        }
    }

    enum opcodes {
        addition,
        subtraction,
        multiplication,
        division,
        failed
    };

    opcodes strToOpcode(const std::string &opcodeBefore) {
        if (opcodeBefore == "+") return addition;
        if (opcodeBefore == "-") return subtraction;
        if (opcodeBefore == "*") return multiplication;
        if (opcodeBefore == "/") return division;

        return failed;
    }
}

int main() {
    std::println("C++ Calculator");
    const double firstNumber = CxxCalc::getNumber("What is the first number: ");
    CxxCalc::opcodes opcode;
    for (;;) {
        const std::string mathOperator = CxxCalc::getInput("What is the operator: ");

        opcode = CxxCalc::strToOpcode(mathOperator);

        if (opcode == CxxCalc::failed) { std::println("BROSKI, please do a real operator, not a nike logo"); continue; }

        break;
    }

    const double secondNumber = CxxCalc::getNumber("What is the second number: ");
    double finalNumber;

    switch (opcode) {
        case CxxCalc::addition: {
            finalNumber = firstNumber + secondNumber;
        } break;
        case CxxCalc::subtraction: {
            finalNumber = firstNumber - secondNumber;
        } break;
        case CxxCalc::multiplication: {
            finalNumber = firstNumber * secondNumber;
        } break;
        case CxxCalc::division: {
            finalNumber = firstNumber / secondNumber;
        } break;
        default: ; // clang tidy bruh
    }

    std::println("You Got: {} Broski", finalNumber);
}
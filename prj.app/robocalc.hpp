#pragma once
#ifndef ROBOCALC_HPP
#define ROBOCALC_HPP

#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class RoboCalc {
public:
    RoboCalc() = default;
    ~RoboCalc() = default;
    int get_number() const noexcept;
    void set_number(int commands) noexcept;
    virtual void execute() {}

private:
    int number_ = 0;
};

class MUL : public RoboCalc {
public:
    MUL() = default;
    MUL(RoboCalc& calc, int multiplier): calc_(calc), multiplier_(multiplier) {}
    ~MUL() = default;
    void execute() override;

private:
    RoboCalc& calc_;
    int multiplier_;
};

class DIV : public RoboCalc {
public:
    DIV() = default;
    DIV(RoboCalc& calc, int divider) : calc_(calc), divider_(divider) {}
    ~DIV() = default;
    void execute() override;
     
private:
    RoboCalc& calc_;
    int divider_;
};

class SUB : public RoboCalc {
public:
    SUB() = default;
    SUB(RoboCalc& calc, int deductible) : calc_(calc), deductible_(deductible) {}
    ~SUB() = default;
    void execute() override;

private:
    RoboCalc& calc_;
    int deductible_;
};

class ADD : public RoboCalc {
public:
    ADD() = default;
    ADD(RoboCalc& calc, int summand) : calc_(calc), summand_(summand) {}
    ~ADD() = default;
    void execute() override;

private:
    RoboCalc& calc_;
    int summand_;
};

class OUT : public RoboCalc {
public:
    OUT() = default;
    OUT(RoboCalc& calc, int number) : calc_(calc), number_(number) {}
    ~OUT() = default;
    void execute() override;

private:
    RoboCalc& calc_;
    int number_;
};

class REV : public RoboCalc {
public:
    REV() = default;
    REV(RoboCalc& calc, int number) : calc_(calc), number_(number) {}
    ~REV() = default;
    void execute() override;

private:
    RoboCalc& calc_;
    int number_;
};

void StartProgram(std::string inputfile, std::string outputfile);

#endif 

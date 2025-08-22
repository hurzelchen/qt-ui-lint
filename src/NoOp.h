#pragma once

#include "Checker.h"
#include "Fixer.h"

class NoOp : public Checker, public Fixer
{
public:
    NoOp();
    virtual ~NoOp() = default;
};

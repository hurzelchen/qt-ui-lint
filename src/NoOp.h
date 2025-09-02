#pragma once

#include "Checker.h"
#include "Fixer.h"

class NoOp : public Checker, public Fixer
{
public:
    NoOp();
    virtual ~NoOp() = default;

    const QString &name() const override;

    RunResult run(QSharedPointer<QDomElement> subject) override;

private:
    class ToolRegistration
    {
    public:
        ToolRegistration();
    };

    static const ToolRegistration s_toolRegistration;

    static const QString s_name;
};

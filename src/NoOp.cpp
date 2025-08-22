#include "NoOp.h"

#include "ToolFactory.h"

NoOp::ToolRegistration::ToolRegistration()
{
    ToolFactory::registerToolConstructor(QStringLiteral("NoOp"), [] {
        QSharedPointer<NoOp> n{new NoOp()};
        return n.staticCast<Fixer>().staticCast<Tool>();
    });
}

const NoOp::ToolRegistration NoOp::s_toolRegistration{};

NoOp::NoOp()
    : Checker(),
      Fixer()
{
}

Tool::RunResult NoOp::run(QSharedPointer<QDomElement> /*subject*/)
{
    return {};
}

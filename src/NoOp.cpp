#include "NoOp.h"

#include "ToolFactory.h"

const QString NoOp::s_name = QStringLiteral("NoOp");

NoOp::ToolRegistration::ToolRegistration()
{
    ToolFactory::registerToolConstructor(s_name, [] {
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

const QString &NoOp::name() const
{
    return s_name;
}

Tool::RunResult NoOp::run(QSharedPointer<QDomElement> /*subject*/)
{
    return {};
}

#pragma once

class Finding
{
public:
    Finding();
    virtual ~Finding() = default;
};

class Warning : public Finding
{
public:
    Warning();
    virtual ~Warning() = default;
};

class Error : public Finding
{
public:
    Error();
    virtual ~Error() = default;
};

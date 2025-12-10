module;
#include <stdio.h>

export module std:extension.stdio;

export
{
    auto stdin_  = stdin;
    auto stdout_ = stdout;
    auto stderr_ = stderr;
}
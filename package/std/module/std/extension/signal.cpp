module;
#include <csignal>

export module std:extension.signal;

export
{
    constexpr auto SIGABRT_ = SIGABRT;
    constexpr auto SIGFPE_  = SIGFPE;
    constexpr auto SIGILL_  = SIGILL;
    constexpr auto SIGINT_  = SIGINT;
    constexpr auto SIGSEGV_ = SIGSEGV;
    constexpr auto SIGTERM_ = SIGTERM;

    auto SIG_DFL_ = SIG_DFL;
    auto SIG_IGN_ = SIG_IGN;
    auto SIG_ERR_ = SIG_ERR;
}
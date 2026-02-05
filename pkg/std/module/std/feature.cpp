module;
#include <version>

export module std:feature;
// #ifndef __cpp_lib_linalg
// export import    :feature.linalg;
// #endif
#ifndef __cpp_lib_sender
export import    :feature.sender;
#endif
#ifndef __cpp_lib_stacktrace
export import    :feature.stacktrace;
#endif

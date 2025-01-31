
#ifndef _INCLUDED_T51_NESTED_NAMESPACES_
#define _INCLUDED_T51_NESTED_NAMESPACES_

namespace aaaa::bbbb::cccc {
void foo_aaaa_bbbb_cccc() {}
namespace dddd{
    void bar_aaaa_bbbb_cccc_dddd() {}
}
namespace eeee {
    void baz_aaaa_bbbb_cccc_eeee() {}
}
}

#endif // _INCLUDED_T51_NESTED_NAMESPACES_

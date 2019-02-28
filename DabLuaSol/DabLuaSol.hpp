#ifndef DABLUASOL_DABLUASOL_HPP
#define DABLUASOL_DABLUASOL_HPP

#include <Stick/Platform.hpp>
#include <sol/sol.hpp>

namespace dabLuaSol
{

STICK_API void registerDab(sol::state_view _lua, sol::table _tbl);

} // namespace dabLuaSol

#endif // DABLUASOL_DABLUASOL_HPP

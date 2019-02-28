#ifndef DABLUASOL_DABLUASOL_HPP
#define DABLUASOL_DABLUASOL_HPP

#include <Stick/Platform.hpp>
#include <sol/sol.hpp>

namespace dabLuaSol
{

STICK_API void registerDab(sol::state_view _lua, sol::table _tbl);

} // namespace dabLuaSol

namespace sol
{
namespace stack
{
template<>
struct checker<dab::VertexLayout>
{
    template <typename Handler>
    static bool check(lua_State * _L, int _index, Handler && _handler, record & _tracking)
    {
        _tracking.use(1);
        return lua_istable(_L, lua_absindex(_L, _index));
    }
};

template<>
struct getter<dab::VertexLayout>
{
    static dab::VertexLayout get(lua_State * _L, int _index, record & _tracking)
    {
        int aidx = lua_absindex(_L, _index);
        sol::table tbl = stack::get<sol::table>(_L, aidx, _tracking);
        dab::VertexElementArray elements;
        elements.reserve(tbl.size());
        for(auto & kv : tbl)
        {
            sol::table el = kv.second.as<sol::table>();
            dab::DataType dt = el[1];
            stick::UInt32 ec = el[2];
            elements.append((dab::VertexElement){dt, ec});
        }
        return dab::VertexLayout(std::move(elements));
    }
};
} // namespace stack
} // namespace sol

#endif // DABLUASOL_DABLUASOL_HPP

#ifndef DABLUASOL_DABLUASOL_HPP
#define DABLUASOL_DABLUASOL_HPP

#include <Dab/Dab.hpp>
#include <StickLuaSol/StickLuaSol.hpp>

namespace dabLuaSol
{

STICK_API void registerDab(sol::state_view _lua, const stick::String & _namespace = "");
STICK_API void registerDab(sol::state_view _lua, sol::table _tbl);

STICK_API void registerDab(sol::state_view _lua, const stick::String & _namespace)
{
    registerDab(_lua, stickLuaSol::ensureNamespaceTable(_lua, _lua.globals(), _namespace));
}

STICK_API void registerDab(sol::state_view _lua, sol::table _tbl)
{
    using namespace dab;

    sol::table tbl = _tbl;
    tbl.new_enum("DataType",
                 "UInt8",
                 DataType::UInt8,
                 "Int8",
                 DataType::Int8,
                 "UInt16",
                 DataType::UInt16,
                 "Int16",
                 DataType::Int16,
                 "UInt32",
                 DataType::UInt32,
                 "Int32",
                 DataType::Int32,
                 "Float32",
                 DataType::Float32,
                 "Float64",
                 DataType::Float64);

    tbl.new_enum("BufferUsageFlags", "Default", BufferUsageDefault);

    tbl.new_enum("VertexDrawMode",
                 "Triangles",
                 VertexDrawMode::Triangles,
                 "TriangleStrip",
                 VertexDrawMode::TriangleStrip,
                 "TriangleFan",
                 VertexDrawMode::TriangleFan,
                 "Points",
                 VertexDrawMode::Points,
                 "Lines",
                 VertexDrawMode::Lines,
                 "LineStrip",
                 VertexDrawMode::LineStrip,
                 "LineLoop",
                 VertexDrawMode::LineLoop);

    tbl.new_enum(
        "BufferType", "Depth", BufferDepth, "Color", BufferColor, "Stencil", BufferStencil);

    tbl.new_enum("FaceDirection", "CW", FaceDirection::CW, "CCW", FaceDirection::CCW);

    tbl.new_enum("FaceType",
                 "None",
                 FaceType::None,
                 "Front",
                 FaceType::Front,
                 "Back",
                 FaceType::Back,
                 "FrontAndBack",
                 FaceType::FrontAndBack);

    tbl.new_enum("CompareFunction",
                 "Equal",
                 CompareFunction::Equal,
                 "LessEqual",
                 CompareFunction::LessEqual,
                 "GreaterEqual",
                 CompareFunction::GreaterEqual,
                 "NotEqual",
                 CompareFunction::NotEqual,
                 "Never",
                 CompareFunction::Never,
                 "Less",
                 CompareFunction::Less,
                 "Greater",
                 CompareFunction::Greater);

    tbl.new_enum("BlendMode",
                 "Add",
                 BlendMode::Add,
                 "Substract",
                 BlendMode::Substract,
                 "ReverseSubstract",
                 BlendMode::ReverseSubstract,
                 "Min",
                 BlendMode::Min,
                 "Max",
                 BlendMode::Max);

    tbl.new_enum("BlendFunction",
                 "Zero",
                 BlendFunction::Zero,
                 "One",
                 BlendFunction::One,
                 "SourceColor",
                 BlendFunction::SourceColor,
                 "InverseSourceColor",
                 BlendFunction::InverseSourceColor,
                 "DestinationColor",
                 BlendFunction::DestinationColor,
                 "InverseDestinationColor",
                 BlendFunction::InverseDestinationColor,
                 "SourceAlpha",
                 BlendFunction::SourceAlpha,
                 "InverseSourceAlpha",
                 BlendFunction::InverseSourceAlpha,
                 "DestinationAlpha",
                 BlendFunction::DestinationAlpha,
                 "InverseDestinationAlpha",
                 BlendFunction::InverseDestinationAlpha,
                 "ConstantColor",
                 BlendFunction::ConstantColor,
                 "InverseConstantColor",
                 BlendFunction::InverseConstantColor,
                 "ConstantAlpha",
                 BlendFunction::ConstantAlpha,
                 "InverseConstantAlpha",
                 BlendFunction::InverseConstantAlpha);

    tbl.new_enum("TextureFormat",
                 "R8",
                 TextureFormat::R8,
                 "R16",
                 TextureFormat::R16,
                 "R32",
                 TextureFormat::R32,
                 "R16F",
                 TextureFormat::R16F,
                 "R32F",
                 TextureFormat::R32F,
                 "RGB8",
                 TextureFormat::RGB8,
                 "RGB16",
                 TextureFormat::RGB16,
                 "RGB32",
                 TextureFormat::RGB32,
                 "RGB16F",
                 TextureFormat::RGB16F,
                 "RGB32F",
                 TextureFormat::RGB32F,
                 "BGR8",
                 TextureFormat::BGR8,
                 "BGR16",
                 TextureFormat::BGR16,
                 "BGR32",
                 TextureFormat::BGR32,
                 "BGR16F",
                 TextureFormat::BGR16F,
                 "BGR32F",
                 TextureFormat::BGR32F,
                 "RGBA8",
                 TextureFormat::RGBA8,
                 "RGBA16",
                 TextureFormat::RGBA16,
                 "RGBA32",
                 TextureFormat::RGBA32,
                 "RGBA16F",
                 TextureFormat::RGBA16F,
                 "RGBA32F",
                 TextureFormat::RGBA32F,
                 "BGRA8",
                 TextureFormat::BGRA8,
                 "BGRA16",
                 TextureFormat::BGRA16,
                 "BGRA32",
                 TextureFormat::BGRA32,
                 "BGRA16F",
                 TextureFormat::BGRA16F,
                 "BGRA32F",
                 TextureFormat::BGRA32F,
                 "Depth16",
                 TextureFormat::Depth16,
                 "Depth24",
                 TextureFormat::Depth24,
                 "Depth32",
                 TextureFormat::Depth32,
                 "Depth24Stencil8",
                 TextureFormat::Depth24Stencil8,
                 "Depth32F",
                 TextureFormat::Depth32F,
                 "Depth32FStencil8",
                 TextureFormat::Depth32FStencil8);

    tbl.new_enum("TextureWrap",
                 "Repeat",
                 TextureWrap::Repeat,
                 "ClampToEdge",
                 TextureWrap::ClampToEdge,
                 "ClampToBorder",
                 TextureWrap::ClampToBorder);

    tbl.new_enum("TextureFiltering",
                 "Nearest",
                 TextureFiltering::Nearest,
                 "Bilinear",
                 TextureFiltering::Bilinear,
                 "Trilinear",
                 TextureFiltering::Trilinear);

    tbl.new_usertype<RenderDevice>("RenderDevice",
                                   "new",
                                   sol::no_constructor,
                                   "createProgram",
                                   &RenderDevice::createProgram,
                                   "destroyProgram",
                                   &RenderDevice::destroyProgram,
                                   "createPipeline",
                                   &RenderDevice::createPipeline,
                                   "destroyPipeline",
                                   &RenderDevice::destroyPipeline,
                                   "createVertexBuffer",
                                   &RenderDevice::createVertexBuffer,
                                   "destroyVertexBuffer",
                                   &RenderDevice::destroyVertexBuffer,
                                   "createIndexBuffer",
                                   &RenderDevice::createIndexBuffer,
                                   "destroyIndexBuffer",
                                   &RenderDevice::destroyIndexBuffer,
                                   "createMesh",
                                   [](RenderDevice * _self, sol::table _tbl) {
                                       //@TODO: proper allocators
                                       stick::DynamicArray<VertexBuffer *> buffers;
                                       stick::DynamicArray<VertexLayout> layouts;

                                       Size count = _tbl.size();
                                       buffers.reserve(count);
                                       layouts.reserve(count);

                                       for (auto & kv : _tbl)
                                       {
                                           sol::table el = kv.second.as<sol::table>();
                                           dab::VertexBuffer * vb = el[1];
                                           sol::table tbl2 = el[2];

                                           dab::VertexElementArray elements;
                                           elements.reserve(tbl2.size());

                                           for (auto & kv2 : tbl2)
                                           {
                                               sol::table el2 = kv2.second.as<sol::table>();
                                               dab::DataType dt = el2[1];
                                               stick::UInt32 ec = el2[2];
                                               elements.append((dab::VertexElement){ dt, ec });
                                           }
                                           buffers.append(vb);
                                           layouts.append(VertexLayout(std::move(elements)));
                                       }

                                       return _self->createMesh(
                                           &buffers[0], &layouts[0], buffers.count());
                                   },
                                   "destroyMesh",
                                   &RenderDevice::destroyMesh,
                                   "createTexture",
                                   &RenderDevice::createTexture,
                                   "destroyTexture",
                                   &RenderDevice::destroyTexture,
                                   "createSampler",
                                   &RenderDevice::createSampler,
                                   "destroySampler",
                                   &RenderDevice::destroySampler,
                                   "createRenderBuffer",
                                   &RenderDevice::createRenderBuffer,
                                   "destroyRenderBuffer",
                                   &RenderDevice::destroyRenderBuffer,
                                   "beginPass",
                                   &RenderDevice::beginPass,
                                   "endPass",
                                   &RenderDevice::endPass,
                                   "beginFrame",
                                   &RenderDevice::beginFrame,
                                   "endFrame",
                                   &RenderDevice::endFrame,
                                   "readPixels",
                                   &RenderDevice::readPixels);

    //@NOTE: I think this is a bug in sol2. we need to wrap this in a lambda so that the custom
    // stick::Result pusher in StickLuaSol is properly utilized across library boundaries. Oddly
    // enough this only appears to be an issue for free functions.
    tbl.set_function("createRenderDevice", []() { return createRenderDevice(); });
    tbl.set_function("destroyRenderDevice", destroyRenderDevice);

    tbl.new_usertype<Program>("Program", "new", sol::no_constructor);

    tbl.new_usertype<Pipeline>("Pipeline",
                               "new",
                               sol::no_constructor,
                               "variable",
                               &Pipeline::variable,
                               "texture",
                               &Pipeline::texture);

    tbl.new_usertype<PipelineVariable>("PipelineVariable",
                                       "new",
                                       sol::no_constructor,
                                       "setFloat32",
                                       &PipelineVariable::setFloat32,
                                       "setInt32",
                                       &PipelineVariable::setInt32,
                                       "setVec2f",
                                       &PipelineVariable::setVec2f,
                                       "setVec3f",
                                       &PipelineVariable::setVec3f,
                                       "setVec4f",
                                       &PipelineVariable::setVec4f,
                                       "setMat4f",
                                       &PipelineVariable::setMat4f);

    tbl.new_usertype<PipelineTexture>(
        "PipelineTexture", "new", sol::no_constructor, "set", &PipelineTexture::set);

    tbl.new_usertype<VertexBuffer>("VertexBuffer",
                                   "new",
                                   sol::no_constructor,
                                   "loadData",
                                   [](VertexBuffer * _self, sol::table _data) {
                                       stick::DynamicArray<Float32> data;
                                       data.reserve(_data.size());
                                       for (auto & kv : _data)
                                       {
                                           STICK_ASSERT(kv.second.is<Float32>());
                                           data.append(kv.second.as<Float32>());
                                       }
                                       _self->loadDataRaw(&data[0], sizeof(Float32) * data.count());
                                   });

    tbl.new_usertype<IndexBuffer>("IndexBuffer",
                                  "new",
                                  sol::no_constructor,
                                  "loadData",
                                  [](IndexBuffer * _self, sol::table _data) {
                                      stick::DynamicArray<UInt32> data;
                                      data.reserve(_data.size());
                                      for (auto & kv : _data)
                                      {
                                          STICK_ASSERT(kv.second.is<UInt32>());
                                          data.append(kv.second.as<UInt32>());
                                      }
                                      _self->loadDataRaw(&data[0], sizeof(UInt32) * data.count());
                                  });

    tbl.new_usertype<Mesh>("Mesh", "new", sol::no_constructor);

    tbl.new_usertype<Texture>("Texture", "new", sol::no_constructor);
    tbl.new_usertype<Sampler>("Sampler", "new", sol::no_constructor);

    tbl.new_usertype<RenderBuffer>("RenderBuffer",
                                   "new",
                                   sol::no_constructor,
                                   "colorTargets",
                                   &RenderBuffer::colorTargets,
                                   "depthStencilTarget",
                                   &RenderBuffer::depthStencilTarget,
                                   "width",
                                   &RenderBuffer::width,
                                   "height",
                                   &RenderBuffer::height,
                                   "sampleCount",
                                   &RenderBuffer::sampleCount);

    virtual void drawMesh(const Mesh * _mesh,
                          const Pipeline * _pipeline,
                          UInt32 _vertexOffset,
                          UInt32 _vertexCount,
                          VertexDrawMode _drawMode) = 0;

    virtual void drawMesh(const Mesh * _mesh,
                          const Pipeline * _pipeline,
                          UInt32 _vertexOffset,
                          UInt32 _vertexCount,
                          UInt32 _baseVertex,
                          VertexDrawMode _drawMode) = 0;

    tbl.new_usertype<RenderPass>(
        "RenderPass",
        "new",
        sol::no_constructor,
        "drawMesh",
        sol::overload(
            (void (RenderPass::*)(const Mesh *, const Pipeline *, UInt32, UInt32, VertexDrawMode)) &
                RenderPass::drawMesh,
            (void (RenderPass::*)(
                const Mesh *, const Pipeline *, UInt32, UInt32, UInt32, VertexDrawMode)) &
                RenderPass::drawMesh),
        "drawCustom",
        [](RenderPass * _self, sol::function _fn) { _self->drawCustom([_fn]() { return _fn(); }); },
        "setViewport",
        &RenderPass::setViewport,
        "clearBuffers",
        &RenderPass::clearBuffers);
}

} // namespace dabLuaSol

namespace sol
{
namespace stack
{
// template <>
// struct checker<dab::VertexLayout>
// {
//     template <typename Handler>
//     static bool check(lua_State * _L, int _index, Handler && _handler, record & _tracking)
//     {
//         _tracking.use(1);
//         return lua_istable(_L, lua_absindex(_L, _index));
//     }
// };

// template <>
// struct getter<dab::VertexLayout>
// {
//     static dab::VertexLayout get(lua_State * _L, int _index, record & _tracking)
//     {
//         int aidx = lua_absindex(_L, _index);
//         sol::table tbl = stack::get<sol::table>(_L, aidx, _tracking);
//         dab::VertexElementArray elements;
//         elements.reserve(tbl.size());
//         for (auto & kv : tbl)
//         {
//             sol::table el = kv.second.as<sol::table>();
//             dab::DataType dt = el[1];
//             stick::UInt32 ec = el[2];
//             elements.append((dab::VertexElement){ dt, ec });
//         }
//         return dab::VertexLayout(std::move(elements));
//     }
// };

template <>
struct checker<dab::RenderBufferSettings>
{
    template <typename Handler>
    static bool check(lua_State * _L, int _index, Handler && _handler, record & _tracking)
    {
        //@TODO: do we need to check if all fields are present in the table??
        _tracking.use(1);
        return lua_istable(_L, lua_absindex(_L, _index));
    }
};

template <>
struct getter<dab::RenderBufferSettings>
{
    static dab::RenderBufferSettings get(lua_State * _L, int _index, record & _tracking)
    {
        int aidx = lua_absindex(_L, _index);
        sol::table tbl = stack::get<sol::table>(_L, aidx, _tracking);
        stick::Float32 width = tbl["width"];
        stick::Float32 height = tbl["height"];
        stick::UInt32 sampleCount = tbl["sampleCount"]; //@TODO make this optional

        dab::RenderBufferSettings settings;
        settings.width = width;
        settings.height = height;
        settings.sampleCount = sampleCount;

        sol::table renderTargets = tbl["renderTargets"];
        settings.renderTargets.reserve(renderTargets.size());
        for (auto & kv : renderTargets)
        {
            sol::table v = kv.second.as<sol::table>();
            dab::TextureFormat fmt = v[1];
            stick::UInt32 mipMapLevelCount = 0;
            if (v.size() > 1)
                mipMapLevelCount = v[2];
            settings.renderTargets.append(
                (dab::RenderBufferSettings::RenderTarget){ fmt, mipMapLevelCount });
        }

        return settings;
    }
};

template <>
struct checker<dab::PipelineSettings>
{
    template <typename Handler>
    static bool check(lua_State * _L, int _index, Handler && _handler, record & _tracking)
    {
        //@TODO: do we need to check if all fields are present in the table??
        _tracking.use(1);
        return lua_istable(_L, lua_absindex(_L, _index));
    }
};

template <>
struct getter<dab::PipelineSettings>
{
    static dab::PipelineSettings get(lua_State * _L, int _index, record & _tracking)
    {
        int aidx = lua_absindex(_L, _index);
        sol::table tbl = stack::get<sol::table>(_L, aidx, _tracking);
        dab::PipelineSettings ret;

        //@TODO: finish this once the render state stuff is finished in Dab
        sol::optional<dab::Program *> oProg = tbl["program"];
        if (oProg)
            ret.program = oProg.value();

        sol::optional<sol::table> oVp = tbl["viewport"];
        if (oVp)
        {
            ret.viewport = {
                oVp.value()["x"], oVp.value()["y"], oVp.value()["width"], oVp.value()["height"]
            };
        }

        sol::optional<sol::table> osciss = tbl["scissor"];
        if (osciss)
        {
            ret.scissor = (dab::Rect){ osciss.value()["x"],
                                       osciss.value()["y"],
                                       osciss.value()["width"],
                                       osciss.value()["height"] };
        }

        sol::optional<bool> oms = tbl["multisample"];
        if (oms)
            ret.multisample = oms.value();

        sol::optional<bool> odt = tbl["depthTest"];
        if (odt)
            ret.depthTest = odt.value();

        sol::optional<bool> odw = tbl["depthWrite"];
        if (odw)
            ret.depthWrite = odw.value();

        sol::optional<dab::CompareFunction> odf = tbl["depthFunction"];
        if (odf)
            ret.depthFunction = odf.value();

        sol::optional<sol::table> ocws = tbl["colorWriteSettings"];
        if (ocws)
        {
            ret.colorWriteSettings = {
                ocws.value()["r"], ocws.value()["g"], ocws.value()["b"], ocws.value()["a"]
            };
        }

        sol::optional<dab::FaceDirection> ofd = tbl["faceDirection"];
        if (ofd)
            ret.faceDirection = ofd.value();

        sol::optional<dab::FaceType> ocf = tbl["cullFace"];
        if (ocf)
            ret.cullFace = ocf.value();

        return ret;
    }
};

template <>
struct checker<dab::SamplerSettings>
{
    template <typename Handler>
    static bool check(lua_State * _L, int _index, Handler && _handler, record & _tracking)
    {
        //@TODO: do we need to check if all fields are present in the table??
        _tracking.use(1);
        return lua_istable(_L, lua_absindex(_L, _index));
    }
};

template <>
struct getter<dab::SamplerSettings>
{
    static dab::SamplerSettings get(lua_State * _L, int _index, record & _tracking)
    {
        int aidx = lua_absindex(_L, _index);
        sol::table tbl = stack::get<sol::table>(_L, aidx, _tracking);

        dab::SamplerSettings ret;

        sol::optional<dab::TextureWrap> oWrap = tbl["wrap"];
        if (oWrap)
        {
            ret.wrapS = oWrap.value();
            ret.wrapT = ret.wrapS;
            ret.wrapR = ret.wrapS;
        }
        else
        {
            sol::optional<dab::TextureWrap> oWrapS = tbl["wrapS"];
            if (oWrapS)
                ret.wrapS = oWrapS.value();
            sol::optional<dab::TextureWrap> oWrapT = tbl["wrapT"];
            if (oWrapT)
                ret.wrapT = oWrapT.value();
            sol::optional<dab::TextureWrap> oWrapR = tbl["wrapR"];
            if (oWrapR)
                ret.wrapR = oWrapR.value();
        }
        sol::optional<dab::TextureFiltering> of = tbl["filtering"];
        if (of)
            ret.filtering = of.value();

        sol::optional<bool> omm = tbl["mipMapping"];
        if (omm)
            ret.mipMapping = omm.value();

        return ret;
    }
};

template <>
struct checker<dab::RenderPassSettings>
{
    template <typename Handler>
    static bool check(lua_State * _L, int _index, Handler && _handler, record & _tracking)
    {
        //@TODO: do we need to check if all fields are present in the table??
        _tracking.use(1);
        return lua_istable(_L, lua_absindex(_L, _index));
    }
};

template <>
struct getter<dab::RenderPassSettings>
{
    static dab::RenderPassSettings get(lua_State * _L, int _index, record & _tracking)
    {
        int aidx = lua_absindex(_L, _index);
        sol::table tbl = stack::get<sol::table>(_L, aidx, _tracking);

        dab::RenderPassSettings ret;

        sol::optional<dab::RenderBuffer *> orb = tbl["renderBuffer"];
        if (orb)
            ret.renderBuffer = orb.value();

        sol::optional<sol::table> occ = tbl["clear"];
        if (occ)
        {
            dab::ClearSettings set;

            sol::optional<sol::table> ocol = occ.value()["color"];
            if (ocol)
                set.color = (dab::ClearColor){
                    ocol.value()[1], ocol.value()[2], ocol.value()[3], ocol.value()[4]
                };

            sol::optional<stick::Float64> odepth = occ.value()["depth"];
            if (odepth)
                set.depth = odepth.value();

            sol::optional<stick::Int32> ostencil = occ.value()["stencil"];
            if (ostencil)
                set.stencil = ostencil.value();

            ret.clear = set;
        }

        return ret;
    }
};

} // namespace stack
} // namespace sol

#endif // DABLUASOL_DABLUASOL_HPP

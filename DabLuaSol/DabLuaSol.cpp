#include <Dab/Dab.hpp>
#include <DabLuaSol/DabLuaSol.hpp>

namespace dabLuaSol
{

void registerDab(sol::state_view _lua, sol::table _tbl)
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
                                   &RenderDevice::createMesh,
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
                                   &RenderDevice::endFrame);

    tbl.set_function("createRenderDevice", createRenderDevice);
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

    tbl.new_usertype<RenderPass>(
        "RenderPass",
        "new",
        sol::no_constructor,
        "drawMesh",
        &RenderPass::drawMesh,
        "drawCustom",
        [](RenderPass * _self, sol::function _fn) { _self->drawCustom([_fn]() { return _fn(); }); },
        "setViewport",
        &RenderPass::setViewport,
        "clearBuffers",
        &RenderPass::clearBuffers);
}

} // namespace dabLuaSol

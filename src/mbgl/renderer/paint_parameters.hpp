#pragma once

#include <mbgl/gl/gl_config.hpp>
#include <mbgl/gl/gl.hpp>

#include <mbgl/map/mode.hpp>

#include <array>

namespace mbgl {

class TransformState;
class Shaders;
class StaticRasterVertexBuffer;

class SpriteAtlas;
class GlyphAtlas;
class LineAtlas;
class FrameHistory;

class PaintParameters {
public:
    gl::Config& config;
    gl::ObjectStore& store;
    Shaders& shaders;
    StaticRasterVertexBuffer& rasterBoundsBuffer;

    bool overdraw;
    std::array<uint16_t, 2> framebufferSize;
    float pixelRatio;
    MapMode mapMode;

    const TransformState& state;
    const std::array<float, 2>& pixelsToGLUnits;

    SpriteAtlas& spriteAtlas;
    GlyphAtlas& glyphAtlas;
    LineAtlas& lineAtlas;
    FrameHistory& frameHistory;

    void setDepthSublayer(int n);
};

} // namespace mbgl

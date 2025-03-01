#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glad/glad.h>

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class Renderer {
    public:
        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};

#endif
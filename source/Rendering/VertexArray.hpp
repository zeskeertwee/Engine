#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include "VertexBuffer.hpp"

class VertexBufferLayout;

class VertexArray {
    private:
        unsigned int m_RendererID;
    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

        void Bind() const;
        void Unbind() const;
};

#endif
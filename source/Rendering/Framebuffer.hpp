#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>

enum class FramebufferTextureFormat
	{
		None = 0,

		// Color
		RGBA8,
		RED_INTEGER,

		// Depth/stencil
		DEPTH24STENCIL8,

		// Defaults
		Depth = DEPTH24STENCIL8
	};

struct FramebufferTextureSpecification {
    FramebufferTextureSpecification() = default;
    FramebufferTextureSpecification(FramebufferTextureFormat format) : TextureFormat(format) {}
    FramebufferTextureFormat TextureFormat = FramebufferTextureFormat::None;
};

struct FramebufferAttachmentSpecification {
    FramebufferAttachmentSpecification() = default;
    FramebufferAttachmentSpecification(std::initializer_list<FramebufferTextureSpecification> attachments) : Attachments(attachments) {}

    std::vector<FramebufferTextureSpecification> Attachments;
};

struct FramebufferSpecification {
    int Width = 0, Height = 0;
    FramebufferAttachmentSpecification Attachments;
    int Samples = 1;
};

class Framebuffer {
    public:
        Framebuffer(const FramebufferSpecification& spec);
        ~Framebuffer();
        FramebufferSpecification GetSpecification() { return m_Specification; }

        void Resize(int Width, int Height);
        int ReadPixel(unsigned int attachmentIndex, int x, int y);
        void TestPixel();
        void Invalidate();

        void Bind();
        void Unbind();

        void ClearAttachment(unsigned int attachmentIndex, int value);

        unsigned int GetColorAttachmentRendererID(unsigned int index = 0) { return m_ColorAttachments[index]; }

    private:
        unsigned int m_RendererID;
        //unsigned int m_ColorAttachment, m_DepthAttachment, m_rbo;
        FramebufferSpecification m_Specification;

        std::vector<FramebufferTextureSpecification> m_ColorAttachmentSpecifications;
        FramebufferTextureSpecification m_DepthAttachmentSpecification = FramebufferTextureFormat::None;

        std::vector<unsigned int> m_ColorAttachments;
        unsigned int m_DepthAttachment = 0;
};

#endif
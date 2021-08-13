#include "hzpch.h"
#include "OpenGLTexture.h"

#include "stb_image/stb_image.h"

#include <glad/glad.h>

namespace Hazel {

    OpenGLTexture2D::OpenGLTexture2D(const std::string &path) : m_Path(path) {
        int width, height, channels;

        stbi_set_flip_vertically_on_load(1);
        stbi_uc *data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        HZ_CORE_ASSERT(data, "Failed to load image!");
        m_Width = width;
        m_Height = height;

        GLenum internalFormat = (channels == 4) ? GL_RGBA8 : (channels == 3) ? GL_RGB8 : 0;
        GLenum dataFormat = (channels == 4) ? GL_RGBA : (channels == 3) ? GL_RGB : 0;
        HZ_CORE_ASSERT((internalFormat & dataFormat), "Format not supported!");
        m_InternalFormat = internalFormat;
        m_DataFormat = dataFormat;

        // Upload to GPU
        glGenTextures(1, &m_RendererID);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_DataFormat, GL_UNSIGNED_BYTE, data);

        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(data);
    }

    OpenGLTexture2D::~OpenGLTexture2D() {
        glDeleteTextures(1, &m_RendererID);
    }

    void OpenGLTexture2D::Bind(uint32_t slot) const {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
    }
}

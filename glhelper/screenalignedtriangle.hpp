#pragma once

#include "gl.hpp"

namespace gl
{
	class Buffer;
	class VertexArrayObject;

	// class for rendering a screen aligned triangle
	class ScreenAlignedTriangle
	{
	public:
		ScreenAlignedTriangle(const ScreenAlignedTriangle&) = delete;
		void operator = (const ScreenAlignedTriangle&) = delete;

		ScreenAlignedTriangle(const Details::DefaultVec2<float>& min=Details::DefaultVec2<float>(-1, -3),
		                      const Details::DefaultVec2<float>& max=Details::DefaultVec2<float>(3, 1));
		~ScreenAlignedTriangle();

		void Draw() const;

	private:
		Buffer* m_vertexBuffer;
		VertexArrayObject* m_vertexArrayObject;
	};
}
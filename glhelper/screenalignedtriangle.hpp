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

		ScreenAlignedTriangle(const Vec2& min=Vec2(-1, -1), const Vec2& max=Vec2(1, 1));
		~ScreenAlignedTriangle();

		void Draw() const;

	private:
		Buffer* m_vertexBuffer;
		VertexArrayObject* m_vertexArrayObject;
	};
}
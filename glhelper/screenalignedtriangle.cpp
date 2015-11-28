#include "screenalignedtriangle.hpp"
#include "buffer.hpp"
#include "vertexarrayobject.hpp"

namespace gl
{
	struct ScreenTriVertex
	{
		float position[2];
	};

	ScreenAlignedTriangle::ScreenAlignedTriangle(const Details::DefaultVec2<float>& min,
	                                             const Details::DefaultVec2<float>& max)
	{
		ScreenTriVertex screenTriangle[3];
		screenTriangle[0].position[0] = min.x;
		screenTriangle[0].position[1] = max.y;
		screenTriangle[1].position[0] = max.x;
		screenTriangle[1].position[1] = max.y;
		screenTriangle[2].position[0] = min.x;
		screenTriangle[2].position[1] = min.y;

		m_vertexBuffer = new Buffer(sizeof(screenTriangle), Buffer::UsageFlag::IMMUTABLE, screenTriangle);
		m_vertexArrayObject = new VertexArrayObject({ VertexArrayObject::Attribute(VertexArrayObject::Attribute::Type::FLOAT, 2) });
	}


	ScreenAlignedTriangle::~ScreenAlignedTriangle(void)
	{
		delete m_vertexBuffer;
		delete m_vertexArrayObject;
	}

	void ScreenAlignedTriangle::Draw() const
	{
		m_vertexArrayObject->Bind();
		m_vertexBuffer->BindVertexBuffer(0, 0, m_vertexArrayObject->GetVertexStride(0));
		GL_CALL(glDrawArrays, GL_TRIANGLES, 0, 3);
	}
}
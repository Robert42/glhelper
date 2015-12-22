#pragma once

#include <glhelperconfig.hpp>
#include <type_traits>

namespace gl
{
	// Typedefs for different kinds of OpenGL IDs for better readability.
	typedef GLuint ShaderId;
	typedef GLuint ProgramId;

	typedef GLuint BufferId;
	typedef GLuint IndexBufferId;
	typedef GLuint VertexArrayObjectId;

	typedef GLuint TextureId;
	typedef GLuint FramebufferId;
	typedef GLuint SamplerId;

	typedef GLuint QueryId;


	// Error handling

	// Note that using GL_CALL may not be that important anymore if using the DebugMessage functionality (see ActivateDebugExtension)


	enum class DebugSeverity
	{
		NOTIFICATION,
		LOW,
		MEDIUM,
		HIGH
	};

	/// Activates GL_DEBUG_OUTPUT.
	void ActivateGLDebugOutput(DebugSeverity level);

	/// Simple result code used in several places.
	enum class Result
	{
		FAILURE = 0,
		SUCCEEDED
	};

	/// Performs OpenGL error handling via glGetError and outputs results into the log.
	/// \param openGLFunctionName
	///		Name of the last OpenGL function that should is implicitly checked.
	Result CheckGLError(const char* openGLFunctionName);

	/// Checks weather the given function pointer is not null and reports an error if it does not exist.
	/// \returns false if fkt is nullptr.
	bool CheckGLFunctionExistsAndReport(const char* openGLFunctionName, const void* fkt);

	// Internal definitions of checked OpenGL calls.
	namespace Details
	{
		template<typename GlFunction, typename... Args>
		Result CheckedGLCall(const char* openGLFunctionName, GlFunction openGLFunction, Args&&... args)
		{
			if (!CheckGLFunctionExistsAndReport(openGLFunctionName, reinterpret_cast<const void*>(openGLFunction)))
				return Result::FAILURE;
			openGLFunction(args...);
			return CheckGLError(openGLFunctionName);
		}


    template<typename T>
    class R;

    template<typename ReturnType, typename... Args>
    class R<ReturnType(*)(Args...)>
    {
    public:
      typedef ReturnType type;
    };
		

		template<typename GlFunction, typename... Args>
		typename R<GlFunction>::type CheckedGLCall_Ret(const char* openGLFunctionName, GlFunction openGLFunction, Args&&... args)
		{
			if (!CheckGLFunctionExistsAndReport(openGLFunctionName, reinterpret_cast<const void*>(openGLFunction)))
				return 0;
			typename R<GlFunction>::type out = openGLFunction(args...);
			CheckGLError(openGLFunctionName);
			return out;
		}
	}

#ifndef NDEBUG

	/// Recommend way to call any OpenGL function. Will perform optional nullptr and glGetError checks during debug runs.
#define GL_CALL(OpenGLFunction, ...) \
	do { ::gl::Details::CheckedGLCall(#OpenGLFunction, OpenGLFunction, __VA_ARGS__); } while(false)

	/// There are a few functions that have a return value (glGet, glIsX, glCreateShader, glCreateProgram). Use this macro for those.
	/// \see GL_CALL
#define GL_RET_CALL_NO_ARGS(OpenGLFunction) \
	::gl::Details::CheckedGLCall_Ret(#OpenGLFunction, OpenGLFunction)

  /// There are a few functions that have a return value (glGet, glIsX, glCreateShader, glCreateProgram). Use this macro for those.
	/// \see GL_CALL
#define GL_RET_CALL(OpenGLFunction, ...) \
	::gl::Details::CheckedGLCall_Ret(#OpenGLFunction, OpenGLFunction, __VA_ARGS__)

#else

#define GL_CALL(OpenGLFunction, ...) OpenGLFunction(__VA_ARGS__)

#define GL_RET_CALL(OpenGLFunction, ...) OpenGLFunction(__VA_ARGS__)

#define GL_RET_CALL_NO_ARGS(OpenGLFunction) OpenGLFunction()

#endif
}

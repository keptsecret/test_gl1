#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>

class Shader
{
public:
	unsigned int ID;

	// constructor reads and builds shader
	Shader(const char* vertexPath, const char* fragmentPath);

	// activate shader
	void use()
	{
		glUseProgram(ID);
	}
	// utility functions for uniforms
	void setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}
	void setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), (float)value);
	}
};

#endif // !SHADER_H

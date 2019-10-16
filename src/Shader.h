#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "GPU-Includes.h"

class Shader
{
	public:
		int id;

		Shader(char *vertex_path, char *fragment_path)
		{
			std::string vertex_code;
			std::string fragment_code;
			std::ifstream vshaderfile;
			std::ifstream fshaderfile;
			vshaderfile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
			fshaderfile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

			try
			{
				vshaderfile.open(vertex_path);
				fshaderfile.open(fragment_path);
				std::stringstream vshaderstream, fshaderstream;
				vshaderstream << vshaderfile.rdbuf();
				fshaderstream << fshaderfile.rdbuf();
				vshaderfile.close();
				fshaderfile.close();
				vertex_code   = vshaderstream.str();
				fragment_code = fshaderstream.str();
			}
			catch (std::ifstream::failure e)
			{
				std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
			}

			const char *vshadercode = vertex_code.c_str();
			const char *fshadercode = fragment_code.c_str();

			unsigned int vertex, fragment;
			int success;
			char info_log[512];

			// vertex shader
			vertex = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertex, 1, &vshadercode, NULL);
			glCompileShader(vertex);
			compile(vertex, "VERTEX");

			// fragment Shader
			fragment = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragment, 1, &fshadercode, NULL);
			glCompileShader(fragment);
			compile(fragment, "FRAGMENT");

			// shader Program
			id = glCreateProgram();
			glAttachShader(id, vertex);
			glAttachShader(id, fragment);
			glLinkProgram(id);
			compile(id, "PROGRAM");

			// delete the shaders as they're linked into our program now and no longer necessary
			glDeleteShader(vertex);
			glDeleteShader(fragment);

		}

		void use()
		{
			glUseProgram(id);
		}

		void set_bool(std::string &name, bool val)
		{
			glUniform1i(glGetUniformLocation(id, name.c_str()), (int) val);
		}

		void set_int(std::string &name, int val)
		{
			glUniform1i(glGetUniformLocation(id, name.c_str()), val);
		}

		void set_float(std::string &name, float val)
		{
			glUniform1i(glGetUniformLocation(id, name.c_str()), val);
		}

		GLint get_int(char *name)
		{
			return glGetAttribLocation(id, name);
		}

		void set_vec4(std::string &name, glm::vec4 &vec) const
		{
			glUniform4f(glGetUniformLocation(id, name.c_str()), vec.x, vec.y, vec.z, vec.a);
		}

		void set_vec3(std::string &name, glm::vec3 &vec) const
		{
			glUniform3f(glGetUniformLocation(id, name.c_str()), vec.x, vec.y, vec.z);
		}

		void set_vec2(std::string &name, glm::vec3 &vec) const
		{
			glUniform2f(glGetUniformLocation(id, name.c_str()), vec.x, vec.y);
		}

		void set_mat2(std::string &name, glm::mat2 &mat) const
		{
		   glUniformMatrix2fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
		}
		// ------------------------------------------------------------------------
		void set_mat3(std::string &name, glm::mat3 &mat) const
		{
		   glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
		}
		// ------------------------------------------------------------------------
		void set_mat4(std::string &name, glm::mat4 &mat) const
		{
		   glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
		}

		void set_uniform(std::string &name, int n)
		{
			glUniform1i(glGetUniformLocation(id, name.c_str()), n);
		}

	private:
		void compile(int shader_id, std::string shader_type)
		{
			int success;
			char log[1024];

			if (shader_type != "PROGRAM")
			{
				glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
				if (!success)
				{
					glGetShaderInfoLog(shader_id, 1024, NULL, log);
					std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << shader_type << "\n" << log << "\n -- --------------------------------------------------- -- " << std::endl;
				}
			}

			else
			{
				glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
				if (!success)
				{
					glGetProgramInfoLog(shader_id, 1024, NULL, log);
					std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << shader_type << "\n" << log << "\n -- --------------------------------------------------- -- " << std::endl;
				}
			}
		}
};

#endif
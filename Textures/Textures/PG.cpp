#include "PG.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

PG::PG()
{
	
	CreateDirectory("Info/", nullptr);

	GLInitWindow();
	
	ShaderFiles();

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST); // enables the depth buffer
}
void PG::Terminate()
{
	glDeleteProgram(m_programID);

	glDeleteVertexArrays(1, &m_planeVAO);
	glDeleteBuffers(1, &m_planeVBO);
	glDeleteBuffers(1, &m_planeIBO);

	glfwDestroyWindow(window);
	glfwTerminate();
}


bool PG::create()
{
	int dims = 25;

	float *perlin_data = Perlin(25);

	int imageWidth = dims, imageHeight = dims, imageFormat = 0;

	//perlin
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R32F, imageWidth, imageHeight, 0, GL_RED, GL_FLOAT, perlin_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	//stbi_image_free(perlin_data);

	//rocks
	unsigned char* data = stbi_load("./textures/rocky_ground.tga", &imageWidth, &imageHeight, &imageFormat, STBI_default);

	glGenTextures(1, &m_rocks);
	glBindTexture(GL_TEXTURE_2D, m_rocks);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	stbi_image_free(data);

	//grass
	data = stbi_load("./textures/dirt_grass.tga", &imageWidth, &imageHeight, &imageFormat, STBI_default);
	glGenTextures(1, &m_grass);
	glBindTexture(GL_TEXTURE_2D, m_grass);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	stbi_image_free(data);

	//gravel
	data = stbi_load("./textures/gravel.tga", &imageWidth, &imageHeight, &imageFormat, STBI_default);
	glGenTextures(1, &m_gravel);
	glBindTexture(GL_TEXTURE_2D, m_gravel);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	stbi_image_free(data);

	PlaneBuffers(dims, dims);
	CreateShaders();
	


	return true;
}
bool PG::GLInitWindow()
{
	glfwInit();

	window = glfwCreateWindow(1080, 720, "Textures", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	myCamera = new FlyCamera;

	myCamera->setLookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	myCamera->setPerspective(glm::pi<float>() * 0.35f, 16 / 9.f, 0.1f, 1000.f);

	m_projectionViewMatrix = myCamera->getProjection() * myCamera->getView();

	return true;
}

bool PG::update()
{
	float currentFrame = glfwGetTime();

	m_time = currentFrame - m_lastFrame;
	m_lastFrame = currentFrame;

	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		myCamera->update(m_time * 10.f);
		m_projectionViewMatrix = myCamera->getProjectionView();
		return true;
	}
	return false;
}

void PG::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(m_programID);
	
	m_projectionViewUniform = glGetUniformLocation(m_programID, "projectionViewWorldMatrix");

	DrawPlane();

	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool PG::CreateShaders()
{
	//Store the returned string into a variable
	std::string vertex = ReadFile("vertshader.txt");

	//Convert to const char* so it can be used in the glShaderSourceFunction
	const char* vsSource = vertex.c_str();

	//Store the returned string into a variable
	std::string fragment = ReadFile("fragshader.txt");

	//Convert to const char* so it can be used in the glShaderSourceFunction
	const char* fsSource = fragment.c_str();

	//Compiles the shader..
	int success = GL_FALSE;
	m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(m_vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(m_vertexShader);
	glShaderSource(m_fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(m_fragmentShader);
	//..

	m_programID = glCreateProgram();
	glAttachShader(m_programID, m_vertexShader);
	glAttachShader(m_programID, m_fragmentShader);
	glLinkProgram(m_programID);

	glDeleteShader(m_vertexShader);
	glDeleteShader(m_fragmentShader);

	// check that it compiled and linked correctly
	glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
	if (success == GL_FALSE) {
		int infoLogLength = 0;
		glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* infoLog = new char[infoLogLength];
		glGetProgramInfoLog(m_programID, infoLogLength, nullptr, infoLog);
		printf("Error: Failed to link shader program!\n");
		printf("%s\n", infoLog);
		delete[] infoLog;
		return false;
	}

	return true;
}
bool PG::PlaneBuffers(const int& width, const int& height)
{
	Vertex* vertices = new Vertex[width * height];
	for (int r = 0; r < width; ++r)
	{
		for(int c = 0; c < height; ++c)
		{
			vertices[r * height + c].position = vec4(c - height * 0.5f, 0, r - width * 0.5f, 1);

			vertices[r * height + c].UV = vec2(c * (1.f / height), r * (1.f / width));
		}
	}
	m_indexCount = (width - 1) * (height - 1) * 6;

	unsigned int* indices = new unsigned int(m_indexCount);

	unsigned int index = 0;
	for (int r = 0; r < (width -1); ++r)
	{
		for (int c = 0; c < (height - 1); ++c)
		{
			indices[index++] = r * height + c;
			indices[index++] = (r + 1) * height + c;
			indices[index++] = (r + 1) * height + (c + 1);

			indices[index++] = r * height + c;
			indices[index++] = (r + 1) * height + (c + 1);
			indices[index++] = r * height + (c + 1);
		}

	}

	glGenBuffers(1, &m_planeVBO);
	glGenBuffers(1, &m_planeIBO);

	glGenVertexArrays(1, &m_planeVAO);

	glBindVertexArray(m_planeVAO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_planeIBO);

	glBufferData(GL_ARRAY_BUFFER, (width * height) * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	//position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

	//color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(vec4));

	return true;

}

bool PG::ShaderFiles()
{
	//Create default vertShader incase user doesnt have a file to read from at first
	const char* vertShader = "#version 410\n \
							layout(location=0) in vec4 position; \
							layout(location=1) in vec4 colour; \
							out vec4 vColour; \
							uniform mat4 projectionViewWorldMatrix; \
							void main() {vColour = colour; gl_Position = projectionViewWorldMatrix * position; }";

	//Create default fragShader incase user doesnt have a file to read from at first
	const char* fragShader = "#version 410\n \
							in vec4 vColour; \
							out vec4 fragColor; \
							void main() { fragColor = vColour; }";

	//Create these files
	std::ofstream vertfile("Info/vdefault.txt");
	std::ofstream fragfile("Info/fdefault.txt");

	//Vert shader
	if (vertfile.fail())
	{
		std::cout << "Failed to open\n";
	}
	else
	{
		vertfile << vertShader;
	}

	//Frag shader
	if (fragfile.fail())
	{
		std::cout << "File failed to open!\n";
	}
	else
	{
		fragfile << fragShader;
	}

	return true;
}
std::string PG::ReadFile(const std::string &a_File)
{
	std::string data;
	std::string components;

	std::ifstream file("Info/" + a_File);

	if (file.fail())
	{
		std::cout << "Failed to open file!\n";
	}
	else
	{
		//Read from file here
		while (getline(file, data))
		{//This will not work correctly without the \n added!
		 //getline() grabs everything up to the endline so adding the endline will allow it to be read
			components += data + "\n";
		}
	}
	//Return the data
	return components;

}
void PG::DrawPlane()
{
	glUniformMatrix4fv(m_projectionViewUniform, 1, false, glm::value_ptr(m_projectionViewMatrix));

	//texture slots
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_rocks);

	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, m_grass);

	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, m_gravel);

	//shows the location
	m_projectionViewUniform = glGetUniformLocation(m_programID, "perlin_texture");
	glUniform1i(m_projectionViewUniform, 0);

	m_projectionViewUniform = glGetUniformLocation(m_programID, "rocks");
	glUniform1i(m_projectionViewUniform, 1);

	m_projectionViewUniform = glGetUniformLocation(m_programID, "grass");
	glUniform1i(m_projectionViewUniform, 2);

	m_projectionViewUniform = glGetUniformLocation(m_programID, "gravel");
	glUniform1i(m_projectionViewUniform, 3);

	glBindVertexArray(m_planeVAO);
	glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}
float* PG::Perlin(const int& dims)
{
	float *perlin_data = new float(dims * dims);
	float scale = (1.0f / dims) * 3;
	int octaves = 6;

	for(int x = 0; x < dims; ++x)
	{
		for(int y = 0; y < dims; ++y)
		{
			float amplitude = 1.f;
			float persistence = 0.3f;
			perlin_data[y * dims + x] = 0;
			for (int o = 0; o < octaves; ++o)
			{
				float freq = powf(2, (float)o);
				float perlin_sample =
					glm::perlin(vec2((float)x, (float)y) * scale * freq) * 0.5f + 0.5f;
				perlin_data[y * dims + x] += perlin_sample * amplitude;
				amplitude += persistence;
			}
		}
	}
	return perlin_data;
}





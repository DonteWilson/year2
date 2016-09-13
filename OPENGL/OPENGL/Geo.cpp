#include "Geo.h"

//Finding Verts for the circle.
std::vector<glm::vec4>CV(int np, float radius)
{
	//number of points
	std::vector<glm::vec4> numpts;
	for (int i = 0; i < np; i++)
	{
		float theta = glm::pi<float>() * (float)i / (float)(np - 1);
		//current X and Y
		float curX = radius * sin(theta);
		float curY = radius * cos(theta);

		//brings it  back to the start o
		numpts.push_back(vec4(curX, curY, 0.f, 1));

	}

	//returns the number of points 
	return numpts;
}
//Generates indices 
std::vector<unsigned int>GI(int nm, int np)
{
	std::vector<unsigned int> indices;
	for (unsigned int i = 0; i < nm; i++) //nm = 4
	{
		unsigned int start = i * np;
		for (int j = 0; j < np; j++) //np = 3
		{
			unsigned int botR = (start + np + j);
			unsigned int botL = (start + j);
			indices.push_back(botL);
			indices.push_back(botR);
		}

		indices.push_back(0xFFFF);
	}
	//returns the indices
	return indices;
}
//Rotating points
std::vector<glm::vec4>RP(std::vector<glm::vec4> &begin, int nm)
{
	std::vector<glm::vec4> vertices;

	for(int i = 0; i <= nm; i++)
	{
		float phi = 2 * glm::pi<float>() * float(i) / float(nm);
		for (int j = 0; j < begin.size(); j++)
		{
			//sets the current  x y and z values.
			float curX = begin[j].x * cos(phi) + begin[j].z * sin(phi);
			float curY = begin[j].y;
			float curZ = begin[j].z * cos(phi) - begin[j].x * sin(phi);

			//push back the verts
			vertices.push_back(vec4(curX, curY, curZ, 1.f));
		}
	}

	return vertices;
}

Geo::Geo()
{
	CreateDirectory("Info/", nullptr);

	Shaderfiles();
	//Initialize glfw
	glfwInit();

	//Get current time
	float time = (float)glfwGetTime();
	// create a basic window
	window = glfwCreateWindow(1080, 720, "Rendering Geometry", nullptr, nullptr);

	//Check if window is equal to null
	if (window == nullptr)
	{//Terminate if it is
		glfwTerminate();
	}

	//Make the current window the window object
	glfwMakeContextCurrent(window);

	//Check if loaded correctly
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	//Create the view matrix
	glm::mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.35f,
		16 / 9.f, 0.1f, 1000.f);
	//Set matrix
	m_projectionViewMatrix = projection * view;

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST); // enables the depth buffer
}
void Geo::Terminate()
{
	glDeleteProgram(m_programID);
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
	glDeleteBuffers(1, &m_IBO);

	glfwDestroyWindow(window);
	glfwTerminate();
}


bool Geo::create()
{
	unsigned int Points = 15;
	unsigned int Meridians = 15;

	std::vector<vec4> halfCircle = CV(Points, 5.f);
	//Puts the buffers onto the screen
	CreateBuffers();
	//GetShaders
	GetShaders();

	return true;
}
bool Geo::update()
{
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		return true;
	}
	return false;
}

void Geo::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_time = glfwGetTime();
	// bind shader
	glUseProgram(m_programID);

	// where to send the matrix
	m_projectionViewUniform = glGetUniformLocation(m_programID, "projectionViewWorldMatrix");

	GLint loc = glGetUniformLocation(m_programID, "Time");

	glBindVertexArray(m_VAO);

	//Circle
glDrawElements(GL_TRIANGLE_STRIP, )

	//Plane
	//DrawPlane(8,8);

	//Cube
	//DrawCube(8,8);

	


	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//This updates the monitors display but swapping the rendered back buffer.If we did not call this then we wouldn’t be able to see
	//anything rendered by us with OpenGL.
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Geo::CreateBuffers()
{
	
	//OPENGL DATA

	//Create buffers
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IBO);

	//Generate Array Object
	glGenVertexArrays(1, &m_VAO);

	glBindVertexArray(m_VAO);

	//vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	//indexes
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);

	//pos
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

	//color
	glEnableVertexAttribArray(10);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

	return true;
	
}
bool Geo::GetShaders()
{
	//Store the returned string into a variable
	std::string vertex = ReadFile("vertshader.txt");

	//Convert to const char* so it can be used in the glShaderSourceFunction
	const char* vsSource = vertex.c_str();

	//Store the returned string into a variable
	std::string fragment = ReadFile("fshader.txt");

	//Convert to const char* so it can be used in the glShaderSourceFunction
	const char* fsSource = fragment.c_str();

	//Compiles the shader..
	int success = GL_FALSE;
	m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(m_vertexShader, 1, (const char**)&vsSource, nullptr);
	glCompileShader(m_vertexShader);
	glShaderSource(m_fragmentShader, 1, (const char**)&fsSource, nullptr);
	glCompileShader(m_fragmentShader);
	//..

	m_programID = glCreateProgram();
	glAttachShader(m_programID, m_vertexShader);
	glAttachShader(m_programID, m_fragmentShader);
	glLinkProgram(m_programID);

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

	// we don't need to keep the individual shaders around
	glDeleteShader(m_fragmentShader);
	glDeleteShader(m_vertexShader);

	return true;
}
bool Geo::Shaderfiles()
{
	//Create default vertShader incase user doesnt have a file to read from at first
	const char* vsSource = "#version 410\n \
							layout(location=0) in vec4 position; \
							layout(location=1) in vec4 colour; \
							out vec4 vColour; \
							uniform mat4 projectionViewWorldMatrix; \
							void main() {vColour = colour; gl_Position = projectionViewWorldMatrix * position; }";

	//Create default fragShader incase user doesnt have a file to read from at first
	const char* fsSource = "#version 410\n \
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
		vertfile << vsSource;
	}

	//Frag shader
	if (fragfile.fail())
	{
		std::cout << "File failed to open!\n";
	}
	else
	{
		fragfile << fsSource;
	}

	return true;
}
std::string Geo::ReadFile(const std::string &a_File)
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


void Geo::DrawCube(const int &width, const int &height)
{
	const unsigned int top = width;

	// create vertex and index data
	Vertex vertices[8];
	unsigned int indices[13] = { 0,1,2,3,4,5,1,6,0,7,2,4,6 };

	//Set the positions
	vertices[0].position = vec4(-width, 0, -height, 1);
	vertices[1].position = vec4(width, 0, -height, 1);
	vertices[2].position = vec4(-width, 0, height, 1);
	vertices[3].position = vec4(width, 0, height, 1);
	vertices[4].position = vec4(-width, top, height, 1);
	vertices[5].position = vec4(width, top, height, 1);
	vertices[6].position = vec4(width, top, -height, 1);
	vertices[7].position = vec4(-width, top, -height, 1);

	//Set the buffer data for the vertices
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(Vertex),
		vertices, GL_STATIC_DRAW);

	//Set the buffer data for the indices
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 13 *
		sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glUniformMatrix4fv(m_projectionViewUniform, 1, false, glm::value_ptr(m_projectionViewMatrix * glm::translate(vec3(-25, 0, 0))));
	glDrawElements(GL_TRIANGLE_STRIP, 13, GL_UNSIGNED_INT, nullptr);
}
void Geo::DrawCircle(const int &radius, bool isFilled)
{
	// create vertex and index data for circle
	Vertex vertices[24];
	unsigned int indices[24] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };

	//Loop through the number of indices
	for (int i = 0; i <= 23; i++)
	{//Angle between each index
		double angle = i * (2 * 3.14159 / 22);
		//get the cos of the angle and multiply by the radius
		double X = cos(angle) * radius;
		//get the sin of the angle and multiply by the radius
		double Z = sin(angle) * radius;
		//Set the appropriate values per vertex
		vertices[i].position = vec4(X, 0, Z, 1);
	}

	//Set the buffer data for the vertices
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(Vertex),
		vertices, GL_STATIC_DRAW);

	//Set the buffer data for the indices
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 24 *
		sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glUniformMatrix4fv(m_projectionViewUniform, 1, false, glm::value_ptr(m_projectionViewMatrix));

	//If false, then dont fill circle
	if (!isFilled)
		glDrawElements(GL_TRIANGLE_STRIP, 24, GL_UNSIGNED_INT, nullptr);
	else //Triangle fan fills in the circle
		glDrawElements(GL_TRIANGLE_FAN, 24, GL_UNSIGNED_INT, nullptr);
}
void Geo::DrawPlane(const int &width, const int &height)
{
	// create vertex and index data
	Vertex vertices[4];
	unsigned int indices[4] = { 0,1,2,3 };

	//Set the positions
	vertices[0].position = vec4(-width, 0, -height, 1);
	vertices[1].position = vec4(width, 0, -height, 1);
	vertices[2].position = vec4(-width, 0, height, 1);
	vertices[3].position = vec4(width, 0, height, 1);

	vertices[0].colour = vec4(1, 0, 0, 1);
	vertices[1].colour = vec4(0, 1, 0, 1);
	vertices[2].colour = vec4(0, 0, 1, 1);
	vertices[3].colour = vec4(1, 0, 0, 1);

	//Set the buffer data for the vertices
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex),
		vertices, GL_STATIC_DRAW);

	//Set the buffer data for the indices
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 *
		sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glUniformMatrix4fv(m_projectionViewUniform, 1, false, glm::value_ptr(m_projectionViewMatrix * glm::translate(vec3(5, 2, -5))));
	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, nullptr);
}
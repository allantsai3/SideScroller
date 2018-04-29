#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <string>

class Graphics {
public:
	static unsigned int CompileShader(unsigned int type, const std::string& source);
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
private:
};

#endif //GRAPHICS_H
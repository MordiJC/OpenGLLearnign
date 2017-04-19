TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
	src/main.cpp \
    src/Core/Exception.cpp \
    src/OpenGL/GLShader.cpp \
	src/OpenGL/impl/GLShader_Impl.cpp \
    src/OpenGL/GLShaderProgram.cpp \
	#src/Core/Url.cpp \
	#src/Core/impl/Url_Impl.cpp

LIBS += -lGL -lGLEW -lglfw -lnetwork-uri
INCLUDEPATH += include

HEADERS += \
    include/Core/Exception.hpp \
    include/OpenGL/GLShader.hpp \
	include/OpenGL/impl/GLShader_Impl.hpp \
    include/spimpl.h \
    include/OpenGL/GLException.hpp \
    include/OpenGL/GLShaderProgram.hpp \
	#include/Core/Url.hpp \
	#include/Core/impl/Url_Impl.hpp

DISTFILES += \
    shaders/vertex.vsh \
    shaders/fragment.fsh

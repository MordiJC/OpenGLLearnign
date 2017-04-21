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
    src/Window/Window.cpp \
    src/Window/VideoMode.cpp \
    src/Window/impl/VideoMode_Impl.cpp

# Linking directories
LIBS += -L/usr/local/lib/

# Libs to link
LIBS += -lGL -lGLEW -lnetwork-uri -lglfw

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
    include/Window/Window.hpp \
    include/Window/WindowException.hpp \
    include/Window/VideoMode.hpp \
    include/Window/impl/VideoMode_Impl.hpp

DISTFILES += \
    shaders/vertex.vsh \
    shaders/fragment.fsh

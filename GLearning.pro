TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
	src/main.cpp \
    src/Core/Exception.cpp \
    src/OpenGL/GLShader.cpp \
    src/OpenGL/GLShader_Impl.cpp

LIBS += -lGL -lGLEW -lglfw
INCLUDEPATH += include

HEADERS += \
    include/Core/Exception.hpp \
    include/OpenGL/GLShader.hpp \
    include/OpenGL/GLShader_Impl.hpp

DISTFILES += \
    shaders/vertex.vsh \
    shaders/fragment.fsh

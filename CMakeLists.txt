cmake_minimum_required(VERSION 3.19)
project(Proyecto2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto2 main.cpp Paciente.cpp Paciente.h Enfermedad.cpp Enfermedad.h Lista.cpp Lista.h Nodo.cpp Nodo.h dist/json/json.h dist/jsoncpp.cpp ContenedoraListas.h ContenedoraListas.cpp MenuAnalisis.h MenuAnalisis.cpp Iterador.h Iterador.cpp IteradorLista.cpp IteradorLista.h)
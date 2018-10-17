#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/smarty/task/Environment.o \
	${OBJECTDIR}/src/smarty/task/Learn.o \
	${OBJECTDIR}/src/smarty/task/Rules.o \
	${OBJECTDIR}/src/smarty/task/State.o \
	${OBJECTDIR}/src/smarty/task/StatePk.o \
	${OBJECTDIR}/src/smarty/task/Task.o \
	${OBJECTDIR}/src/smarty/task/Transition.o \
	${OBJECTDIR}/src/smarty/task/TransitionPk.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lopencv_core

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_task.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_task.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_task.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/smarty/task/Environment.o: src/smarty/task/Environment.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/task
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/task/Environment.o src/smarty/task/Environment.cpp

${OBJECTDIR}/src/smarty/task/Learn.o: src/smarty/task/Learn.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/task
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/task/Learn.o src/smarty/task/Learn.cpp

${OBJECTDIR}/src/smarty/task/Rules.o: src/smarty/task/Rules.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/task
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/task/Rules.o src/smarty/task/Rules.cpp

${OBJECTDIR}/src/smarty/task/State.o: src/smarty/task/State.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/task
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/task/State.o src/smarty/task/State.cpp

${OBJECTDIR}/src/smarty/task/StatePk.o: src/smarty/task/StatePk.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/task
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/task/StatePk.o src/smarty/task/StatePk.cpp

${OBJECTDIR}/src/smarty/task/Task.o: src/smarty/task/Task.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/task
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/task/Task.o src/smarty/task/Task.cpp

${OBJECTDIR}/src/smarty/task/Transition.o: src/smarty/task/Transition.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/task
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/task/Transition.o src/smarty/task/Transition.cpp

${OBJECTDIR}/src/smarty/task/TransitionPk.o: src/smarty/task/TransitionPk.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/task
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/task/TransitionPk.o src/smarty/task/TransitionPk.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_task.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

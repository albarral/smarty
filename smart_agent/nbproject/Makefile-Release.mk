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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/smarty/agent/AgentBehaviour.o \
	${OBJECTDIR}/src/smarty/agent/Analyzer.o \
	${OBJECTDIR}/src/smarty/agent/Aware.o \
	${OBJECTDIR}/src/smarty/agent/core/AgentBus.o \
	${OBJECTDIR}/src/smarty/agent/core/AgentData.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/smarty/agent/AgentBehaviour.o: src/smarty/agent/AgentBehaviour.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/agent
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/agent/AgentBehaviour.o src/smarty/agent/AgentBehaviour.cpp

${OBJECTDIR}/src/smarty/agent/Analyzer.o: src/smarty/agent/Analyzer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/agent
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/agent/Analyzer.o src/smarty/agent/Analyzer.cpp

${OBJECTDIR}/src/smarty/agent/Aware.o: src/smarty/agent/Aware.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/agent
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/agent/Aware.o src/smarty/agent/Aware.cpp

${OBJECTDIR}/src/smarty/agent/core/AgentBus.o: src/smarty/agent/core/AgentBus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/agent/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/agent/core/AgentBus.o src/smarty/agent/core/AgentBus.cpp

${OBJECTDIR}/src/smarty/agent/core/AgentData.o: src/smarty/agent/core/AgentData.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/agent/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/agent/core/AgentData.o src/smarty/agent/core/AgentData.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

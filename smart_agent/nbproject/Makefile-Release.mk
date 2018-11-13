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
	${OBJECTDIR}/src/smart/agent/Agent.o \
	${OBJECTDIR}/src/smart/agent/SmartBehaviour.o \
	${OBJECTDIR}/src/smart/agent/core/SmartBus.o \
	${OBJECTDIR}/src/smart/agent/core/SmartConfig.o \
	${OBJECTDIR}/src/smart/agent/core/SmartData.o \
	${OBJECTDIR}/src/smart/agent/modules/Aware.o


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

${OBJECTDIR}/src/smart/agent/Agent.o: src/smart/agent/Agent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smart/agent
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smart/agent/Agent.o src/smart/agent/Agent.cpp

${OBJECTDIR}/src/smart/agent/SmartBehaviour.o: src/smart/agent/SmartBehaviour.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smart/agent
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smart/agent/SmartBehaviour.o src/smart/agent/SmartBehaviour.cpp

${OBJECTDIR}/src/smart/agent/core/SmartBus.o: src/smart/agent/core/SmartBus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smart/agent/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smart/agent/core/SmartBus.o src/smart/agent/core/SmartBus.cpp

${OBJECTDIR}/src/smart/agent/core/SmartConfig.o: src/smart/agent/core/SmartConfig.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smart/agent/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smart/agent/core/SmartConfig.o src/smart/agent/core/SmartConfig.cpp

${OBJECTDIR}/src/smart/agent/core/SmartData.o: src/smart/agent/core/SmartData.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smart/agent/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smart/agent/core/SmartData.o src/smart/agent/core/SmartData.cpp

${OBJECTDIR}/src/smart/agent/modules/Aware.o: src/smart/agent/modules/Aware.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smart/agent/modules
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smart/agent/modules/Aware.o src/smart/agent/modules/Aware.cpp

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

##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CarFrec
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Gord/Desktop/ab/AlgoritmiaBasica
ProjectPath            :=C:/Users/Gord/Desktop/ab/AlgoritmiaBasica/CarFrec
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Gord
Date                   :=17/03/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="CarFrec.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/pruebasCarFrec.cpp$(ObjectSuffix) $(IntermediateDirectory)/CarFrec.cc$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/pruebasCarFrec.cpp$(ObjectSuffix): pruebasCarFrec.cpp $(IntermediateDirectory)/pruebasCarFrec.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/ab/AlgoritmiaBasica/CarFrec/pruebasCarFrec.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pruebasCarFrec.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pruebasCarFrec.cpp$(DependSuffix): pruebasCarFrec.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pruebasCarFrec.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pruebasCarFrec.cpp$(DependSuffix) -MM pruebasCarFrec.cpp

$(IntermediateDirectory)/pruebasCarFrec.cpp$(PreprocessSuffix): pruebasCarFrec.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pruebasCarFrec.cpp$(PreprocessSuffix) pruebasCarFrec.cpp

$(IntermediateDirectory)/CarFrec.cc$(ObjectSuffix): CarFrec.cc $(IntermediateDirectory)/CarFrec.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/ab/AlgoritmiaBasica/CarFrec/CarFrec.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CarFrec.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CarFrec.cc$(DependSuffix): CarFrec.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CarFrec.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/CarFrec.cc$(DependSuffix) -MM CarFrec.cc

$(IntermediateDirectory)/CarFrec.cc$(PreprocessSuffix): CarFrec.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CarFrec.cc$(PreprocessSuffix) CarFrec.cc


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



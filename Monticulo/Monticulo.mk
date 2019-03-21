##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Monticulo
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Gord/Desktop/ab/AlgoritmiaBasica
ProjectPath            :=C:/Users/Gord/Desktop/ab/AlgoritmiaBasica/Monticulo
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Gord
Date                   :=21/03/2019
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
ObjectsFileList        :="Monticulo.txt"
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
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/pruebas.cpp$(ObjectSuffix) $(IntermediateDirectory)/Cola.cc$(ObjectSuffix) 



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
$(IntermediateDirectory)/pruebas.cpp$(ObjectSuffix): pruebas.cpp $(IntermediateDirectory)/pruebas.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/ab/AlgoritmiaBasica/Monticulo/pruebas.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pruebas.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pruebas.cpp$(DependSuffix): pruebas.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pruebas.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pruebas.cpp$(DependSuffix) -MM pruebas.cpp

$(IntermediateDirectory)/pruebas.cpp$(PreprocessSuffix): pruebas.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pruebas.cpp$(PreprocessSuffix) pruebas.cpp

$(IntermediateDirectory)/Cola.cc$(ObjectSuffix): Cola.cc $(IntermediateDirectory)/Cola.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/ab/AlgoritmiaBasica/Monticulo/Cola.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cola.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Cola.cc$(DependSuffix): Cola.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Cola.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/Cola.cc$(DependSuffix) -MM Cola.cc

$(IntermediateDirectory)/Cola.cc$(PreprocessSuffix): Cola.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Cola.cc$(PreprocessSuffix) Cola.cc


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



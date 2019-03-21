##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ArbolTrie
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Gord/Desktop/ab/AlgoritmiaBasica
ProjectPath            :=C:/Users/Gord/Desktop/ab/AlgoritmiaBasica/ArbolTrie
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
ObjectsFileList        :="ArbolTrie.txt"
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
Objects0=$(IntermediateDirectory)/pruebasArboles.cpp$(ObjectSuffix) $(IntermediateDirectory)/ArbolTrie.cc$(ObjectSuffix) 



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
$(IntermediateDirectory)/pruebasArboles.cpp$(ObjectSuffix): pruebasArboles.cpp $(IntermediateDirectory)/pruebasArboles.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/ab/AlgoritmiaBasica/ArbolTrie/pruebasArboles.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pruebasArboles.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pruebasArboles.cpp$(DependSuffix): pruebasArboles.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pruebasArboles.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pruebasArboles.cpp$(DependSuffix) -MM pruebasArboles.cpp

$(IntermediateDirectory)/pruebasArboles.cpp$(PreprocessSuffix): pruebasArboles.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pruebasArboles.cpp$(PreprocessSuffix) pruebasArboles.cpp

$(IntermediateDirectory)/ArbolTrie.cc$(ObjectSuffix): ArbolTrie.cc $(IntermediateDirectory)/ArbolTrie.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/ab/AlgoritmiaBasica/ArbolTrie/ArbolTrie.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ArbolTrie.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ArbolTrie.cc$(DependSuffix): ArbolTrie.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ArbolTrie.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/ArbolTrie.cc$(DependSuffix) -MM ArbolTrie.cc

$(IntermediateDirectory)/ArbolTrie.cc$(PreprocessSuffix): ArbolTrie.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ArbolTrie.cc$(PreprocessSuffix) ArbolTrie.cc


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DesignPrinciple/DependencyInversionPrinciple.cpp \
../src/DesignPrinciple/InterfaceSegregationDiscipline.cpp \
../src/DesignPrinciple/LiskoSubstitutionPrinciple.cpp \
../src/DesignPrinciple/OpenClosedPrinciple.cpp \
../src/DesignPrinciple/SingleResponsibilityPrinciple.cpp 

OBJS += \
./src/DesignPrinciple/DependencyInversionPrinciple.o \
./src/DesignPrinciple/InterfaceSegregationDiscipline.o \
./src/DesignPrinciple/LiskoSubstitutionPrinciple.o \
./src/DesignPrinciple/OpenClosedPrinciple.o \
./src/DesignPrinciple/SingleResponsibilityPrinciple.o 

CPP_DEPS += \
./src/DesignPrinciple/DependencyInversionPrinciple.d \
./src/DesignPrinciple/InterfaceSegregationDiscipline.d \
./src/DesignPrinciple/LiskoSubstitutionPrinciple.d \
./src/DesignPrinciple/OpenClosedPrinciple.d \
./src/DesignPrinciple/SingleResponsibilityPrinciple.d 


# Each subdirectory must supply rules for building sources it contributes
src/DesignPrinciple/%.o: ../src/DesignPrinciple/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



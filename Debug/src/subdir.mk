################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DependencyInversionPrinciple.cpp \
../src/InterfaceSegregationDiscipline.cpp \
../src/LiskoSubstitutionPrinciple.cpp \
../src/OpenClosedPrinciple.cpp \
../src/SingleResponsibilityPrinciple.cpp 

OBJS += \
./src/DependencyInversionPrinciple.o \
./src/InterfaceSegregationDiscipline.o \
./src/LiskoSubstitutionPrinciple.o \
./src/OpenClosedPrinciple.o \
./src/SingleResponsibilityPrinciple.o 

CPP_DEPS += \
./src/DependencyInversionPrinciple.d \
./src/InterfaceSegregationDiscipline.d \
./src/LiskoSubstitutionPrinciple.d \
./src/OpenClosedPrinciple.d \
./src/SingleResponsibilityPrinciple.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


